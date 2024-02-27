int removeElement(int* nums, int numsSize, int val) {
    int i = 0; // 결과 배열의 인덱스
    for (int j = 0; j < numsSize; j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i; // 새로운 배열의 길이 반환
}