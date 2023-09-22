class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        vector<int> leftSmall(n);
        vector<int> rightSmall(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(st.empty()) {
                leftSmall[i] = 0;
            } else {
                leftSmall[i] = st.top() + 1;
            }
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }
        

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(st.empty()) {
                rightSmall[i] = n - 1;
            } else {
                rightSmall[i] = st.top() - 1;
            }
            st.push(i);
        }

        for(int i = 0; i < n; i++) {
            int area = (heights[i] * (rightSmall[i] -leftSmall[i] + 1));
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};