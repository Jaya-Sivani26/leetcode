class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        end = len(s)
        a = ""
        for i in s:
            if i.isalpha():
                a+=lower(i)
            if i.isnumeric():
                a+=i
        return a == a[::-1]
