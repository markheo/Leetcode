#define MAX_CHAR 26 // 알파벳 소문자 개수 -> 대문자 포함이면 52
int countUniqueCharsBetweenIndexes(char *s, int start, int end) {
    int hash_table[MAX_CHAR] = {0};
    for (int i = start + 1; i < end; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            hash_table[s[i] - 'a'] = 1;
        }
    }

    int count = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        count += hash_table[i];
    }
    return count;
}

int countPalindromicSubsequence(char* s) {
    int firstIndex[MAX_CHAR], lastIndex[MAX_CHAR];
    memset(firstIndex, -1, sizeof(firstIndex));
    memset(lastIndex, -1, sizeof(lastIndex));

    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int index = s[i] - 'a';
        if (firstIndex[index] == -1) firstIndex[index] = i;
        lastIndex[index] = i;
    }

    int count = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (firstIndex[i] != -1 && lastIndex[i] != -1 && firstIndex[i] != lastIndex[i]) {
            count += countUniqueCharsBetweenIndexes(s, firstIndex[i], lastIndex[i]);
        }
    }
    return count;
}