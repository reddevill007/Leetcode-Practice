class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> onesRow(n, 0);
        vector<int> onesCol(m, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    onesRow[i]++;
                    onesCol[j]++;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int zerosRow = n - onesRow[i]; 
                int zerosCol = m - onesCol[j]; 

                grid[i][j] = onesRow[i] + onesCol[j] - zerosRow - zerosCol;
            }
        }

        return grid;
    }
};