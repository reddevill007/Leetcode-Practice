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
        int mid = (i + j) / 2;
        int maxt = 0;
        string res;

        while(i <= j){
            if(timestamp > mp[key][mid].second){
                if(maxt <= mp[key][mid].second){
                    maxt = mp[key][mid].second;
                    res = mp[key][mid].first;
                }

                i = mid + 1;
            }else if(timestamp < mp[key][mid].second){
                j = j - 1;
            }else{
                return mp[key][mid].first;
            }
            mid = (i + j)/2;
        }
        return res;
    }
};