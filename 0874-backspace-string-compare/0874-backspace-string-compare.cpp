class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a = "", b = "";

        for(auto ch: s) {
            cout << a << endl;
            if(ch == '#' && a.length() != 0) {
                a.pop_back();
            } else if(ch != '#'){
                a.push_back(ch);
            }
        }

        for(auto ch: t) {
            cout << b << endl;
            if(ch == '#' && b.length() != 0) {
                b.pop_back();
            } else if(ch != '#'){
                b.push_back(ch);
            }
        }

        cout << "string a: " << a << " string b: " << b << endl;

        return (a == b);
    }
};