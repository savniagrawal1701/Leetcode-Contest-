#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        int m = shifts.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + tasks[i];
        }
        vector<int> ans;
        long long comp = 0;
        for (int i = 0; i < m; i++){
            long long s = shifts[i];
            
            if (comp + s < pref[n]) {
                comp += s;
                int completed = upper_bound(pref.begin(), pref.end(), comp) - pref.begin() - 1;
                ans.push_back(n - completed);
            } else {
                ans.push_back(0);
                comp = 0;
            }
        }
        return ans;
    }
};
