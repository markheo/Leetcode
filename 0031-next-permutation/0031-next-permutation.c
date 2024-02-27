void swap_int_arr(int *nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

// 주어진 인덱스에서 시작하여 배열을 뒤집는 함수
void reverse_int_arr(int *nums, int start, int n) {
    int i = start, j = n - 1;
    while (i < j) {
        swap_int_arr(nums, i, j);
        i++;
        j--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;
    // 뒤에서부터 탐색하여 첫 번째 감소하는 위치 찾기
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {  // 감소하는 위치가 있다면
        int j = numsSize - 1;
        // 뒤에서부터 현재 값보다 큰 첫 번째 값 찾기
        while (j >= 0 && nums[j] <= nums[i]) {
            j--;
        }
        swap_int_arr(nums, i, j);  // 찾은 값과 교환
    }

    reverse_int_arr(nums, i + 1, numsSize);
}