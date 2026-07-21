class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int prev =-1,sum=0,ones =0,i=0;
        while(i<s.size()){
            if(s[i] == '1'){
                ones++;
                i++;
            }else{
                int curr =0;
                while(i<s.size() && s[i] == '0'){
                    
                    curr++;
                    i++;
                }
                if(prev>0){
                    sum = max(sum,prev+curr);
                }
                prev = curr;
                
            }
        }
        return ones + sum;
    }
};