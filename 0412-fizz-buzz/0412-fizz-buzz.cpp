class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;

        for(int i = 1; i <= n; ++i) {
            string op;
            if(i % 3 == 0) op += "Fizz";
            if(i % 5 == 0) op += "Buzz";

            if(op.length() == 0)
                op = to_string(i);

            ans.push_back(op);
        }

        return ans;
    }
};