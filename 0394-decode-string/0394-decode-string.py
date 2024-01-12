class Solution:
    def decodeString(self, s: str) -> str:
        def dfs(index):
            result = ""
            num = 0

            while index < len(s):
                char = s[index]
                if char.isdigit():
                    num = num * 10 + int(char)
                elif char == '[':
                    # 재귀 호출로 대괄호 안의 문자열 처리
                    index, decoded_string = dfs(index + 1)
                    result += num * decoded_string
                    num = 0
                elif char == ']':
                    # 현재 대괄호의 문자열 반환
                    return index, result
                else:
                    result += char
                index += 1

            return result

        return dfs(0)
        