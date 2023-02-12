// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is 
// being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; there are no extra white spaces, square brackets 
// are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits 
// and that digits are only for those repeat numbers, k. For example, there will not be input 
// like 3a or 2[4].

// The test cases are generated so that the length of the output will never exceed pow(10,5).

# include <string>
# include <stack>
using namespace std;

class Solution {
public:
  string decodeString(string s) {
    stack<char> stack_;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] != ']') {
        stack_.push(s[i]);
      } else {
        string substr = "";
        while (stack_.top() != '[') {
          substr = stack_.top() + substr;
          stack_.pop();
        }
        stack_.pop();

        string k = "";
        while (!stack_.empty() && isdigit(stack_.top())) {
          k = stack_.top() + k;
          stack_.pop();
        }
        int repeat = stoi(k);
        for (int j = 0; j < repeat; j++) {
          for (int l = 0; l < substr.size(); l++) {
            stack_.push(substr[l]);
          }
        }
      }
    }
    string result = "";
    while (!stack_.empty()) {
      result = stack_.top() + result;
      stack_.pop();
    }
    return result;
  }
};

// faster solution with Tail Recursion
class Solution {
public:
  string recursion(const string& s, int& i) {
    string res;
    while (i < s.length() && s[i] != ']') {
      if (!isdigit(s[i]))
        res += s[i++];
      else {
        int n = 0;
        while (i < s.length() && isdigit(s[i]))
          n = n * 10 + s[i++] - '0';
        i++; // '['
        string t = recursion(s, i);
        i++; // ']'
        
        while (n-- > 0)
          res += t;
      }
    }
    return res;
  }

  string decodeString(string s) {
    int i = 0;
    return recursion(s, i);
  }
};