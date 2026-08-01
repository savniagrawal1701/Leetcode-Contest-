class Solution {
public:
    int largestInteger(int n, int s) {
      if(s>9*n)  return -1;
        if(s==0) return 0;
        
        string ans = string(s / 9, '9');
        if (s % 9) ans += to_string(s % 9);
        
        ans += string(n - ans.length(), '0');
        return stoi(ans);
    }
};