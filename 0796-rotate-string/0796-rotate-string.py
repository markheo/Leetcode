class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        n = len(s)
        comb = set()
        for idx in range(n+1):
            a,b = s[:idx], s[idx:]
            comb.add(b+a)
        if goal in comb:
            return True
        return False