

char * mergeAlternately(char * word1, char * word2){
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int reslen = len1 + len2;
    char* result = (char *)malloc((reslen+1) * sizeof(char));
    int index1 = 0, index2 = 0;
    for (int i = 0; i < reslen; i++) {
        if ((i % 2 == 0 && index1 < len1) || index2 >= len2) {
            result[i] = word1[index1++];
        } else if ((i % 2 != 0 && index2 < len2) || index1 >= len1) {
            result[i] = word2[index2++];
        }
    }

    result[reslen] = '\0'; // Null terminator
    return result;
}