class StockSpanner {
    stack<pair<int,int>> st;
    int day;
public:
    StockSpanner() {
        day = 0;
    }
    
    int next(int price) {
        day++;
        int today = day;
        while(!st.empty() && st.top().first <= price){
            today = st.top().second;
            st.pop();
        } 
        st.push(make_pair(price, today));
        return - today + day + 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
