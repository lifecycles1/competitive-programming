/**
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(val)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */

var MinStack = function () {
  this.stack = [];
};

/**
 * @param {number} val
 * @return {void}
 */
MinStack.prototype.push = function (val) {
  this.stack.push(val);
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function () {
  this.stack.pop();
};

/**
 * @return {number}
 */
MinStack.prototype.top = function () {
  return this.stack.slice(-1)[0];
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function () {
  if (this.stack.length === 0) return -1;
  return Math.min(...this.stack);
};

////////////////////////////////////////////
// JavaScript solution 2
////////////////////////////////////////////

/**
 * Time O(1) | Space O(N)
 */
class MinStack {
  constructor() {
    this.stack = [];
    this.minStack = [];
  }

  /**
   * @param {number} val
   * @return {void}
   */
  push(val, { minStack } = this) {
    this.stack.push(val);

    const isMinEmpty = !minStack.length;
    const hasNewMin = val <= this.top(minStack);
    const canAddMin = isMinEmpty || hasNewMin;
    if (canAddMin) minStack.push(val);
  }

  /**
   * @return {void}
   */
  pop({ stack, minStack } = this) {
    const top = stack.pop();

    const canPopMin = top === this.getMin();
    if (canPopMin) minStack.pop();
  }

  /**
   * @return {number}
   */
  top(stack = this.stack) {
    return stack.length ? stack[stack.length - 1] : null;
  }

  /**
   * @return {number}
   */
  getMin(minStack = this.minStack) {
    return this.top(minStack);
  }
}

////////////////////////////////////////////
// JavaScript solution 3
////////////////////////////////////////////

/**
 * Time O(1) | Space O(1)
 */

class MinStack {
  constructor() {
    this.head = null;
  }

  /**
   * @param {number} val
   * @return {void}
   */
  push(val) {
    this.head = !this.head ? new Node(val, val, null) : new Node(val, Math.min(val, this.head.min), this.head);
  }

  /**
   * @return {void}
   */
  pop() {
    this.head = this.head.next;
  }

  /**
   * @return {number}
   */
  top() {
    return this.head.val;
  }

  /**
   * @return {number}
   */
  getMin() {
    return this.head.min;
  }
}

class Node {
  constructor(val, min, next) {
    this.val = val;
    this.min = min;
    this.next = next;
  }
}
