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
        int x;
        if(output.empty()==false){
            x = output.top();    
            output.pop();
            return x;
        }
        else{
            while(input.empty()==false){
                output.push(input.top());
                input.pop();
            }
            x = output.top();
            output.pop();
            return x; 
        }   
    }
    
    int peek() {
        if(output.empty()==false)
            return output.top();
        else{
            while(input.empty()==false){
                output.push(input.top());
                input.pop();
            }
           
            return output.top();
        }   
    }
    
    bool empty() {
        return output.empty() && input.empty() ;
    }
};
