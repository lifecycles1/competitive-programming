# You are given n rectangular boxes, the ith box has the length lengthi, the width widthi and 
# the height heighti. Your task is to check if it is possible to pack all boxes into one so that 
# inside each box there is no more than one another box (which, in turn, can contain at most one 
# another box, and so on). More formally, your task is to check whether there is such sequence of n 
# different numbers pi (1 ≤ pi ≤ n) that for each 1 ≤ i < n the box number pi can be put into the box 
# number pi+1.
# A box can be put into another box if all sides of the first one are less than the respective ones 
# of the second one. You can rotate each box as you wish, i.e. you can swap its length, width and 
# height if necessary.

# Example

# For length = [1, 3, 2], width = [1, 3, 2], and height = [1, 3, 2], the output should be
# solution(length, width, height) = true;
# For length = [1, 1], width = [1, 1], and height = [1, 1], the output should be
# solution(length, width, height) = false;
# For length = [3, 1, 2], width = [3, 1, 2], and height = [3, 2, 1], the output should be
# solution(length, width, height) = false

class Solution:
    def solution(self, length, width, height):
        dimensions = []
        for i in range(len(length)):
            dimensions.append(sorted([length[i],width[i],height[i]]))
            
        dimensions = sorted(dimensions,key = lambda x: (x[0],x[1],x[2]))
        
        for i in range(len(length)-1):
            if dimensions[i][0]>= dimensions[i+1][0] or dimensions[i][1]>= dimensions[i+1][1] or dimensions[i][2]>= dimensions[i+1][2]:
                return False
            
        return True