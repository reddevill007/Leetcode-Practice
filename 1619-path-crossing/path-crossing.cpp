class Solution {
public:
    bool isPathCrossing(string path) {
        vector<int> origin(2, 0);

        set<pair<int, int>> loacation_track;
        loacation_track.insert({0, 0});

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

            if(!loacation_track.insert({x, y}).second) return true;
        }


        return false;
    }
};