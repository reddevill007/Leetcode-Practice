class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        vector<int> indexToBeRemoved;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                st.push(i);
            }

            else if(s[i] == ')') {
                if(st.empty()) {
                    indexToBeRemoved.push_back(i);
                } else {
                    st.pop();
                }
            }
        }

        while(!st.empty()) {
            indexToBeRemoved.push_back(st.top());
            st.pop();
        }

        string res = "";

        for(int i = 0; i < s.length(); i++) {
            if(count(indexToBeRemoved.begin(), indexToBeRemoved.end(), i)) continue;
            res.push_back(s[i]);
        }

        return res;
    }
};