class Solution {
public:
    int minAddToMakeValid(string s) {
    int op=0,cl=0;
    for(auto x:s){
        if(x=='('){
            op++;
        }else{
            if(op==0){
                cl++;
            }else{
                op--;
            }
        }
    }
    return cl+op; 
    }
};