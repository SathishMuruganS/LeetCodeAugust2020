/**
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 

Constraints:

s consists only of printable ASCII characters.
**/

class Solution {
    void removeAlphaNumaric(string& s){
        for(unsigned int i =0;i<s.size(); i++){
            if (!isalnum(s[i])){
                s.erase(s.begin()+i, s.begin()+i+1);
                i--;
            }
        }
    }
public:
    bool isPalindrome(string s) {
        int i = 0;
        bool flag = false;
        removeAlphaNumaric(s);
        int j = s.size() - 1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if (s.empty() || s.size() == 1) return true;
        
        while (i<j){
            flag = false;
            if (s[i] == s[j]){
                i++;
                j--;
                flag = true;
            }else{
                flag = false;
                break;
            }
        }
        return flag;
    }
};
