"""
determine if integer is palindrome
"""

def isPalindrome(x):
    return str(x) == str(x)[::-1]


print(isPalindrome(123))
print(isPalindrome(12321))
print(isPalindrome(123215))
