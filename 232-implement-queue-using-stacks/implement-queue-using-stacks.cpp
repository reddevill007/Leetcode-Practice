class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty() && input.empty()) {
            return -1;
        }
        if(!output.empty()) {
            int top = output.top();
            output.pop();
            return top;
        }

        else {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            int top = output.top();
            output.pop();
            return top;
        }
    }
    
    int peek() {
        if(output.empty() && input.empty()) {
            return -1;
        }
        if(!output.empty()) {
            int top = output.top();
            return top;
        }

        else {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
    }
    
    bool empty() {
        return output.empty() && input.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */