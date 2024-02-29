bool startsWith(const char *str, const char *prefix) {
    if (str == NULL || prefix == NULL)
        return false;

    while (*prefix) {
        if (*str != *prefix) {
            return false;
        }
        str++;
        prefix++;
    }
    return true;
}

char* replaceWords(char** dictionary, int dictionarySize, char* sentence) {
    char* result = malloc(sizeof(char) * strlen(sentence) + 1);  // 결과를 저장할 공간, 처음에 지정하고 초기화를 안하면 이상한 값이 있을 수 있음
    result[0] = '\0'; // result[0] = '\0'; 구문을 사용함으로써, result 문자열은 현재 비어 있는 상태
    
    char* word = strtok(sentence, " ");  // 문장을 공백으로 분리
    while (word != NULL) {
        char* shortestPrefix = NULL;
        for (int i = 0; i < dictionarySize; i++) {
            if (startsWith(word, dictionary[i])) {
                // 가장 짧은 접두사 찾기
                if (shortestPrefix == NULL || strlen(dictionary[i]) < strlen(shortestPrefix)) {
                    shortestPrefix = dictionary[i];
                }
            }
        }

        if (shortestPrefix) {
            strcat(result, shortestPrefix);
        } else {
            strcat(result, word);
        }

        word = strtok(NULL, " ");  // 다음 단어
        if (word != NULL) {
            strcat(result, " ");  // 단어 사이에 공백 추가
        }
    }

    return result;
}