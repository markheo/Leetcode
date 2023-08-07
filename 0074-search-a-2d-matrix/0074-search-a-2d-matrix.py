class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])
        if m == 1:
            tRow = matrix[0]
        else:
            for r in range(m-1):
                if target < matrix[r+1][0]:
                    tRow = matrix[r]
                    break
                if r == m-2 and target > matrix[r][0]:
                    tRow = matrix[-1]
        if n == 1:
            if tRow[0] == target:
                return True
            return False
        elif n == 2:
            if tRow[0] == target or tRow[1] == target:
                return True
            return False
        else:
            start, end = 0, n-1
            while start < end:
                mid = start + (end - start) // 2
                # print("start: ", start, ", end: ", end, ", mid: ", mid)
                if tRow[mid] > target:
                    end = mid - 1
                    # print("start: ", start, ", end: ", end)
                elif tRow[mid] < target:
                    start = mid + 1
                    # print("start: ", start, ", end: ", end)
                else:
                    return True

            if tRow[start] == target:
                return True
            return False
