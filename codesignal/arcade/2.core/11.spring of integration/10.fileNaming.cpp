// You are given an array of strings names representing filenames. The array is sorted in order of 
// file creation, such that names[i] represents the name of a file created before names[i+1] and 
// after names[i-1] (assume 0-based indexing). Because all files must have unique names, files 
// created later with the same name as a file created earlier should have an additional (k) suffix 
// in their names, where k is the smallest positive integer (starting from 1) that does not appear 
// in previous file names.

// Your task is to iterate through all elements of names (from left to right) and update all filenames 
// based on the above. Return an array of proper filenames.

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> fileNaming(std::vector<std::string> names) {
    for (int i = 0; i < names.size(); i++) {
      if (find(names.begin(), names.begin() + i, names[i]) != names.begin() + i) {
        int k = 1;
        while (find(names.begin(), names.begin() + i, names[i] + "(" + std::to_string(k) + ")") != names.begin() + i) {
          k++;
        }
        names[i] += "(" + std::to_string(k) + ")";
      }
    }
    return names;
  }
};