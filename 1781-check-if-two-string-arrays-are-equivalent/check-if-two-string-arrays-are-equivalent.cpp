class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string res1 = "";
        string res2 = "";

        for(int i = 0; i < word1.size(); i++) {
            res1 += word1[i];
        }
        
        for(int i = 0; i < word2.size(); i++) {
            res2 += word2[i];
        }

        return (res1 == res2);
    }
};