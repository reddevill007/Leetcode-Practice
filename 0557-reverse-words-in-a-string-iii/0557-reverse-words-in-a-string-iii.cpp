class Solution {
public:
    string reverseWords(string s) {
        int lastspaceIndex = -1;
        int len = s.length();

        for(int i = 0; i <= len; i++) {
            if(i == len || s[i] == ' ') {
                int left = lastspaceIndex + 1;
                int right = i - 1;

                while(left < right) {
                    char temp = s[left];
                    s[left] = s[right];
                    s[right] = temp;
                    left++;
                    right--;
                } 

                lastspaceIndex = i;
            }
        }

        return s;
    }
};