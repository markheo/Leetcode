int compareFreq(int freq1[26], int freq2[26]) {
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) return 0;
        }
        return 1;
} // Function to check if two words are special equivalent
    
int isSpecialEquivalent(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    if (len1 != len2) return 0;
    
    int freq1Even[26] = {0}, freq1Odd[26] = {0};
    int freq2Even[26] = {0}, freq2Odd[26] = {0};
    
    for (int i = 0; i < len1; i++) {
        if (i % 2 == 0) {
            freq1Even[str1[i] - 'a']++;
            freq2Even[str2[i] - 'a']++;        
        } else {
            freq1Odd[str1[i] - 'a']++;
            freq2Odd[str2[i] - 'a']++;
        }
    }
    
    return compareFreq(freq1Even, freq2Even) && compareFreq(freq1Odd, freq2Odd);
}

int numSpecialEquivGroups(char** words, int wordsSize) {
    int group = 0;
    int* grouped = (int*)calloc(wordsSize, sizeof(int)); // Array to mark grouped words
    
    for (int i = 0; i < wordsSize; i++) {
        if (grouped[i]) continue; // Skip already grouped words\n        
        group++; // New group found
        
        for (int j = i + 1; j < wordsSize; j++) {
            if (isSpecialEquivalent(words[i], words[j])) {
                grouped[j] = 1; // Mark word as grouped
                }
        }
    }
    free(grouped);
    return group;
}