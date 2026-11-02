class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = [0] * len(nums)
        suffix = [0] * len(nums)
        answer = [0] * len(nums)

        product = 1
        for i in range(len(nums)):
            prefix[i] = product
            product *= nums[i]
        
        product = 1
        for i in reversed(range(len(nums))):
            suffix[i] = product
            product *= nums[i]

        for i in range(len(nums)):
            answer[i] = prefix[i] * suffix[i] 
        
        return answer