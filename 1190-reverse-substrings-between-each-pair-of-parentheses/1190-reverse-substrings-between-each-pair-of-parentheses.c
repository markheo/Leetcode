void reverseString(char *str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char* reverseParentheses(char* s) {
    int n = strlen(s), top = -1;
    int *stack = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else if (s[i] == ')') {
            if (top != -1) {
                int start = stack[top--] + 1; // 여는 괄호 다음 위치
                int end = i - 1; // 닫는 괄호 이전 위치
                reverseString(s, start, end);
            }
        }
    }

    // 결과 문자열 생성
    char *result = (char*)malloc((n + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != '(' && s[i] != ')') {
            result[j++] = s[i];
        }
    }
    result[j] = '\0'; // 문자열 종료

    free(stack); // 메모리 해제
    return result;
}