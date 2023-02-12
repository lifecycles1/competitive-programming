class ListNode:
  def __init__(self, val, prev=None, next=None):
    self.val = val
    self.prev = prev
    self.next = next

class BrowserHistory:
  def __init__(self, homepage: str):
    self.cur = ListNode(homepage)
  
  def visit(self, url: str):
    self.cur.next = ListNode(url, self.cur)
    self.cur = self.cur.next

  def back(self, steps: int) -> str:
    while self.cur.prev and steps > 0:
      self.cur = self.cur.prev
      steps -= 1
    return self.cur.val
  
  def forward(self, steps: int) -> str:
    while self.cur.next and steps > 0:
      self.cur = self.cur.next
      steps -= 1
    return self.cur.val

###############################################
# solution using an array/stack
class BrowserHistory:
  def __init__(self, homepage: str):
    self.i = 0  # i is the current pointer
    self.len = 1
    self.history = [homepage]
  
  def visit(self, url: str) -> None:
    if len(self.history) < self.i + 2:
      self.history.append(url)
    else:
      self.history[self.i+1] = url
    self.i += 1
    self.len = self.i + 1
  
  def back(self, steps: int) -> str:
    self.i = max(self.i - steps, 0)
    return self.history[self.i]
  
  def forward(self, steps: int) -> str:
    self.i = min(self.i + steps, self.len - 1)
    return self.history[self.i]