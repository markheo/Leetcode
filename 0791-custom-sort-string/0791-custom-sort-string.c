#define HASH_SIZE 26

void build_order_hash_table(const char *order, int *hash_table) {
    for (int i = 0; i < HASH_SIZE; i++) {
        hash_table[i] = -1; // 초기값 설정
    }
    int len = strlen(order);
    for (int i = 0; i < len; i++) {
        hash_table[order[i] - 'a'] = i; // 문자의 우선순위 설정
    }
}

char* customSortString(char* order, char* s) {
    int len = strlen(s);
    char* result = malloc((len+1) * sizeof(char));
    
    int hash[HASH_SIZE];
    build_order_hash_table(order, hash);
    
    int count[HASH_SIZE] = {0}; // s 문자열에 있는 각 문자의 빈도수
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }

    int idx = 0;
    // order에 따라 result 문자열 생성
    for (int i = 0; i < strlen(order); i++) {
        while (count[order[i] - 'a'] > 0) {
            result[idx++] = order[i];
            count[order[i] - 'a']--;
        }
    }

    // order에 없는 문자를 result 뒤에 추가
    for (int i = 0; i < HASH_SIZE; i++) {
        while (count[i] > 0) {
            result[idx++] = i + 'a';
            count[i]--;
        }
    }

    result[idx] = '\0'; // 문자열 종료
    return result;
}