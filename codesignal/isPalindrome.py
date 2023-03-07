def isPalindrome(str):
    return str == "".join(reversed(str))


def isPalindrome(str):
    return str == str[::-1]


def isPalindrome(str):
    for i in range(len(str)//2):
        if str[i] != str[len(str) - i - 1]:
            return False
    return True

def isPalindrome(str):
    if len(str) == 0 or len(str) == 1:
        return True
    if str[0] == str[len(str) - 1]:
        return isPalindrome(str[1:len(str)-1])
    return False