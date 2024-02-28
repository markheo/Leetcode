char* largestGoodInteger(char* num) {
    char* largest = (char*)malloc(4 * sizeof(char)); // 결과를 저장할 문자열
    largest[0] = '\0'; // 초기화
    int len = strlen(num);

    for (int i = 2; i < len; i++) {
        if (num[i] == num[i-1] && num[i] == num[i-2]) { // 연속하는 동일한 문자 확인
            if (largest[0] == '\0' || num[i] > largest[0]) { // 가장 큰 '좋은' 정수 갱신
                largest[0] = num[i];
                largest[1] = num[i];
                largest[2] = num[i];
                largest[3] = '\0';
            }
        }
    }

    return largest;
}