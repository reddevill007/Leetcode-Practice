class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string> seen;

        for (int i=0; i<9; ++i) {
            for (int j=0; j<9; ++j) {
                char number = board[i][j];

                if(number != '.') {
                    string b = "(" + to_string(number) + ")";
                    if(!seen.insert(b + to_string(i)).second || !seen.insert(to_string(j) + b).second || !seen.insert(to_string(i / 3) + b + to_string(j/3)).second) {
                        return false;
                    }
                }
            }
        }

        return true;

    }
};