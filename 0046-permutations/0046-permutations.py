class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        def permute_help(data, i, length):
            if i == length:
                ans.append(data[:])
            else:
                for j in range(i, length):
                    data[i], data[j] = data[j], data[i]
                    permute_help(data, i+1, length)
                    data[i], data[j] = data[j], data[i]
        permute_help(nums, 0, len(nums))
        return ans
        