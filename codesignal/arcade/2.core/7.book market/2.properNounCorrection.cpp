// Proper nouns always begin with a capital letter, followed by small letters.

// Correct a given proper noun so that it fits this statement.

#include <string>

class Solution {
public:
  std::string properNounCorrection(std::string noun) {
    std::string result = "";
    result += toupper(noun[0]);
    for (int i = 1; i < noun.size(); i++) {
      result += tolower(noun[i]);
    }
    return result;
  }
};