class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.length();
        int aliceCanPlay = 0;
        int bobCanPlay = 0;

        for(int i = 1; i < n - 1; i++) {
            if(colors[i] == colors[i - 1] && colors[i] == colors[i + 1]) {
                if(colors[i] == 'A') aliceCanPlay++;
                else bobCanPlay++;
            }
        }

        return aliceCanPlay > bobCanPlay;

    }
};