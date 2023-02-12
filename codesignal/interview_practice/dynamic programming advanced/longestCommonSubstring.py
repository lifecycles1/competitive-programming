
# Given two strings, s and t, find the length of their longest common substring.


# Python solution 1 - dynamic programming . slower than solution 2

# This algorithm uses a 2D array dp, where dp[i][j] stores the length of the longest common substring 
# ending at index i in s and index j in t. The time complexity of this algorithm is O(mn) and the space 
# complexity is O(mn)
def solution(s, t):
    m, n = len(s), len(t)
    # Initialize a 2D array dp with the size (m+1) x (n+1) filled with 0
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    ans = 0
    for i in range(m):
        for j in range(n):
            # if the characters at index i in s and index j in t are the same 
            if s[i] == t[j]:
                # update dp[i][j] with the length of the longest common substring ending at index i-1 in s and index j-1 in t + 1 
                dp[i][j] = dp[i - 1][j - 1] + 1
                # update the ans with the max between the previous ans and the current dp[i][j]
                ans = max(ans, dp[i][j])
            else:
                #if the characters at index i and j are different, leave dp[i][j] as 0
                dp[i][j] = 0
    # return ans which holds the length of the longest common substring
    return ans



# a Python2 solution 2 - rolling hash technique combined with binary search 

# This is a robust implementation of the rolling hash technique, which uses a different approach to handle 
# collisions. It uses a function called "hashes" to calculate the hash value of the substrings of the two 
# input strings, and the function "find" to compare the hashed values of the substrings. The function 
# "find" uses a dictionary to store the hash values of the substrings of the first string, and checks if 
# the hash value of a substring of the second string is present in the dictionary, and if it is, it 
# compares the substring of the first string with the substring of the second string to check if they are 
# the same.

# It also uses a binary search approach to find the length of the longest common substring, and uses a 
# variable called MOD which is a prime number, P and Pinv which are used as part of the hash function to 
# ensure that the hash values are unique.

def solution(s, t):
    
    limit = 500000000023
    prime_base = 101
    
    # Append dummy element in front so we can ignore first hash.
    # It makes the loops cleaner and adds insignificant computation.
    s = [0] + [ord(i) - 31 for i in s]
    t = [0] + [ord(i) - 31 for i in t]
    
    # Build global list of powers of base and initial hashes of s and t so they
    # don't need to be recomputed for each hasSubstringOfLength call.
    powers_of_base = [1]
    s_init_hashes = [0]
    t_init_hashes = [0]
    
    def hasSubstringOfLength(n):
        """Return True if a substring of s with length n also appears in t.
        Uses a rolling hash to compute unique (with high probability) hashes for each
        substring of s with length n, then does the same for t, stopping if any hash
        from t was seen in s.
        """
        # Extend global lists as needed
        for i in range(len(powers_of_base), n):
            powers_of_base.append(powers_of_base[-1] * prime_base % limit)
            s_init_hashes.append((s_init_hashes[-1] * prime_base + s[i]) % limit)
            t_init_hashes.append((t_init_hashes[-1] * prime_base + t[i]) % limit)

        s_hashes = []  # set()
        
        # Initial s hash
        cur_hash = s_init_hashes[n - 1]
        # The rest of the s hashes
        for i in range(n, len(s)):
            cur_hash = ((cur_hash - s[i - n] * powers_of_base[n - 1]) * prime_base + s[i]) % limit
            s_hashes.append(cur_hash) # add(cur_hash)
        s_hashes = set(s_hashes)

        # Initial t hash
        cur_hash = t_init_hashes[n - 1]
        # The rest of the t hashes
        for i in range(n, len(t)):
            cur_hash = ((cur_hash - t[i - n] * powers_of_base[n - 1]) * prime_base + t[i]) % limit
            if cur_hash in s_hashes:
                return True

        return False
    
    # Binary search for length of longest substring
    lo, hi = 0, min(len(s), len(t))
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if hasSubstringOfLength(mid):
            lo = mid
        else:
            hi = mid - 1
            
    return lo




