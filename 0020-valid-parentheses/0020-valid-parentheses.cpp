class Solution {
public:
    bool isValid(string str) {
        stack<char> st;

        for(int i = 0; i < str.length(); i++) {
            // if(str[i] == '(' || str[i] == '{' || str[i] == '[') st.push(str[i]);
            if(str[i] == '(' || str[i] == '{' || str[i] == '[')
                st.push(str[i]);
            else {
                if(st.empty())
                    return false;
                else if(str[i] == ')' && st.top() != '(')
                    return false;
                else if(str[i] == '}' && st.top() != '{')
                    return false;
                else if(str[i] == ']' && st.top() != '[')
                    return false;
                else 
                    st.pop();
            }
        }

        return st.empty();
    }
};