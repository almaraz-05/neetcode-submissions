class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
         int k = 0;
         for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
         }
         return k;
    }
};

/*
    nums = [2,2,2,3] val = 3   k = 2
                i

    Remove all occurences of val.
    Change nums so the first k elements of nums contain the elements which
    are not equal to val





*/
