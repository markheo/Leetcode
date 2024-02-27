char* removeStars(char* s) {
    int n = strlen(s); // 입력 문자열의 길이
    char* stack = (char*)malloc((n + 1) * sizeof(char)); // 스택으로 사용할 문자열 메모리 할당
    if (stack == NULL) {
        return NULL; // 메모리 할당 실패 처리
    }

    int top = 0; // 스택의 최상단 위치 (현재 스택에 저장된 문자의 수)
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            if (top > 0) { // 스택이 비어있지 않으면
                top--; // 가장 최근에 삽입된 문자 제거
            }
        } else {
            stack[top++] = s[i]; // '*' 문자가 아니면 스택에 문자 추가
        }
    }
    stack[top] = '\0'; // 최종 문자열을 널 문자로 종료

    return stack; // 수정된 문자열을 가리키는 포인터 반환
}