class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expandAroundCenter(left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            return s[left + 1:right]

        if not s:
            return ""

        longest_palindrome = ""
        for i in range(len(s)):
            palindrome1 = expandAroundCenter(i, i)  # Odd length palindrome
            palindrome2 = expandAroundCenter(i, i + 1)  # Even length palindrome
            longest_palindrome = max(longest_palindrome, palindrome1, palindrome2, key=len)

        return longest_palindrome