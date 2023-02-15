# A valid IP address consists of exactly four integers separated by single dots. 
# Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

# For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", 
# "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
# Given a string s containing only digits, return all possible valid IP addresses that can be 
# formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. 
# You may return the valid IP addresses in any order.

from typing import List

class Solution:
  def restoreIpAddresses(self, s: str) -> List[str]:
    res = []
    self.backtrack(s, 0, [], res)
    return res

  def backtrack(self, s: str, start: int, path: List[str], res: List[str]):
    if len(path) == 4:
      if start == len(s):
        res.append('.'.join(path))
      return
    for i in range(start, start + 3):
      if i < len(s):
        if i > start and s[start] == '0':
          break
        if int(s[start:i+1]) <= 255:
          path.append(s[start:i+1])
          self.backtrack(s, i+1, path, res)
          path.pop()