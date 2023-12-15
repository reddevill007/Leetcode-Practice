class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        unordered_map<string, int> link_count;

        for(auto path: paths) {
            link_count[path[0]]++;
        }

        for(auto path: paths) {
            if(link_count[path[1]] == 0) {
                return path[1];
            }
        }
        
        return "";
    }
};