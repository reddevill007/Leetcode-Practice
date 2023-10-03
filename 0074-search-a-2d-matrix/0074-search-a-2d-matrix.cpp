class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0, col = n - 1;

        while(row < m && col > -1) {
            int curr = matrix[row][col];
            if(curr == target) return true;
            if(target > curr) row++;
            else col--;
        }

        return false;
    }
};