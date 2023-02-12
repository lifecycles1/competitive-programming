// Every valid email consists of a local name and a domain name, separated by the '@' sign. 
// Besides lowercase letters, the email may contain one or more '.' or '+'.

// For example, in "alice@leetcode.com", "alice" is the local name, and "leetcode.com" is the domain name.
// If you add periods '.' between some characters in the local name part of an email address, mail sent 
// there will be forwarded to the same address without dots in the local name. Note that this rule does 
// not apply to domain names.

// For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.
// If you add a plus '+' in the local name, everything after the first plus sign will be ignored. This 
// allows certain emails to be filtered. Note that this rule does not apply to domain names.

// For example, "m.y+name@email.com" will be forwarded to "my@email.com".
// It is possible to use both of these rules at the same time.

// Given an array of strings emails where we send one email to each emails[i], return the number of 
// different addresses that actually receive mails.

#include <vector>
#include <string>
#include <set>
#include <regex>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int numUniqueEmails(vector<string>& emails) {
    set<string> unique_emails;
    for (string email: emails) {
      string local_name = email.substr(0, email.find('@'));
      local_name = local_name.substr(0, email.find('+'));
      local_name = regex_replace(local_name, regex("\\."), "");
      string domain_name = email.substr(email.find('@') + 1, email.length());
      email = local_name + '@' + domain_name;
      unique_emails.insert(email);
    }
    return unique_emails.size();
  }
};

// faster solution
class Solution {
public:
  int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> st;
    for(string &email : emails) {
      string cleanEmail;
      for(char c : email) {
        if(c == '+' || c == '@') break;
        if(c == '.') continue;
        cleanEmail += c;
      }
      cleanEmail += email.substr(email.find('@'));
      st.insert(cleanEmail);
    }
    return st.size();
  }
};

// fastest solution
class Solution {
public:
  int numUniqueEmails(vector<string>& emails) {
    for(auto& email:emails){
      auto at_location = find(email.begin(), email.end(), '@');
      auto end_after_removing_dots = remove(email.begin(), at_location, '.');
      auto plus_location = find(email.begin(), end_after_removing_dots, '+');
      email.erase(plus_location, at_location);
    }
    return unordered_set(emails.begin(),emails.end()).size();
  }
};