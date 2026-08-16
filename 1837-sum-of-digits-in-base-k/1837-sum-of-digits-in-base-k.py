class Solution(object):
    def sumBase(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        digits = []
        while(n>0):
            digit = n % k
            digits.append(digit)
            n /= k
        digits = digits[::-1]

        su =0
        for i in digits:
            su +=i
        return su