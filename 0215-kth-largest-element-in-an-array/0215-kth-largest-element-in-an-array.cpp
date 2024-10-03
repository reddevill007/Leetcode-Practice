class Solution {
    // void print_priority_queue(priority_queue<int, vector<int>, greater<int>> pq) {
    //     cout << "[ ";
    //     while (!pq.empty()) {
    //         cout << pq.top() << " ";
    //         pq.pop();
    //     }
    //     cout << "]" << endl;
    // }

public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it: nums) {
            pq.push(it);
            // print_priority_queue(pq);
            if(pq.size() > k) {
                pq.pop();
                // print_priority_queue(pq);
            }
        }
        // for(int i = 0; i < k - 1; i++) pq.pop();
        cout << "returning " << pq.top() << endl;
        return pq.top();
    }
};