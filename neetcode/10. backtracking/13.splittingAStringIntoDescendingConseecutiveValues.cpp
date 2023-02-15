// You are given a string s that consists of only digits.

// Check if we can split s into two or more non-empty substrings such that the numerical values of the substrings are in descending order 
// and the difference between numerical values of every two adjacent substrings is equal to 1.

// For example, the string s = "0090089" can be split into ["0090", "089"] with numerical values [90,89]. The values are in 
// descending order and adjacent values differ by 1, so this way is valid.
// Another example, the string s = "001" can be split into ["0", "01"], ["00", "1"], or ["0", "0", "1"]. However all the ways are 
// invalid because they have numerical values [0,1], [0,1], and [0,0,1] respectively, all of which are not in descending order.
// Return true if it is possible to split s​​​​​​ as described above, or false otherwise.

// A substring is a contiguous sequence of characters in a string.

#include <string>
using namespace std;

// greedy approach
class Solution {
	bool dfs(int index, long long firstVal, string& str)
	{
		if (index == str.length())
			return true;

		for (int j = index; j < str.length(); j++) {
			long long secondVal = stoll(str.substr(index, j - index + 1));

			//If current val is 1 less than prev, then proceed for further valuation
			if (secondVal + 1 == firstVal && dfs(j + 1, secondVal, str))
				return true;

			//if current val is greater than prev value then no point in proceeding further
			else if (secondVal > firstVal)
				return false;
		}
		return false;
	}

public:

	bool splitString(string s)
	{
		//take out leading zeros
		while (s[0] == '0') {
			s.erase(0, 1);
		}

		int len = s.length();

		//special case: if len is 1 then it has to be false
		if (len == 1)
			return false;

		//max length of first number can be half of original string length
		if (len % 2 == 0)
			len = len / 2;
		else
			len = (len / 2) + 1;

		for (int i = 0; i < len; i++) {
			long long firstVal = stoll(s.substr(0, i + 1));
			if (dfs(i + 1, firstVal, s))
				return true;
		}
		return false;
	}
};