char* makeGood(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc((len + 1) * sizeof(char)); // 스택으로 사용할 메모리 할당
    int top = -1; // 스택의 최상단 위치

    for (int i = 0; i < len; i++) {
        if (top >= 0 && abs(stack[top] - s[i]) == 32) { // 대소문자 쌍 확인
            top--; // 스택에서 제거
        } else {
            stack[++top] = s[i]; // 스택에 추가
        }
    }
    
    stack[top + 1] = '\0'; // 문자열 종료 문자 추가
    return stack;
}