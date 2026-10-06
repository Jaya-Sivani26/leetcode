int maxProfit(int* prices, int pricesSize) {
    int i,di=0,minpr = prices[0];//assume 0th is min price and update it later
    for (i = 1; i < pricesSize; i++){
        if(prices[i] - minpr > di)
            di = prices[i] - minpr;
        if (prices[i] < minpr)
            minpr = prices[i];
    }
    return di;
}
