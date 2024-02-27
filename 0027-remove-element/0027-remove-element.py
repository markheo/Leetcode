class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0  # 결과 리스트의 인덱스
        for j in range(len(nums)):
            if nums[j] != val:
                nums[i] = nums[j]
                i += 1
        return i  # 새로운 리스트의 길이 반환
