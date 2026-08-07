class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        if(num%3!=0){
            return ans;
        }else{
            long long num2 = num / 3;
            long long num1 = num2-1;
            long long num3 = num2+1;
            ans.push_back(num1);
            ans.push_back(num2);
            ans.push_back(num3);
        }
        return ans;
    }

};