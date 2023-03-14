# Some people run along a straight line in the same direction. They start simultaneously at pairwise 
# distinct positions and run with constant speed (which may differ from person to person).

# If two or more people are at the same point at some moment we call that a meeting. The number of 
# people gathered at the same point is called meeting cardinality.

# For the given starting positions and speeds of runners find the maximum meeting cardinality assuming 
# that people run infinitely long. If there will be no meetings, return -1 instead.

# Example

# For startPosition = [1, 4, 2] and speed = [27, 18, 24], the output should be
# solution(startPosition, speed) = 3.

# In 20 seconds after the runners start running, they end up at the same point. Check out the gif below 
# for better understanding:

class Solution:
    def solution(startPosition, speed):
        res = -1
        for i in range(len(startPosition)):
            meetings = {}
            for j in range(i+1, len(startPosition)):
                if speed[i] == speed[j]:
                    if startPosition[i] == startPosition[j]:
                        time = 0
                        place = startPosition[i]
                    else:
                        continue
                elif startPosition[i] < startPosition[j] or speed[i] < speed[j]:
                    time = (startPosition[i]-startPosition[j])/(speed[j]-speed[i])
                    place = startPosition[i] + speed[i]*time
                else:
                    continue
                if (time, place) not in meetings:
                    meetings[(time, place)] = 1
                meetings[(time, place)] += 1
                if meetings[(time, place)] > res:
                    res = meetings[(time, place)]
        return res