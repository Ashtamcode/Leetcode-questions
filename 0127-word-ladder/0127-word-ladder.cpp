class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if(word == endWord){
                return lvl;
            }
            for(int i=0;i<word.size();i++){
                char orignal = word[i];
                for(char c='a';c<='z';c++){
                    word[i] = c;
                    if(s.count(word)){
                        q.push({word,lvl+1});
                        s.erase(word);
                    }
                }
                word[i] = orignal;
            }
        }
        return 0;
    }
};