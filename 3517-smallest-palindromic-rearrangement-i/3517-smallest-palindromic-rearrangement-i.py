class Solution(object):
    def smallestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) == 1 or len(s) == 0:
            return s
        if len(s)%2==0:
            half_s = s[0:len(s)//2]
            a = "".join(sorted(half_s))
            ans = ""
            ans = a + a[::-1]
            return ans
        else:
            mid = len(s) // 2
            half_s = s[0:mid]
            a = "".join(sorted(half_s))
            ans = a + s[mid] + a[::-1] 
            return ans