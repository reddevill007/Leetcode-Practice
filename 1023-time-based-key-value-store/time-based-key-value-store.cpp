class TimeMap {
private:
    unordered_map<string,vector<pair<string, int> > > mp;
    // key : pair of value, timestamp
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        int i = 0;
        int j = mp[key].size() - 1;
        string res;

        while(i <= j){
            int mid = (i + j) / 2;

            if(mp[key][mid].second <= timestamp) {
                res = mp[key][mid].first;
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return res;
    }
};