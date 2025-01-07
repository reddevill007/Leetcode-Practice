class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string> seen;

        for (int i=0; i<9; ++i) {
            for (int j=0; j<9; ++j) {
                char number = board[i][j];

                if(number != '.') {
                    if(!seen.insert(to_string(number) + " in row " + to_string(i)).second ||
                        !seen.insert(to_string(number) + " in column " + to_string(j)).second ||
                        !seen.insert(to_string(number) + " in block " + to_string(i/3) + "-" + to_string(j/3)).second) {
                            return false;
                        }
                }
            }
        }

        return true;

    }
};