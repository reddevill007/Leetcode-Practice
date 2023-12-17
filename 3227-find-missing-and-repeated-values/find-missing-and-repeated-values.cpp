class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> newArr;
        int n = grid.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                newArr.push_back(grid[i][j]);
            }
        }
        
        sort(newArr.begin(), newArr.end());
        vector<int> arr(2, -1);
        
        for(int i = 0; i < n * n - 1; i++) {
            if (newArr[i] == newArr[i + 1]) {
                arr[0] = newArr[i]; // Repeating number
            }
            else if (newArr[i] + 1 != newArr[i + 1]) {
                arr[1] = newArr[i] + 1; // Missing number
            }
        }
        
        if(newArr[0] != 1) arr[1] = 1;

        // Handle the case when the missing number is at the end
        if (arr[1] == -1 && newArr[n * n - 1] != n * n) {
            arr[1] = n * n; // Missing number
        }

        return arr;
    }
};