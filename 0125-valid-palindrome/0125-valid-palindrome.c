void toLowerCase_SW(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}

// 주어진 char 문자가 알파벳(대소문자 불문)이거나 숫자(0-9)인지 여부를 판단하는 함수(bool이 아닌 int 주의 0 or not)
int isalnum_SW(int c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// 알파벳, 숫자를 제외한 space, comma, colon 등을 제거해주는 함수
void remove_non_alphanumeric_SW(char *str) {
    int src = 0, dst = 0;
    while (str[src]) {
        if (isalnum_SW((unsigned char)str[src])) {
            str[dst++] = str[src];
        }
        src++;
    }
    str[dst] = '\0';
}

bool isPalindrome(char* s) {
    if (!s[0]) {
        return false;
    }
    
    toLowerCase_SW(s);
    remove_non_alphanumeric_SW(s);
       
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) {
            return false;
        }
    }

    return true;
}