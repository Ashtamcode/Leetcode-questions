class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> stk;
        int prevtime = 0;

        for (const string& s : logs) {
            int first_colon = s.find(':');
            int last_colon = s.rfind(':');

            int id = stoi(s.substr(0, first_colon));
            string type = s.substr(first_colon + 1, last_colon - first_colon - 1);
            int time = stoi(s.substr(last_colon + 1));

            if (type == "start") {
                if (!stk.empty()) {
                    ans[stk.top()] += (time - prevtime);
                }
                stk.push(id);
                prevtime = time;
            } 
            else {
                ans[stk.top()] += (time - prevtime + 1);
                stk.pop();
                prevtime = time + 1;
            }
        }
        return ans;
    }
};
