# We want to turn the given integer into a number that has only one non-zero digit using a 
# tail rounding approach. This means that at each step we take the last non 0 digit of the number 
# and round it to 0 or to 10. If it's less than 5 we round it to 0 if it's larger than or equal to 
# 5 we round it to 10 (rounding to 10 means increasing the next significant digit by 1). 
# The process stops immediately once there is only one non-zero digit left.

class Solution:
    def rounders(n):
        n = str(n)
        for i in range(len(n)-1, 0, -1):
            if int(n[i]) >= 5:
                n = n[:i-1] + str(int(n[i-1]) + 1) + '0' * (len(n) - i)
            else:
                n = n[:i] + '0' * (len(n) - i)
        return int(n)