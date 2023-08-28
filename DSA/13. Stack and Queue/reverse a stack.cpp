#include <bits/stdc++.h> 
void reverse(stack<int> &stack, int num){
    if(stack.empty()){
        stack.push(num);
        return;
    }
    int temp = stack.top();
    stack.pop();
    reverse(stack,num);
    stack.push(temp);
}
void reverseStack(stack<int> &stack) {
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();
    reverseStack(stack);
    reverse(stack, num);
}