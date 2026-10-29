class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<string>opp = {"+","-","*","/"};
        stack<string>stk;
        for(int i=0;i<tokens.size();i++){
            if(find(opp.begin(),opp.end(),tokens[i]) == opp.end()){
                stk.push(tokens[i]);
            }
            else{
                int b = stoi(stk.top());
                stk.pop();
                int a = stoi(stk.top());
                stk.pop();
                if(tokens[i] =="+"){
                    stk.push(to_string(a+b));
                }
                if(tokens[i] =="-"){
                    stk.push(to_string(a-b));
                }
                if(tokens[i] =="*"){
                    stk.push(to_string(a*b));
                }
                if(tokens[i] =="/"){
                    stk.push(to_string(a/b));
                }
            }
            
            
        }
        return stoi(stk.top());
    }
};