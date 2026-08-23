class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        vector<long long> bonus(n + 1, 0);
  for (const auto& b : boosts) {
            bonus[b[0]] += b[2];
            if (b[1] + 1 < n) bonus[b[1] + 1] -= b[2];
        }
        for (int i = 1; i < n; ++i) {
            bonus[i] += bonus[i - 1];
        }
        
        long long R=0;
        for(int i =n-1;i>=0;i--){
            if(R==0){
                R = max(0LL, (long long)monsters[i] - bonus[i]); 
            }else {
                 R += monsters[i];
            }
        }
        return R;
    }
};