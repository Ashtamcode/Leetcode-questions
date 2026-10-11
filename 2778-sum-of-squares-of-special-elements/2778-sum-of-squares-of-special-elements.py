class Solution(object):
    def sumOfSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0
        n = len(nums)
        for index,ele in enumerate(nums):
            if n % (index+1) == 0:
                ans += ele**2
        return ans