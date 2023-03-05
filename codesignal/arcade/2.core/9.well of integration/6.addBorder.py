# Given a rectangular matrix of characters, add a border of asterisks(*) to it.

class Solution:
      def addBorder(self, picture):
          for i in range(len(picture)):
              picture[i] = "*" + picture[i] + "*"
          picture.insert(0, "*" * len(picture[0]))
          picture.append(picture[0])
          return picture