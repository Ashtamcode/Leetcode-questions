class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int count = 0;
        for (int i = 0; i < arr1.size(); i++) { // 4 5 8         // 1 8 9 10
            int ele = arr1[i];
            int l = 0, r = arr2.size() - 1;
            bool found = false;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (abs(arr2[mid] - ele) <= d) {
                     found = true;
                    break;
                   
                }
                else if(arr2[mid] < ele){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
            if(found){
                count++;
            }
        }
        return arr1.size()-count;
    }
};