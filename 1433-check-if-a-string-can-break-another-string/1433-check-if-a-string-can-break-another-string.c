#define ALPHABET_SIZE 26

void build_hash_table(const char *str, int *hash_table) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        hash_table[str[i] - 'a']++;
    }
}

bool checkIfCanBreak(char* s1, char* s2) {
    int freq1[ALPHABET_SIZE] = {0}, freq2[ALPHABET_SIZE] = {0};
    
    build_hash_table(s1, freq1);
    build_hash_table(s2, freq2);

    // 누적 빈도 계산
    for (int i = 1; i < ALPHABET_SIZE; i++) {
        freq1[i] += freq1[i - 1];
        freq2[i] += freq2[i - 1];
    }
    
    bool s1CanBreak = true, s2CanBreak = true;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (freq1[i] < freq2[i]) s1CanBreak = false;
        if (freq2[i] < freq1[i]) s2CanBreak = false;
    }
    
    return s1CanBreak || s2CanBreak;
}