# You're a crossword fanatic, and have finally decided to try and create your own. 
# However, you also love symmetry and good design, so you come up with a set of rules they 
# should follow:

# the crossword must contain exactly four words;
# these four words should form four pairwise intersections;
# all words must be written either left-to-right or top-to-bottom;
# the area of the rectangle formed by empty cells inside the intersections isn't equal to zero.
# Given 4 words, find the number of ways to make a crossword following the above-described rules. 
# Note that two crosswords which differ by rotation are considered different

from itertools import permutations as p

class Solution:
    def crosswordFormation(words):
      c = 0
      for l in p(words):
          for d1 in range(len(l[0])-2):
              s1 = [i for i,j in enumerate(l[1]) if j == l[0][d1]]
              for d2 in range(d1+2, len(l[0])):
                  s2 = [i for i,j in enumerate(l[2]) if j == l[0][d2]]
                  for cw1 in s1:
                      for cw2 in s2:
                          for c1, c2 in zip(l[1][cw1+2:],l[2][cw2+2:]):
                              for c3, c4 in zip(l[3],l[3][d2-d1:]):
                                  c += c1 == c3 and c2 == c4
      return c