class Solution(object):
    def maxProduct(self, n):
        """
        :type n: int
        :rtype: int
        """
        x = []
        z = str(n)
        for i in range(len(z)):
            x.append(int(z[i]))

        y = sorted(x)[::-1]

        return y[0]*y[1]