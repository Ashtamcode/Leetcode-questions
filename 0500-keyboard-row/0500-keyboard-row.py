class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """

        row1 = "qwertyuiop"
        row2 = "asdfghjkl"
        row3 = "zxcvbnm"
        
        ans = []
        for word in words:
            c1,c2,c3 = 0,0,0
            for ch in word.lower():
                if ch in row1:
                    c1+=1
                elif ch in row2:
                    c2 +=1
                else:
                    c3 +=1
            if(c1>=1 and c2 ==0 and c3 == 0):
                ans.append(word)
            elif(c1 ==0 and c2>=1 and c3 ==0):
                ans.append(word)
            elif(c1 ==0 and c2==0 and c3>=1):
                ans.append(word)
        return ans