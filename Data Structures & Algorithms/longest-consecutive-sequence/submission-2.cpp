class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int maxLength = 0;

        unordered_set<int> seen(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int length = 0;
            int current = nums[i];

            if (seen.find(current - 1) == seen.end()) {
                while (seen.find(current) != seen.end()) {
                    length++;
                    current++;
                }
                maxLength = max(maxLength, length);
            }
        }
        return maxLength;
    }
};

/*
   maxLength = 0

   nums = [2, 20, 4, 10, 3, 4, 5]
           i
   seen = {2, 20, 4, 10, 3, 5}

   length = 1
   current = 3
*/