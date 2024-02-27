class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        else:
            lst = list(str(x))
            lst2 = [lst[i] for i in range(len(lst)-1, -1, -1)]
            if lst == lst2:
                return True
            return False
        