char * makeSmallestPalindrome(char * s){
    int len = strlen(s);
    char *result = strdup(s); // 문자열 복사

    if (!result) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int left = 0, right = len - 1;
    while (left < right) {
        if (result[left] != result[right]) {
            // 아스키 코드가 더 작은 문자로 통일
            if (result[left] < result[right]) {
                result[right] = result[left];
            } else {
                result[left] = result[right];
            }
        }
        left++;
        right--;
    }
    return result;
}