class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;

        for (int i : nums) {   // nums = [5,5,2,2,3,3,3]   
            frequency[i]++;
        }
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto it = frequency.begin(); it != frequency.end(); ++it) {
            buckets[it->second].push_back(it->first);
        }

        vector<int> result;
        for (int i = static_cast<int>(nums.size()); i >= 1; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);

                if (result.size() == k) {
                    return result;
                }
            }
        }
        return result;
    }
}; 


/*
    1. unordered_map<int, int> frequency;
        for (int i : nums) {
            add 1 to each number that occurs in nums

    
        }

        frequency = {
            {5, 2},
            {2, 2},
            {3, 3}
        }

    2.  create frequency buckets that hold the number
    vector<vector<int>> buckets(nums.size() + 1);
    [
        [0],
        [1],
        [2],
        [3],
        [4],
        [5],
        [6],
        [7]
    ]


*/