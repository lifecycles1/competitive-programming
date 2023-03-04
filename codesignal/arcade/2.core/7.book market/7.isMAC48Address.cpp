// A media access control address (MAC address) is a unique identifier assigned to network 
// interfaces for communications on the physical network segment.

// The standard (IEEE 802) format for printing MAC-48 addresses in human-friendly form is six groups 
// of two hexadecimal digits (0 to 9 or A to F), separated by hyphens (e.g. 01-23-45-67-89-AB).

// Your task is to check by given string inputString whether it corresponds to MAC-48 address or not.

#include <string>

class Solution {
public:
  bool isMAC48Address(std::string inputString) {
    int len = inputString.length();
    if (len != 17) return false;
    for (int i = 0; i < len; i++) {
      if (i % 3 == 2) {
        if (inputString[i] != '-') return false;
      } else {
        if (!isHex(inputString[i])) return false;
      }
    }
    return true;
  }
  bool isHex(char c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F');
  }
};