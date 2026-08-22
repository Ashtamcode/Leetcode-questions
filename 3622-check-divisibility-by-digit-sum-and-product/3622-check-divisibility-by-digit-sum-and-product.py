class Solution(object):
    def checkDivisibility(self, n):
        """
        :type n: int
        :rtype: bool
        """
        s = str(n)
        d_s =0
        d_p = 1
        for i in s:
            d_s += int(i)
            d_p *= int(i)

        if n % (d_s+d_p) == 0:
            return True
        else:
            return False
