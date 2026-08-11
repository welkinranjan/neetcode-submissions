class MinStack {
public:

    stack<int> st,minst;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty() || minst.top()>val){
            minst.push(val);
        }
        else{
            minst.push(minst.top());
        }
        st.push(val);
    }
    
    void pop() {
        minst.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
