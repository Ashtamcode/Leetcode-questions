class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string> hash;
        for(int i=0;i<knowledge.size();i++){
            hash[knowledge[i][0]] = knowledge[i][1];
        }
        string result = "";

        int i=0;
        while(i<s.size()){
            if(s[i] == '('){
                int  j= i+1;
                while(j < s.size() && s[j] != ')' ){
                    j++;
                }
                string f = s.substr(i+1,j-i-1);
                if(hash.find(f) != hash.end()){
                    result += hash[f];
                }else{
                    result += "?";
                }
                i = j;

            }
           else{
            result += s[i];
           }
           i++;

        }
        return result;
    }
};