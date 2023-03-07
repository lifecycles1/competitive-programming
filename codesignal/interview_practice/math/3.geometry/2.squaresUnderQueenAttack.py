# Note: Write a solution with O(queries.length + queens.length + n) complexity and 
# O(queries.length) additional memory, since this is what you would be asked to do during a 
# real interview.

# In chess, queens can move any number of squares vertically, horizontally, or diagonally. 
# You have an n × n chessboard with some queens on it. You are given several queries, each of 
# which represents one square on the chessboard. For each query square, determine whether it 
# can be attacked by a queen or not.

class Solution:
    def squaresUnderQueenAttack(n, queens, queries):
        # 'n' is not needed at all 
        rows, cols, diags1, diags2 = set(), set(), set(), set()
        for r, c in queens:
            rows.add(r)
            cols.add(c)
            diags1.add(r + c)
            diags2.add(r - c)
        return [r in rows or c in cols or r + c in diags1 or r - c in diags2 for r, c in queries]
    
              