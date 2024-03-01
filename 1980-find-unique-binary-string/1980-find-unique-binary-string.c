char** generatePermutations(int k, int *size) {
    char** result = (char**)malloc(*size * sizeof(char*));
    char* arr = (char*)malloc((k + 1) * sizeof(char));
    arr[k] = '\0';
    int index = 0;

    generateAllBinaryStrings(k, arr, 0, result, &index);

    free(arr); // 임시 배열에 대한 메모리 해제
    return result;
}

void generateAllBinaryStrings(int n, char arr[], int i, char** result, int* index) {
    if (i == n) {
        result[*index] = strdup(arr);
        (*index)++;
        return;
    }

    arr[i] = '0';
    generateAllBinaryStrings(n, arr, i + 1, result, index);

    arr[i] = '1';
    generateAllBinaryStrings(n, arr, i + 1, result, index);
}

char* findDifferentBinaryString(char** nums, int numsSize) {
    int len = strlen(nums[0]);
    
    // char* ans = malloc((len+1) * sizeof(char));
    // ans[0] = '\0';

    int size = pow(2, len);
    char** result = generatePermutations(len, &size);
    for (int i = 0; i < size; i++) {
        int found = 0;
        for (int j = 0; j < numsSize; j++) {
            if (strcmp(result[i], nums[j]) == 0) {
                found = 1; // result[i]가 nums 배열에 존재함
                break;
            }
        }
        if (!found) { // nums 배열에 없는 문자열을 찾음
            char* ans = strdup(result[i]); // 찾은 문자열 복사하여 반환
            // 메모리 해제 부분
            for (int k = 0; k < size; k++) free(result[k]);
            free(result);
            return ans; // 없는 문자열 반환
        }
    }

    // 모든 문자열이 nums 배열에 존재하는 경우, 여기는 도달하지 않음
    // 메모리 해제 부분
    for (int i = 0; i < size; i++) free(result[i]);
    free(result);

    return NULL; // 이론상 발생하지 않음
}