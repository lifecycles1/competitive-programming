/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function (s) {
  // let strippedstring = s.replace(/[^a-zA-Z0-9]/g, "").toLowerCase();

  let left = 0;
  let right = strippedstring.length - 1;

  while (left < right) {
    if (strippedstring[left] != strippedstring[right]) {
      return false;
    }
    left++;
    right--;
  }
  return true;
};
