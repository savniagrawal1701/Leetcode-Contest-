class Solution {
public:
    bool isPalindromic(string s) {
        string bs="";
       for(char c:s){
           bs+=bitset<8>(c).to_string();
       }
        string rev=bs;
        reverse(rev.begin(),rev.end());
        if(bs==rev) return true;
        return false;
    }
};
