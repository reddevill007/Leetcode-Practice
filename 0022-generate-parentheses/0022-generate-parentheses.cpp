class Solution {
    void helpFun(vector<string> &res, int n, int openN, int closeN, string s) {
        if(openN == n && closeN == n) {
            res.push_back(s);
            return;
        }

        if(openN < n) {
            helpFun(res, n, openN + 1, closeN, s + "(");
        }

        if(closeN < openN) {
            helpFun(res, n, openN, closeN + 1, s + ")");
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int openN = 0, closeN = 0;
        helpFun(res, n, openN, closeN, "");
        return res;
    }
};