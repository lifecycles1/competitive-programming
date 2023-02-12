// The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

// For example, "ACGAATTCCG" is a DNA sequence.
// When studying DNA, it is useful to identify repeated sequences within the DNA.

// Given a string s that represents a DNA sequence, return all the 10-letter-long sequences 
// (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

# include < string >
# include < vector >
# include < map >
# include < unordered_map >
using namespace std;

// slow solution
class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    map<string, int> sequences;
    vector<string> multiples;
    for (int i = 0, ii = s.size(); i < ii; i++) {
      string seq = s.substr(i, 10);
      if (seq.length() != 10) {
        break;
      }
      if (sequences.count(seq) == 0) {
        sequences[seq] = 0;
      }
      sequences[seq]++;
    }
    for (auto const& [pos, count] : sequences) {
      if (count > 1) {
        multiples.push_back(pos);
      }
    }
    return multiples;
  }
};

// 90% runtime
class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    int n = s.size();
    if (n <= 10) {
      return {};
    }
    vector<string> answer;
    unordered_map<string, int> hash;
    for (int i = 0; i <= s.size() - 10; i++) {
      string ss = s.substr(i, 10);
      hash[ss]++;
      if (hash[ss] == 2) {
        answer.push_back(ss);
      }
    }
    return answer;
  }
};