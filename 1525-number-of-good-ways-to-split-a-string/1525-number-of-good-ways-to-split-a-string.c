#define ALPHABET_SIZE 26

int numSplits(char* s) {
    int len = strlen(s);
    int leftCounts[ALPHABET_SIZE] = {0}, rightCounts[ALPHABET_SIZE] = {0};
    int uniqueLeft = 0, uniqueRight = 0, result = 0;

    // 왼쪽에서 오른쪽으로 순회하며 고유 문자 개수를 계산
    for (int i = 0; i < len; i++) {
        if (++leftCounts[s[i] - 'a'] == 1) uniqueLeft++;
    }

    // 오른쪽에서 왼쪽으로 순회하며 고유 문자 개수를 비교
    for (int i = len - 1; i > 0; i--) {
        if (++rightCounts[s[i] - 'a'] == 1) uniqueRight++;
        if (--leftCounts[s[i] - 'a'] == 0) uniqueLeft--;

        if (uniqueLeft == uniqueRight) result++;
    }

    return result;
}