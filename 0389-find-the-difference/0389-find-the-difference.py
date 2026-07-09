class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        o = 0
        k =0
        if s == "":
            return t
        else:
            for i in s:
                o += ord(i)
            for i in t:
                k += ord(i)
        return chr(k-o)
            