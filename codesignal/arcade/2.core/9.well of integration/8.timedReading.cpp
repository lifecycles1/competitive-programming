// Timed Reading is an educational tool used in many schools to improve and advance reading skills. 
// A young elementary student has just finished his very first timed reading exercise. 
// Unfortunately he's not a very good reader yet, so whenever he encountered a word longer than 
// maxLength, he simply skipped it and read on.

// Help the teacher figure out how many words the boy has read by calculating the number of words 
// in the text he has read, no longer than maxLength.
// Formally, a word is a substring consisting of English letters, such that characters to the left 
// of the leftmost letter and to the right of the rightmost letter are not letters.

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
  int timedReading(int maxLength, string text) {
    int count = 0;
    int i = 0;
    while (i < text.size()) {
      if (isalpha(text[i])) {
        int j = i;
        while (j < text.size() && isalpha(text[j])) {
          j++;
        }
        if (j - i <= maxLength) {
          count++;
        }
        i = j;
      } else {
        i++;
      }
    }
    return count;
  }
};