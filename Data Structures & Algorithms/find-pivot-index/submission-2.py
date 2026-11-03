class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        
        prefix = [0] * len(nums)
        suffix = [0] * len(nums)

        preTotal = 0
        suffTotal = 0

        for i in range(len(nums)):
            prefix[i] = preTotal
            preTotal += nums[i]
        
        for i in range(len(nums) - 1, -1, -1):
            suffix[i] = suffTotal
            suffTotal += nums[i]

        for i in range(len(nums)):
            if prefix[i] == suffix[i]:
                return i

        return -1