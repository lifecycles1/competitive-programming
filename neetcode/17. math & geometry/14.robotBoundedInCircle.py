# On an infinite plane, a robot initially stands at (0, 0) and faces north. Note that:

# The north direction is the positive direction of the y-axis.
# The south direction is the negative direction of the y-axis.
# The east direction is the positive direction of the x-axis.
# The west direction is the negative direction of the x-axis.
# The robot can receive one of three instructions:

# "G": go straight 1 unit.
# "L": turn 90 degrees to the left (i.e., anti-clockwise direction).
# "R": turn 90 degrees to the right (i.e., clockwise direction).
# The robot performs the instructions given in order, and repeats them forever.

# Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        # 0: north, 1: east, 2: south, 3: west
        direction = 0
        # initial position
        x = y = 0
        for i in instructions:
            if i == 'G':
                if direction == 0:
                    y += 1
                elif direction == 1:
                    x += 1
                elif direction == 2:
                    y -= 1
                else:
                    x -= 1
            elif i == 'L':
                direction = (direction + 3) % 4
            else:
                direction = (direction + 1) % 4
        return (x == 0 and y == 0) or direction != 0