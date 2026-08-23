class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
       vector<int>hash(upper+1,0) ;
        for(int i =0;i<nums.size();i++){
            if (nums[i] >= lower && nums[i] <= upper) {
                hash[nums[i]] = 1;
            }
        }
        vector<vector<int>> res;
        int i =lower;
        while(i<=upper){
            if(hash[i]==0){
                int j =i;
            
            while(j<=upper && hash[j]==0){
                j++;
            }
            res.push_back({i,j-1});
            i=j;
        }else{
            i++;
        }}
        return res;
    }
};