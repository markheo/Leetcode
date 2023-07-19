class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        # If there are no intervals, return 0
        if not intervals:
            return 0

        # Sort the intervals by end time
        intervals.sort(key=lambda x: x[1])

        # Initialize the end time of the last kept interval to negative infinity
        last_end = float('-inf')

        # Initialize the count of removed intervals to 0
        removed = 0

        for start, end in intervals:
            # If the current interval doesn't overlap with the last kept interval,
            # update the end time of the last kept interval
            if start >= last_end:
                last_end = end
                # print(start, last_end)
            else:
                # Otherwise, remove the current interval
                # print(start, last_end, "remove!")
                removed += 1

        return removed
        
        
        
        
        
        # l = len(intervals)
        # dct = {}
        # start, end = 0, 0
        # for i in range(l):
        #     ans = 0
        #     start, end = intervals[i][0], intervals[i][1]
        #     # print(start, end, "로 시작합니다.")
        #     tmp = intervals[:]
        #     tmp.remove(intervals[i])
        #     for a, b in tmp:
        #         if b <= start or a < start < b:
        #             start = a
        #             # print("renew start: ", start)
        #         elif a >= end or a < end < b:
        #             end = b
        #             # print("renew end: ", end)
        #         else:
        #             # print("overlap happened: ", a, b)
        #             ans += 1
        #     dct[i] = ans
        # # print(dct)
        # return min(dct.values())