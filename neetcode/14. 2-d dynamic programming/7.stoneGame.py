# Alice and Bob play a game with piles of stones. There are an even number of piles arranged 
# in a row, and each pile has a positive integer number of stones piles[i].

# The objective of the game is to end with the most stones. The total number of stones across 
# all the piles is odd, so there are no ties.

# Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile 
# of stones either from the beginning or from the end of the row. This continues until there are 
# no more piles left, at which point the person with the most stones wins.

# Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

from typing import List

# 15% raster runtime. memory efficient solution
class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        dp = {} # subarr piles (l ,r) -> Max Alice Total

        # Return: Max Alice Total
        def dfs(l: int, r: int) -> int:
            if l > r:
                return 0
            if (l, r) in dp:
                return dp[(l, r)]
            
            even = True if (r - l) % 2 else False
            left = piles[l] if even else 0
            right = piles[r] if even else 0
            
            # Alice take left
            dp[(l, r)] = max(dfs(l+1, r) + left,
            # Alice take right
                            dfs(l, r-1) + right)
            
            return dp[(l, r)]
        
        return dfs(0, len(piles) -1) > (sum(piles)) // 2
    

# 30% faster runtime. time efficient solution
class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        # allocate the space, not so efficient
        dp = [[0]*(len(piles)) for k in range(len(piles))]

        # initial conditions:
        for i in range(len(piles)):
            dp[i][i] = piles[i]
        
        # make caution of the sequence of updating, from small-gap to huge-gap (controlled by d)
        for d in range(1, len(piles)):
            for i in range(len(piles) - d):
                dp[i][i+d] = max(piles[i] - dp[i+1][i+d], piles[i+d] - dp[i][i+d-1])

        print(dp)      
        if dp[0][-1] > 0:
            return True
        
        return False
    
