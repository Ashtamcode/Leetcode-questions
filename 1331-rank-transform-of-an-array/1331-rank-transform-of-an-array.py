class Solution(object):
    def arrayRankTransform(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        x =sorted(set(arr))
        d = {}
        ans =[]
        for index,element in enumerate(x):
     
            d[element] =  index+1 # 10,20,30,40
                               #  0,1,2,3, 

        for i in arr:
            if i in d:
                ans.append(d[i])
        return ans

        