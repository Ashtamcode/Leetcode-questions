class Solution {
private:
    int countOverlap(vector<vector<int>>&a,vector<vector<int>>&b,int r,int c){
        int n = a.size();
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int n_r = i+r;
                int n_c = j+c;
                if(n_r>=n || n_r<0 || n_c >=n || n_c < 0){
                    continue;
                }
                if(a[i][j] == 1 && b[n_r][n_c] == 1){
                    count++;
                }
            }
        }
        return count;
    }
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int m =0;
        for(int row_off = -n+1;row_off<n;row_off++){
            for(int col_off=-n+1;col_off<n;col_off++){
                m = max(m,countOverlap(img1,img2,row_off,col_off));
            }
        }
        return m;
    }
};