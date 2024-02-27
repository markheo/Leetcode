int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}


int maxOperations(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), compare);
    int maxOps = 0; // 최대 작업 횟수 저장할 변수
    int left = 0; // 왼쪽 포인터
    int right = numsSize - 1; // 오른쪽 포인터

    while (left < right) {
        int currentSum = nums[left] + nums[right]; // 현재 포인터들의 합 계산
        
        if (currentSum == k) { // 합이 k와 같으면
            maxOps++; // 작업 횟수 증가
            left++; // 왼쪽 포인터 이동
            right--; // 오른쪽 포인터 이동
        } else if (currentSum < k) { // 합이 k보다 작으면
            left++; // 왼쪽 포인터 이동
        } else { // 합이 k보다 크면
            right--; // 오른쪽 포인터 이동
        }
    }

    return maxOps;
}