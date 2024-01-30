class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;

        for(auto it: tokens) {
            if(it == "*" || it == "/" || it == "+" || it == "-") {
                long long top = st.top();
                st.pop();
                long long second = st.top();
                st.pop();

                if(it == "*") {
                    long long  val = second * top;
                    st.push(val);
                } else if(it == "+") {
                    long long  val = second + top;
                    st.push(val);
                } else if(it == "-") {
                    long long  val = second - top;
                    st.push(val);
                } else if(it == "/") {
                    long long  val = second / top;
                    st.push(val);
                }
            } else {
                st.push(stoll(it));
            }
        }

        return st.top();
    }
};