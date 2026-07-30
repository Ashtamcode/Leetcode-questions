class Solution {
public:
    int minimumPushes(string word) {
        int size = word.size();
        int count =0;
        if(size<=8) count = size;
        else if(size<=16) count  = 8 + (size-8)*2;
        else if(size<=24) count = 24 + (size-16)*3;
        else count= 48 + (size-24)*4;

        return count;

    }
};