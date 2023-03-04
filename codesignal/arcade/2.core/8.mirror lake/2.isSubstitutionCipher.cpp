// A ciphertext alphabet is obtained from the plaintext alphabet by means of rearranging some 
// characters. For example "bacdef...xyz" will be a simple ciphertext alphabet where a and b 
// are rearranged.

// A substitution cipher is a method of encoding where each letter of the plaintext alphabet is 
// replaced with the corresponding (i.e. having the same index) letter of some ciphertext alphabet.

// Given two strings, check whether it is possible to obtain them from each other using some 
// (possibly, different) substitution ciphers.

#include <string>
#include <vector>

class Solution {
public:
  bool isSubstitutionCipher(std::string string1, std::string string2) {
    std::vector<int> buckets1(26, 0);
    std::vector<int> buckets2(26, 0);
    for(int i = 0; i < string1.size(); i++){
      if(buckets1[string1[i]-'a'] != buckets2[string2[i]-'a']) {
        return false;
      }
      buckets1[string1[i]-'a'] = i+1;
      buckets2[string2[i]-'a'] = i+1;
    }
    return true;
  }
};