class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if (aux_st.empty()) {
            aux_st.push(val);
        } else {
            aux_st.push(std::min(val, aux_st.top()));
        }
    }
    
    void pop() {
        st.pop();
        aux_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return aux_st.top();
    }
private:
    std::stack<int> st;
    std::stack<int> aux_st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
