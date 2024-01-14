class Solution:
    def isPalindrome(self, s: str) -> bool:
        if not s:
            return None
        s = ''.join(char for char in s.lower() if char.isalnum())
        return s == s[::-1]