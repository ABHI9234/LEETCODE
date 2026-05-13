class MyStack {
public:
    queue<int> q;

    MyStack() {}
    
    // O(n) time: Every push re-arranges the queue
    void push(int x) {
        q.push(x);
        int sz = q.size();
        
        // Rotate the queue: take elements from the front and 
        // put them at the back until the new element 'x' is at the front
        for(int i = 0; i < sz - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    // O(1) time
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    // O(1) time
    int top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};