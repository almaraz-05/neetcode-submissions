class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;

        for (int i : nums) {
            frequency[i]++;
        }

        // create frequency buckets
        vector<vector<int>> buckets(nums.size() + 1);

        for (auto it = frequency.begin(); it != frequency.end(); ++it) {
            buckets[it->second].push_back(it->first);
        }

        // find top k elements and store in a vector
        vector<int> result; 

        for (int i = nums.size(); i >= 1; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
            }

            if (result.size() == k) {
                return result;
            }
        }
        return result;
    }
};
