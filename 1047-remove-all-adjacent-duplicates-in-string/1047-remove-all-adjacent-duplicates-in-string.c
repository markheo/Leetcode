char* removeDuplicates(char* s) {
    int len = strlen(s);
    char* result = (char*)malloc((len + 1) * sizeof(char)); // 스택으로 사용할 메모리 할당
    int top = -1; // 스택의 최상단 위치

    for (int i = 0; i < len; i++) {
        if (top >= 0 && abs(result[top] - s[i]) == 0) { // result[top]은 가장 최근 문자, 인접쌍 확인(abs 써서 앞뒤로)
            top--; // 스택에서 제거
        } else {
            result[++top] = s[i]; // 인접쌍 없으면 스택에 추가
        }
    }
    
    result[top + 1] = '\0'; // 문자열 종료 문자 추가
    return result;
}