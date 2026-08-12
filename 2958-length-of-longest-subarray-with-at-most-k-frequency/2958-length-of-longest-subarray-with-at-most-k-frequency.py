class Solution(object):
    def maxSubarrayLength(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        freq = {}  # value : freq
        l =0 
        m = 0
        for j in range(len(nums)):
            freq[nums[j]] = freq.get(nums[j],0) + 1

            while freq[nums[j]] > k:
                freq[nums[l]] -= 1
                l +=1
            m = max(m,j-l+1)
        return m


