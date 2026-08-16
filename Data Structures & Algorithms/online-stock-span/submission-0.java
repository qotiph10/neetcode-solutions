class StockSpanner {
    Stack<Integer> st = new Stack<>();
    public StockSpanner() {
        
    }
    
    public int next(int price) {
        st.push(price);
        Stack<Integer> stTemp = new Stack<>();
        stTemp.addAll(st);
        int c = 0;
        while(!stTemp.isEmpty() && stTemp.peek() <= price){
            c+=1;
            stTemp.pop();
        }
        return c;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */