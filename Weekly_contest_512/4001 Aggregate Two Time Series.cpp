class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {

        vector<vector<int>> res;
        int i = 0;
        int j = 0;
        int m = series1.size();
        int n = series2.size();
        
        while (i < m || j < n) {
            int current_time;
            int val1 = 0;
            int val2 = 0;
            
            if (i < m && j < n) {
                if (series1[i][0] == series2[j][0]) {
                    current_time = series1[i][0];
                    val1 = series1[i][1];
                    val2 = series2[j][1];
                    i++;
                    j++;
                } else if (series1[i][0] < series2[j][0]) {
                    current_time = series1[i][0];
                    val1 = series1[i][1];
                    val2 = series2[j][1]; 
                    i++;
                } else {
                    current_time = series2[j][0];
                    val1 = series1[i][1];
                    val2 = series2[j][1];
                    j++;
                }
            } else if (i < m) {
                current_time = series1[i][0];
                val1 = series1[i][1];
                val2 = 0;
                i++;
            } else {
                current_time = series2[j][0];
                val1 = 0; 
                val2 = series2[j][1];
                j++;
            }
            
            res.push_back({current_time, val1 + val2});
        }
        
        return res;
    }
};
