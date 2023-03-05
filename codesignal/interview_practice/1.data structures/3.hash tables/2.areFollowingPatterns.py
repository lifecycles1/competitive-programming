# Given an array strings, determine whether it follows the sequence given in the patterns array. 
# In other words, there should be no i and j for which strings[i] = strings[j] 
# and patterns[i] ≠ patterns[j] or for which strings[i] ≠ strings[j] and patterns[i] = patterns[j].

# Example

# For strings = ["cat", "dog", "dog"] and patterns = ["a", "b", "b"], the output should be
# solution(strings, patterns) = true;

# class Solution:
#     def areFollowingPatterns(self, strings, patterns):
#         return len(set(zip(strings, patterns))) == len(set(strings)) == len(set(patterns))
    

class Solution:
    def areFollowingPatterns(self, strings, patterns):
        a = {}
        b = {}
        for i in range(len(strings)):
            if strings[i] not in a:
                a[strings[i]] = i
            if patterns[i] not in b:
                b[patterns[i]] = i
            if a[strings[i]] != b[patterns[i]]:
                return False
        return True