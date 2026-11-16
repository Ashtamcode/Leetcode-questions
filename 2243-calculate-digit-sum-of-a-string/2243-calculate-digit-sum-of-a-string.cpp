class Solution {
private:
    string digsum(string num){
        int ans=0;
        for(int i=0;i<num.size();i++){
            ans += (num[i] - '0');
        }
        return to_string(ans);
    }
public:
    string digitSum(string s, int k) {
        int n = s.size();
        while(s.size() >k){
            int ch= 0;
            string n,sub;
            for(int i=0;i<s.size();i++){
                // string sub;
                if(ch<k){
                    sub+=s[i];
                    ch++;
                }else{
                    string sum = digsum(sub);
                    n+=sum;
                    ch =1;
                    sub = "";
                    sub += s[i];
                }
            }
            if(!sub.empty()){
                n+=digsum(sub);
            }
            s = n;
        }
        return s;
    }
};