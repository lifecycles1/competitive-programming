# Given the positions of a bishop and a pawn on the standard chess board, determine whether the bishop can 
# capture the pawn in one move.

# The bishop has no restrictions in distance for each move, but is limited to diagonal movement.

# board from A1 to H8


def solution(bishop, pawn):
    return abs(ord(bishop[0])-ord(pawn[0]))==abs(int(pawn[1])-int(bishop[1]))
    
    # or search in each direction
#     s = "_abcdefgh"
#     ind = s.index(bishop[0])
#     for i in range(int(bishop[1]) + 1, 9):
#         if ind < 8: 
#             ind += 1
#         else: break
#         if s[ind] == pawn[0] and i == int(pawn[1]): return True
    
#     ind = s.index(bishop[0])
#     for i in range(int(bishop[1]) - 1, 1, -1):
#         if ind < 8: 
#             ind += 1
#         else: break
#         if s[ind] == pawn[0] and i == int(pawn[1]): return True
    
#     ind = s.index(bishop[0])
#     for i in range(int(bishop[1]) - 1, 1, -1):
#         if ind > 0: 
#             ind -= 1
#         else: break
#         if s[ind] == pawn[0] and i == int(pawn[1]): return True
        
#     ind = s.index(bishop[0])
#     for i in range(int(bishop[1]) + 1, 9):
#         if ind > 0: 
#             ind -= 1
#         else: break
#         if s[ind] == pawn[0] and i == int(pawn[1]): return True
#     return False
