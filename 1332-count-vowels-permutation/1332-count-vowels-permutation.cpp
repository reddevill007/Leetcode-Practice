class Solution {
public:
    int countVowelPermutation(int n) {
        long long prevA = 1, prevE = 1, prevI = 1, prevO = 1, prevU = 1;
        int MOD = 1e9 + 7;

        // a -> e, i, u
        // e -> a, i
        // i -> e, o
        // o -> i
        // u -> o, i

        for(int i = 2; i <= n; i++) {
            long long nextA = (prevE + prevU + prevI) % MOD;
            long long nextE = (prevA + prevI) % MOD;
            long long nextI = (prevE + prevO) % MOD;
            long long nextO = (prevI) % MOD;
            long long nextU = (prevO + prevI) % MOD;

            prevA = nextA;
            prevE = nextE;
            prevI = nextI;
            prevO = nextO;
            prevU = nextU;
        }

        return (prevA + prevE + prevI + prevO + prevU) % MOD;
    }
};