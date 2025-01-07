class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string> seen;

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    if(
                        !seen.insert(to_string(board[i][j]) + "x" + to_string(i)).second
                        || !seen.insert(to_string(board[i][j]) + "y" + to_string(j)).second
                        || !seen.insert(to_string(board[i][j])+ to_string(i / 3) + "xy" + to_string(j / 3)).second
                    ) return false;
                }
            }
        }

        return true;
    }
};