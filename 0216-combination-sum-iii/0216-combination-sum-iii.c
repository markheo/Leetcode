/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void findCombinations(int k, int n, int start, int currSum, int* currComb, int idx, int*** result, int* returnSize, int** returnColumnSizes) {
    // 조건 만족시 결과에 추가
    if (idx == k && currSum == n) {
        (*result)[*returnSize] = (int*)malloc(k * sizeof(int));
        for (int i = 0; i < k; i++) {
            (*result)[*returnSize][i] = currComb[i];
        }
        (*returnColumnSizes)[*returnSize] = k;
        (*returnSize)++;
        return;
    } else if (idx == k || currSum > n) { // 조건 불만족시 백트래킹
        return;
    }

    for (int i = start; i <= n - currSum && i <= 9; i++) {
        currComb[idx] = i;
        findCombinations(k, n, i + 1, currSum + i, currComb, idx + 1, result, returnSize, returnColumnSizes);
    }
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(1000 * sizeof(int*)); // 결과를 저장할 배열, 크기 추정
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));
    *returnSize = 0;
    int* currComb = (int*)malloc(k * sizeof(int)); // 현재 조합을 저장할 배열
    findCombinations(k, n, 1, 0, currComb, 0, &result, returnSize, returnColumnSizes);
    free(currComb);
    return result;
}