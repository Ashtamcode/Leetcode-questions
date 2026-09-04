class Solution(object):
    def firstStableIndex(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        mi = float('inf')
        for i in range(len(nums)):
            if max(nums[0:i+1]) - min(nums[i:n]) <= k:
                mi = min(mi,i)
        if(mi == float('inf')):
            return -1     
        return mi