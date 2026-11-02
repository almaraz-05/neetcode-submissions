class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        frequency = {}

        for i in nums:
            frequency[i] = frequency.get(i, 0) + 1
        
        """ 
        nums = [1,1,2,2,2,3]

        frequency = {
                {1: 2},
                {2: 3},
                {3: 1}
                num freq
        }

        create a frequency bucket:
        """
        buckets = [[] for i in range(len(nums) + 1)] # len = 6 -> buckets = 6 + 1

        for num, freq in frequency.items():
            buckets[freq].append(num)

        """ 
        buckets = [
            [0]
            [1], -> 3
            [2], -> 1
            [3], -> 2
            [4],
            [5],
            [6],
            [7]
        ] 
        
        turn buckets list into a single list:

        
        """ 
        result = []
        for i in range(len(nums), 0, -1):
            for num in buckets[i]:
                result.append(num)

            if len(result) == k:
                return result
        return result




