class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length() - 1;

        for(int i = n; i >= 0; i--) {
            int curr_digit = int(num[i] - '0');

            if(curr_digit % 2 != 0) {
                return num.substr(0, i + 1);
            }
        }

        return "";
    }
};