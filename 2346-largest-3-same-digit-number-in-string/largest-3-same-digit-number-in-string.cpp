class Solution {
public:
    string largestGoodInteger(string num) {
        int curr_ans = -1;

        for(int i = 0; i < num.length() - 2; i++) {
            if(num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                curr_ans = max(curr_ans, int(num[i] - '0'));
            }
        }

        if(curr_ans == -1) return "";


        return string(3, '0' + curr_ans);
    }
};