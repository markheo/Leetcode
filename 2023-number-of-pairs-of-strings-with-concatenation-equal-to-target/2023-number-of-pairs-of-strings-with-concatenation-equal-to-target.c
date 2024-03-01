int numOfPairs(char** nums, int numsSize, char* target) {
    int ans = 0;

    for (int i=0; i<numsSize; i++) {
        for (int j=0; j<numsSize; j++) {
            if (i!=j) {
                char* tmp = malloc(201 * sizeof(char));
                tmp[0] = '\0';
                strcat(tmp, nums[i]);
                strcat(tmp, nums[j]);
                if (strcmp(tmp, target) == 0) ans++;
                free(tmp);
            }
        }
    }
    return ans;
}