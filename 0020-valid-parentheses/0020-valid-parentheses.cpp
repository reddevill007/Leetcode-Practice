class Solution {
public:
    bool isValid(string str) {
        stack<char> s;

        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
                s.push(str[i]);
            }
            else {
                if(s.empty()) {
                    return false;
                }
                if(str[i] == ')' && s.top() != '(') {
                    return false;
                }
                else if(str[i] == ']' && s.top() != '[') {
                    return false;
                }

                else if(str[i] == '}' && s.top() != '{') {
                    return false;
                }
                else {
                    s.pop();
                }
            }
        }

        return s.empty();
    }
};