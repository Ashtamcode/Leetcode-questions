class Solution(object):
    def checkGoodInteger(self, n):
        """
        :type n: int
        :rtype: bool
        """
        s = str(n)
        digsum =0
        square = 0
        for i in s:
            digsum += int(i)
            square += int(i)*int(i)
        
        return square-digsum >=50