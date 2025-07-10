class MyQueue {
public:
    stack<int>input,output;
    MyQueue() {
        
    }
    
    void push(int x) {
        
        while(!input.empty())
        {
            output.push(input.top());
            input.pop();
        }

        input.push(x);
        while(!output.empty())
        {
            input.push(output.top());
            output.pop();
        }


    }
    
    int pop() {
        int r=input.top();
        input.pop();

        return r;
    }
    
    int peek() {
        
        return input.top();
    }
    
    bool empty() {
        return input.empty();;
    }
};