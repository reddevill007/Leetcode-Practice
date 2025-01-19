class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> sequenceCount;
        int i = 0;
        int j = 9;

        while(j < s.length()) {
            sequenceCount[s.substr(i, j - i + 1)]++;
            j++;
            i++;
        }

        vector<string> repeatedSequence;

        for(auto it: sequenceCount) {
            if(it.second > 1) repeatedSequence.push_back(it.first);
        }

        return repeatedSequence;
    }
};