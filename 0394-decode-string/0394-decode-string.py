class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        num = 0
        curString = ''

        for char in s:
            if char.isdigit():
                num = num * 10 + int(char)
            elif char == '[':
                # 숫자와 현재 문자열을 스택에 푸시
                stack.append((num, curString))
                num, curString = 0, ''
            elif char == ']':
                # 스택에서 숫자와 이전 문자열을 팝
                prevNum, prevString = stack.pop()
                curString = prevString + prevNum * curString
            else:
                curString += char

        return curString
        