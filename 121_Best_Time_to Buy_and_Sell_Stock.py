class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        prof = 0
        minpr = prices[0]
        for i in range(1,n):
            if prices[i] - minpr > prof:
                prof = prices[i] - minpr
            if prices[i] < minpr:
                minpr =prices[i]
        return prof
        
