class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        // find shortest distance b/w (i)th and (i+1)th point
        // min(dx + dy) + abs(dx - dy)
        // ^Diagnol       ^extra

        int n = points.size();
        int steps = 0;

        for(int i = 0; i < n - 1; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            int x2 = points[i + 1][0];
            int y2 = points[i + 1][1];

            int dx = abs(x2 - x1);
            int dy = abs(y2 - y1);

            int curr_steps = min(dx, dy) + abs(dy - dx);

            steps += curr_steps;
        }

        return steps;
    }
};