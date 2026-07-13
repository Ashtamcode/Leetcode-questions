class Solution(object):
    def sequentialDigits(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: List[int]
        """
        s = "123456789"
        ans =[]
        for leng in range(2,11):
            for j in range(len(s)-leng +1):
                substr = int(s[j:j+leng])
                if substr >= low and substr <=high:
                    ans.append(substr)
        return ans