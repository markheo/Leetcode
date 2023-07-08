class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        countT, countF = 0, 0
        ans, cnt = 0, 0
        left, right = 0, 0
        l = len(answerKey)
        while right < l:
            if answerKey[right] == 'T': countT += 1
            else: countF += 1
            cnt = min(countT, countF)

            # 열쇠는 'T'와 'F'의 카운트 차이가 최대 'k' 스왑으로 수정될 수 있는 문자열 내에서 윈도우를 유지한다는 것
            if cnt <= k:
                ans = max(ans, right-left+1)

            # 최대 k 스왑으로 T, F의 카운트 차이를 메꿀 수 없다면 윈도우 크기 조정
            else:
                while cnt > k:
                    # cnt가 k보다 크면 교환할 수 있는 것보다 더 많은 소수 문자가 있음을 의미. 이 경우에는 cnt가 k보다 작거나 같을 때까지 left 포인터를 증가시킴(따라서 창 크기가 줄어듦). 이 과정에서 카운트 countT 및 countF는 창에서 제거되는 문자에 따라 업데이트됨.
                    if answerKey[left] == 'T': countT -= 1
                    else: countF -= 1
                    cnt = min(countT, countF)
                    left += 1
            right += 1     # 오른쪽 포인터가 전체 문자열을 통과할 때까지 계속
        return ans        
        
        
        
#         if 'F' not in answerKey or 'T' not in answerKey:
#             return len(answerKey)
#         else:
#             dct = {}
#             for i in range(len(answerKey)-1):
#                 if answerKey[i] != answerKey[i+1]:
#                     dct[i] = i+1

#             key_lst = list(dct.keys())[::-1]
#             dct[len(answerKey)-1] = len(answerKey) - dct[key_lst[0]]
#             for i in range(len(key_lst)-1):
#                 dct[key_lst[i]] = dct[key_lst[i]] - dct[key_lst[i+1]]

#             key_lst = list(dct.keys())
#             ans = 0
#             if max(list(dct.values())) < k:
#                 return len(answerKey)   
#             for i, key in enumerate(key_lst):
#                 if dct[key] == k:
#                     if 0 < i < len(key_lst)-1:
#                         ans = max(ans, k+dct[key_lst[i-1]]+dct[key_lst[i+1]])
#                     elif i == len(key_lst)-1:
#                         ans = max(ans, dct[key_lst[i-1]]+k)
#                     elif i == 0:
#                         ans = max(ans, dct[key_lst[i+1]]+k)
#             return ans