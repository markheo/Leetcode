char* getSmallestString(int n, int k) {
    char* ans = malloc((n + 1) * sizeof(char));
    ans[n] = '\0'; // 문자열 종료 문자 추가

    // 각 위치에 배치할 수 있는 최소 값인 'a'로 초기화
    for (int i = 0; i < n; i++) {
        ans[i] = 'a';
        k--; // 'a'를 배치함으로써 소모되는 가중치 1을 뺀다.
    }

    // 뒤에서부터 최대한 큰 값으로 채워넣기
    int i = n - 1;
    while (k > 0) {
        // 현재 위치에서 추가할 수 있는 가중치 계산 (최대 'z'까지)
        int add = (k < 25) ? k : 25;
        ans[i] += add; // 해당 위치의 문자를 업데이트
        k -= add; // 추가된 가중치만큼 k 감소
        i--; // 이전 위치로 이동
    }

    return ans;
}