char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    
    // 첫 번째 문자열을 기준으로 설정
    char* prefix = (char*)malloc(strlen(strs[0]) + 1);
    strcpy(prefix, strs[0]);
    
    for (int i = 1; i < strsSize; i++) {
        int prefixLen = 0; // 현재까지의 공통 접두사 길이
        // 현재 문자열과 비교하여 공통 접두사 길이 업데이트
        while (prefix[prefixLen] && strs[i][prefixLen] && prefix[prefixLen] == strs[i][prefixLen]) {
            prefixLen++;
        }
        prefix[prefixLen] = '\0'; // 공통 접두사의 끝에 NULL 문자 추가
    }
    
    return prefix;
}