class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        def count_unique_chars_between_indexes(s, start, end):
            """주어진 인덱스 사이의 유니크한 문자 수를 계산합니다."""
            return len(set(s[start+1:end]))
        first_index = [-1] * 26
        last_index = [-1] * 26

        # 각 문자에 대해 첫 등장 위치와 마지막 등장 위치를 기록합니다.
        for i, char in enumerate(s):
            index = ord(char) - ord('a')
            if first_index[index] == -1:
                first_index[index] = i
            last_index[index] = i

        count = 0
        # 각 문자를 중심으로 가능한 팰린드롬 서브시퀀스 수를 계산합니다.
        for i in range(26):
            if first_index[i] != -1 and last_index[i] != -1 and first_index[i] != last_index[i]:
                count += count_unique_chars_between_indexes(s, first_index[i], last_index[i])

        return count