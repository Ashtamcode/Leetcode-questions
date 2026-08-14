class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(const auto &[key,value]:m){
            if(value >=2){
                return true;
                break;
            }
        }
        return false;
    }
};