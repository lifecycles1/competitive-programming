// You are given an array of strings products and a string searchWord.

// Design a system that suggests at most three product names from products after each character 
// of searchWord is typed. Suggested products should have common prefix with searchWord. 
// If there are more than three products with a common prefix return the three lexicographically
// minimums products.

// Return a list of lists of the suggested products after each character of searchWord is typed.

#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
//If the strings are sorted we can binary search to get the first word that has the same prefix, we can then just check the next 2 words to see if they have the same prefix or not.
  std::vector<std::vector<std::string>> suggestedProducts(std::vector<std::string>& products, std::string searchWord) {
    std::sort(products.begin(), products.end());
    std::vector<std::vector<std::string>> res;
    std::string temp = "";
    int low = 0;
    int high = 0;
    for (int i = 0; i < searchWord.length(); i++) {
      temp += searchWord[i];
      low = lower_bound(products.begin()+high, products.end(), temp) - products.begin();
      res.push_back({});
      for (int j = low; (j < (low+3) && j < products.size()) && (!products[j].compare(0, temp.size(), temp)); j++) {
        res.back().push_back(products[j]);
      }
      high = low;
    }
    return res;
  }
};