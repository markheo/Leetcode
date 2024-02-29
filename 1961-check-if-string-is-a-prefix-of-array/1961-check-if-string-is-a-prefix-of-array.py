class Solution:
    def isPrefixString(self, s: str, words: List[str]) -> bool:
        prefix = ""
    
        # Iterate through each word in the words array
        for word in words:
            # Concatenate the current word to the prefix
            prefix += word
            # Check if the current prefix matches the string s
            if prefix == s:
                return True
            # If the length of the prefix exceeds s, no need to continue
            if len(prefix) > len(s):
                break

        # If the loop completes without finding a match, return False
        return False