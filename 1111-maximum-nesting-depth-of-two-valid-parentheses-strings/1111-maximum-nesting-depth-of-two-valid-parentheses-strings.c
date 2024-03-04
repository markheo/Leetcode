/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char* seq, int* returnSize) {
    char *stack = (char *)malloc(returnSize + 1); // 스택으로 사용할 메모리 할당
    int len = 0;
    while (seq[len] != '\0') len++; // 문자열 길이 계산
    
    int* result = (int*)malloc(sizeof(int) * len);
    if (!result) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    int depth = 0;
    for (int i = 0; i < len; ++i) {
        if (seq[i] == '(') {
            depth++;
            // 깊이가 짝수인 경우 0, 홀수인 경우 1 할당
            result[i] = depth % 2;
        } else {
            result[i] = depth % 2;
            depth--;
        }
    }

    *returnSize = len;
    return result;
}