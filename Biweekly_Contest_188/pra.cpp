class Solution {
public:
    int valid(string s , int l ,int r ){
        int count1=0;
        int count0=0;
        for(int i =l;i<=r;i++){
            if(s[i]=='1') count1++;
            else count0++;
        }
        if(abs(count0-count1)<=1) return 1;
        else return 0;
    }
    int countValidPrefixes(string s) {
        int total=0;
        int n =s.size();
        int l=0;
        int r=0;
        while(r<n){
            if(valid(s,l,r)==1){
                total++;
            }
            r++;
        }
        return total;
    }
};