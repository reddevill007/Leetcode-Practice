class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();

        int prevLaserCnt = 0;

        int totalLaserbeams = 0;

        for(int i = 0; i < n; i++) {
            int currLaserCnt = 0;

            for(char &ch: bank[i]) {
                if(ch == '1') {
                    currLaserCnt++;
                }
            }

            if(currLaserCnt == 0) {
                continue;
            } else {
                totalLaserbeams += currLaserCnt*prevLaserCnt;
                prevLaserCnt = currLaserCnt;
            }
        }

        return totalLaserbeams;
    }
};