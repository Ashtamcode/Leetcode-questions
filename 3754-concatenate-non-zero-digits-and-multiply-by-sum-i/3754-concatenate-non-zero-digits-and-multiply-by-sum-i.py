class Solution(object):
    def sumAndMultiply(self, n):
        """
        :type n: int
        :rtype: int
        """
        s=str(n)
        x = ""
        if n == 0:
            return 0
        for i in range(len(s)):
            if s[i] != '0':
                x += s[i]

        sum1 =0
        for i in range(len(x)):
            sum1 += int(x[i])

        return sum1 * int(x)