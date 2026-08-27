class Solution(object):
    def missingMultiple(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        d = {}
        for i in nums:
            if i in d:
                d[i] +=1
            else:
                d[i] =1
        
        for i in range(1,102):
            if i*k in d:
                continue
            else:
                return i*k
        
        