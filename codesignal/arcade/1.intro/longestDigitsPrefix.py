# Given a string, output its longest prefix which contains only digits.

# Important to note: this is only for the prefix, not checking longest sequence of digits in entire string

def solution(inputString):
  prefix = ""
  i = 0
  while i < len(inputString) and inputString[i].isdigit():
    prefix += inputString[i]
    i += 1
  return prefix
