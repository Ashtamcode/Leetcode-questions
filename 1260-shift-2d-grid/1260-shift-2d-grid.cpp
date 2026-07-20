class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size() , n= grid[0].size();
        vector<vector<int>> matrix(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int index = ((n*i + j) + k) % (m*n) ;
                int index_2x = index / n;
                int index_2y = index % n;
                matrix[index_2x][index_2y] = grid[i][j];
            }
        }
        return matrix;
    }
};