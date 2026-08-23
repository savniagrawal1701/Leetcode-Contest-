class Solution {
public:
    // 0(n2)
    long long maxPairStrength(vector<int>& nums) {
        long long s=-1;
        long long maxi = -1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                s = ((long long)nums[i] * nums[j]) /
                    ((long long)gcd(nums[i], nums[j]) * gcd(nums[i], nums[j]));
                maxi = max(maxi, s);
            }
        }
        return maxi;
    }
};
