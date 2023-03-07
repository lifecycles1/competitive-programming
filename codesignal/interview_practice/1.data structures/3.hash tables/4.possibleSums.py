# You have a collection of coins, and you know the values of the coins and the quantity of 
# each type of coin in it. You want to know how many distinct sums you can make from non-empty 
# groupings of these coins.

class Solution:
    def possibleSums(self, coins, quantity):
        # create a dictionary to store the sums
        # create a list to store the sums
        sums = set()
        sums.add(0)
        # loop through the coins
        for i in range(len(coins)):
            newSums = set()
            # loop through the quantity
            for j in range(quantity[i] + 1):
                # loop through the sums
                for s in sums:
                    # add the coin to the sum
                    newSums.add(s + j * coins[i])
            # update the sums
            sums = newSums
        # return the length of the sums
        return len(sums) - 1
    