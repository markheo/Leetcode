bool isValid(char* s) {
    int n = strlen(s);
    char *stack = (char *)malloc(n + 1); // 스택으로 사용할 메모리 할당
    int top = -1; // 스택의 최상위 인덱스를 나타냄

    for (int i = 0; i < n; i++) {
        char c = s[i];
        // 여는 괄호일 경우 스택에 추가
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else {
            // 닫는 괄호일 경우 스택의 최상위 항목과 비교
            if (top == -1) {
                // 스택이 비어있으면 유효하지 않음
                free(stack);
                return false;
            }
            char topChar = stack[top--]; // 스택에서 하나 제거
            if ((c == ')' && topChar != '(') || 
                (c == '}' && topChar != '{') || 
                (c == ']' && topChar != '[')) {
                // 괄호의 짝이 맞지 않으면 유효하지 않음
                free(stack);
                return false;
            }
        }
    }

    bool result = top == -1; // 스택이 비어있으면 유효함
    free(stack); // 할당된 메모리 해제
    return result;
}