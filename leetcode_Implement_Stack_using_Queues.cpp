class MyStack {
private:
    queue<int> q1;
public:

    MyStack() {
        ;
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
       int n=q1.size()-1;
       int top;
       while(n--){
           top=q1.front();
           q1.pop();
           q1.push(top);
       }
       top=q1.front();
       q1.pop();
       return top;
        
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {        
        if(q1.empty())return true;
       
        return false;
    }
};



/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */