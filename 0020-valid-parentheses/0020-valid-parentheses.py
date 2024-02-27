class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        pairs = {
            '(':')',
            '{':'}',
            '[':']'
        }
        for br in s:
            if br in pairs:
                stack.append(br)
            elif len(stack) == 0 or br != pairs[stack.pop()]:
                return False
        
        return len(stack) == 0