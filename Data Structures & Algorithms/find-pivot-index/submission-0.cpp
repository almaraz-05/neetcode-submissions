class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());

        int preTotal = 0;
        int suffTotal = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix[i] = preTotal;
            preTotal += nums[i];
        }   
        for (int i = nums.size() - 1; i >= 0; i--) {
            suffix[i] = suffTotal;
            suffTotal += nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (prefix[i] == suffix[i]) {
                return i;
            }
        }
        return -1;

    }
};