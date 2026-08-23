class Solution {
public:
    //o(n2)
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n =nums.size();
        int count=0;
        for(int i =0;i<nums.size();i++){
            int x=0;
            int y=0;
            for(int j =i;j<nums.size();j++){
                if(nums[j]%2==0){
                    x++;
                }else{
                    y++;
                }
                  if (y > 0 && (x * b <= a * y)) {
                    count++;
                }
            }
        }
        return count;
    }
};