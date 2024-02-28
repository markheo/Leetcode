#define ALPHABET_SIZE 26 // 알파벳의 개수

// 문자열에서 문자 세트를 생성하는 함수
void createCharSet(const char *str, bool charSet[ALPHABET_SIZE]) {
    int len = strlen(str);
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        charSet[i] = false; // 초기화
    }
    for (int i = 0; i < len; i++) {
        if ('a' <= str[i] && str[i] <= 'z') {
            charSet[str[i] - 'a'] = true; // 소문자인 경우
        } else if ('A' <= str[i] && str[i] <= 'Z') {
            charSet[str[i] - 'A'] = true; // 대문자인 경우(필요한 경우)
        }
    }
}

bool isEqualSet(const bool charSet1[ALPHABET_SIZE], const bool charSet2[ALPHABET_SIZE]) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (charSet1[i] != charSet2[i]) {
            return false;
        }
    }
    return true;
}

int similarPairs(char** words, int wordsSize) {
    int ans = 0;
    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            bool charSet1[ALPHABET_SIZE], charSet2[ALPHABET_SIZE];
            createCharSet(words[i], charSet1);
            createCharSet(words[j], charSet2);
            // if (isSuperset(charSet1, charSet2) || isSuperset(charSet2, charSet1)) ans++;
            if (isEqualSet(charSet1, charSet2)) ans++;
        }
    }
    return ans;
}