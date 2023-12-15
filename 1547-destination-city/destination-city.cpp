class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        unordered_set<string> cities;

        for(vector<string> &path: paths) {
            cities.insert(path[0]);
        }

        for(vector<string> &path: paths) {
            if(cities.find(path[1]) == cities.end()) {
                return path[1];
            }
        }
        
        return "";
    }
};