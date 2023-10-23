class Solution {
public:
    bool isPowerOfFour(int n) {
        // if(n == 0 || n == 1) {
        //     return n;
        // }

        // while(n % 4 == 0) {
        //     n = n / 4;
        // }

        // if(n == 1) return true;
        // return false;

        // int x = (log(n) / log(4));

        // if(pow(4, x) == n) return true;
        // return false;

        return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }
};