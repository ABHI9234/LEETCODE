class MinStack {
public:
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        int x = INT_MAX;
        stack<int> temp;
        while(st.size()>0){
            x = min(x,st.top());
            temp.push(st.top());
            st.pop();
        }
        while(temp.size()>0){
            st.push(temp.top());
            temp.pop();
        }
        return x;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */