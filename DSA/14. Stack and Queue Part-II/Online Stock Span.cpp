class StockSpanner {
public:
    stack<pair<int, int>> st; //price, span
    StockSpanner() {
        
    }
    int next(int price) {
        int span = 1; //min all element have span of 1 i.e itself
        while(!st.empty() && st.top().first <= price){
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};