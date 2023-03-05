# N candles are placed in a row, some of them are initially lit. 
# For each candle from the 1st to the Nth the following algorithm is applied: 
# if the observed candle is lit then states of this candle and all candles before it are 
# changed to the opposite. Which candles will remain lit after applying the algorithm to all 
# candles in the order they are placed in the line?

class Solution:
    def switchLights(self, a):
        return [(x + sum(a[i:]))%2 for i,x in enumerate(a)]