#define ASCII_SIZE 256  // ASCII 문자에 대한 배열 크기

void remove_string_duplicate_SW(char *s) {
    bool seen[ASCII_SIZE] = {false};
    int src = 0, dst = 0; // 최종 결과의 idx

    while (s[src] != '\0') {
        if (!seen[(unsigned char)s[src]]) {
            seen[(unsigned char)s[src]] = true;
            s[dst++] = s[src];
        }
        src++;
    }
    s[dst] = '\0';  // 문자열의 끝을 표시
}

int minimizedStringLength(char * s){
    remove_string_duplicate_SW(s);
    return strlen(s);
}