class Solution {
    int getLength(int num) {
        int length = 0;
        while (num > 0) {
            num /= 10;
            length++;
        }
        return length;
    }

    

public:
    vector<int> sequentialDigits(int low, int high) {
        int lowLength = getLength(low);
        int highLength = getLength(high);

        set<int> res;

        for (int length = lowLength; length <= highLength; length++) {
            for (int firstDigit = 1; firstDigit <= 9; firstDigit++) {
                int num = 0;
                int currDigit = firstDigit;
                for (int i = 0; i < length; i++) {
                    num = num * 10 + currDigit;
                    if (num > high) break;
                    if (num >= low) res.insert(num);
                    currDigit++;
                    if (currDigit > 9) break;
                }
            }
        }

        vector<int> result;

        for(auto it: res) {
            result.push_back(it);
        }

        return result;
    }
};