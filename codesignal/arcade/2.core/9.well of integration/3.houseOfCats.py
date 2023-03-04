# There are some people and cats in a house. 
# You are given the number of legs they have all together. 
# Your task is to return an array containing every possible number of people that could be in the 
# house sorted in ascending order. It's guaranteed that each person has 2 legs and each cat has 4 legs.

class Solution:
    def houseOfCats(self, legs):
        return [i for i in range(int(legs/2)+1) if (legs-2*i)%4==0] 