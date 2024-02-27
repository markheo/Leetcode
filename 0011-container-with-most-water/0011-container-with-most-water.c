int maxArea(int* height, int heightSize) {
    int maxArea = 0; // 최대 영역을 저장할 변수
    int left = 0; // 왼쪽 포인터
    int right = heightSize - 1; // 오른쪽 포인터

    while (left < right) {
        // 현재 포인터들 사이의 영역 계산
        int currentHeight = height[left] < height[right] ? height[left] : height[right];
        int currentArea = currentHeight * (right - left);

        // 최대 영역 업데이트
        if (currentArea > maxArea) {
            maxArea = currentArea;
        }

        // 포인터 이동
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
}