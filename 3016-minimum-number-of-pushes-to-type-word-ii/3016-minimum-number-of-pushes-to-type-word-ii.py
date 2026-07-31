class Solution(object):
    def minimumPushes(self, word):
        """
        :type word: str
        :rtype: int
        """
        d = {}
        for i in word:
            if i in d:
                d[i] +=1
            else:
                d[i] = 1
        vals = list(d.values())
        vals.sort(reverse=True)
        i = 0
        res = 0
        for cout in vals:
            res += cout * (1 + i // 8)
            i+=1
        return res
            