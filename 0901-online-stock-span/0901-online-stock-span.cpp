class StockSpanner {
    stack<pair<int, int>> st;  // price, span
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int currSpan = 1;
        while(st.size() > 0 && st.top().first <= price ) {
            auto [prevPrice, span] = st.top();
            st.pop();
            
            currSpan += span;
        }
        st.push({price, currSpan});
        return currSpan;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */