class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = nums.size();
        int tmp = 0;
        for (int i=0;i<l;i++) {
            if (nums[i] == val) {
                tmp++;
            }
        }
        int ans = l - tmp;
        int i=0;
        while (i < ans) {
            for (int j=0;j<l;j++) {
                if (nums[j] != val) {
                    nums[i] = nums[j];
                    i++;
                }
            }
        }
        return ans;
    }
};