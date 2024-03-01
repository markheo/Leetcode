char* findDifferentBinaryString(char** nums, int numsSize) {
    int len = strlen(nums[0]); // nums 배열의 모든 문자열은 같은 길이를 가짐
    char* diffStr = (char*)malloc((len + 1) * sizeof(char)); // 결과 문자열 할당

    for (int i = 0; i < len; i++) {
        // nums 배열의 i번째 문자열의 i번째 문자를 확인하고 반전
        if (nums[i][i] == '0') {
            diffStr[i] = '1';
        } else {
            diffStr[i] = '0';
        }
    }

    diffStr[len] = '\0'; // 문자열 종료 문자 추가

    return diffStr; // 생성된 유일한 문자열 반환
}