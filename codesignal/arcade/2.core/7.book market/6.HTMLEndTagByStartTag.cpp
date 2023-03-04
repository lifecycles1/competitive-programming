// You are implementing your own HTML editor. To make it more comfortable for developers you 
// would like to add an auto-completion feature to it.

// Given the starting HTML tag, find the appropriate end tag which your editor should propose.

#include <string>

class Solution {
public:
  std::string htmlEndTagByStartTag(std::string startTag) {
    int len = startTag.length();
    int i = 1;
    while (i < len && startTag[i] != ' ' && startTag[i] != '>') i++;
    return "</" + startTag.substr(1, i - 1) + ">";
  }
};