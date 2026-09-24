def sumdig(n):
    s =str(n)
    sui =0
    for i in s:
        sui += int(i)
    return sui
class Solution(object):
    
    def smallestIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mini = float('inf')
        for i in range(len(nums)):
            if i == sumdig(nums[i]):
                mini = min(mini,i)
        if(mini == float('inf')):
            return -1
        return mini