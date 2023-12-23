class Solution {
public:
    bool isPathCrossing(string path) {
        vector<int> origin(2, 0);

        unordered_set<string> loacation_track;
        loacation_track.insert("0,0");

        for(char &dir: path) {
            if(dir == 'N') {
                origin[0]++;
            } else if(dir == 'E') {
                origin[1]++;
            } else if(dir == 'S') {
                origin[0]--;
            } else if(dir == 'W') {
                origin[1]--;
            }

            int x = origin[0];
            int y = origin[1];

            string hash = to_string(x) + "," + to_string(y);

            if(!loacation_track.insert(hash).second) return true;
        }


        return false;
    }
};