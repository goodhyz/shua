#include<vector>
using namespace std;

class Node {
    public:
    Node(int i,int j){
        val =i;
        presentMin = j;

    }
    int val;
    int presentMin;
};

class MinStack {
    private:
    vector<Node> stack1;
  public:
    MinStack() {
       stack1.clear();
    }

    void push(int val) {
        if(stack1.empty()){
            // Node cur(val,val);
            stack1.push_back(Node(val,val));
        }else{
            auto node = stack1.back();
            int minVal = min(node.presentMin,val);
            stack1.push_back(Node(val,minVal));
        }
    }

    void pop() {
        stack1.pop_back();
    }

    int top() {
        return stack1.back().val;
    }

    int getMin() {
        return stack1.back().presentMin;
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