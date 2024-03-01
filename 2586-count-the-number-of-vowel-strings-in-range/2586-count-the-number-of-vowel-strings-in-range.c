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

bool endsWith(const char *str, const char *suffix) {
    if (str == NULL || suffix == NULL) return false;
    int str_len = strlen(str);
    int suffix_len = strlen(suffix);
    if (suffix_len > str_len) return false;
    return strncmp(str + str_len - suffix_len, suffix, suffix_len) == 0;
}

int vowelStrings(char** words, int wordsSize, int left, int right) {
    int ans = 0;
    for (int i = left; i <= right; i++) {
        if ((startsWith(words[i], "a") || startsWith(words[i], "e") || startsWith(words[i], "i") || startsWith(words[i], "o") || startsWith(words[i], "u")) &&
            (endsWith(words[i], "a") || endsWith(words[i], "e") || endsWith(words[i], "i") || endsWith(words[i], "o") || endsWith(words[i], "u"))) ans++;
    }
    return ans;
}