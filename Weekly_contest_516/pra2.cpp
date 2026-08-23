class Solution {
public:
    vector<int> getPrimes(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            while (n % i == 0) n /= i; 
        }
    }
    if (n > 1) factors.push_back(n); 
    return factors;
}
    void removeprime(int n , unordered_map<int,int>&pc){
        if(n%2==0){
            pc[2]--;
            if(pc[2]==0) pc.erase(2);
            while(n%2==0)n/=2;
        }
        for(int i =3;i*i<=n;i+=2){
            if(n%i==0){
                pc[i]--;
                if(pc[i]==0)pc.erase(i);
                while(n%i==0)n/=i;
            }
        }
        if(n>1){
            pc[n]--;
            if(pc[n]==0)pc.erase(n);
        }
    }

    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int,int> pc;
        int l=0;
        int maxi=0;
        for(int r=0;r<nums.size();r++){
            vector<int>fact=getPrimes(nums[r]);
            for(int f:fact){
                pc[f]++;
            }
            while(pc.size()>k){
                removeprime(nums[l],pc);
                l++;
            }
            maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};