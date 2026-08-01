class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = ['a', 'e', 'i', 'o', 'u','A','E','I','O','U']
        li = list(s)
        v = []
        for i in li:
            if i in vowels:
                v.append(i)
        v= v[::-1]
        j=0
        for i in range(len(li)):

            if li[i] in vowels and j<len(v):
                li[i] = v[j]
                j+=1
        return "".join(li)