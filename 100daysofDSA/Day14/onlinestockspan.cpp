class StockSpanner {
public:
    stack<pair<int,int>> st;
        int k;
    StockSpanner() {
   k=1;
    }
    
    int next(int price) {
        while(!st.empty() && st.top().second<=price)
            st.pop();
        
        int span=0;
        if(st.empty())
            span = k;
        else
            span =k-st.top().first;
            
        st.push({k,price});
        k++;
        return span;
        
    }
};
