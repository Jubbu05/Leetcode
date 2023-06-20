class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        int rightSmall[n]; 
        int leftSmall[n]; 
        
        stack<int> st;

        //store the index of the next smaller element on the left
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                st.pop();
            }
            leftSmall[i] = (st.empty()) ? 0 : st.top() + 1;
            //we are pushing index
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        //store the index of the next smaller element on the right
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            rightSmall[i] = (st.empty()) ? n-1 : st.top() - 1;
            st.push(i);
        }
        
        int maxArea= 0;
        for(int i= 0; i<n; i++)
            maxArea= max(maxArea, heights[i]*(rightSmall[i]- leftSmall[i] + 1));
        
        return maxArea;
    }
};