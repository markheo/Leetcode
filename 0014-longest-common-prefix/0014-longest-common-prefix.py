class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        min_str = len(min(strs, key=len))
        str_lst = [list(s) for s in strs]
        ans = ""
        for i in range(min_str):
            c = set([lst[i] for lst in str_lst])
            if i==0 and len(c) > 1:
                return ""
                break
            if len(c)==1:
                ans += str_lst[0][i]
            if i>0 and len(c)>1:
                break    
        return "".join(ans)
            