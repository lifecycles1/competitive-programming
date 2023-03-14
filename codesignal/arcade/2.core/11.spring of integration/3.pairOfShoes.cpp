// Yesterday you found some shoes in the back of your closet. Each shoe is described by two values:

// type indicates if it's a left or a right shoe;
// size is the size of the shoe.
// Your task is to check whether it is possible to pair the shoes you found in such a way that each 
// pair consists of a right and a left shoe of an equal size.

// Example

// For

// shoes = [[0, 21], 
        //  [1, 23], 
        //  [1, 21], 
        //  [0, 23]]
// the output should be
// solution(shoes) = true;

#include <vector>
#include <map>

class Solution {
public:
    bool solution(std::vector<std::vector<int>> shoes) {
        std::map<int, int> m;
        for (auto shoe : shoes) {
            m[shoe[1]] += shoe[0] ? 1 : -1;
        }
        for (auto p : m) {
            if (p.second != 0) {
                return false;
            }
        }
        return true;
    }
};