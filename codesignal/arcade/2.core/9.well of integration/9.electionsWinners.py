
class Solution:
    def electionsWinners(self, votes, k):
      maximum = 0
      count = 0
      for i in range(len(votes)):
        if votes[i] > maximum:
          maximum = votes[i]
          count = 1
        elif votes[i] == maximum:
          count += 1
      if k == 0:
        return 1 if count == 1 else 0
      result = 0
      for i in range(len(votes)):
        if votes[i] + k > maximum:
          result += 1
      return result
    

class Solution:
    def electionsWinners(self, votes, k):
      maximum = max(votes)
      return sum(1 for i in votes if i + k > maximum) + (1 if votes.count(maximum) == 1 and k == 0 else 0)