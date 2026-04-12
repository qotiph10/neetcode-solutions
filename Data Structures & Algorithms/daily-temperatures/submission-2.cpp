class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans(temperatures.size() , 0);
        stack<pair<int , int>> st;
        int i = 1;
        st.push({temperatures[0] , 0});
        while(i < temperatures.size()){
            int c = temperatures[i];
            while(!st.empty() && c > st.top().first){
                auto pair = st.top();
                st.pop();
                ans[pair.second] = i - pair.second;
            }
            st.push({c , i});
            i+=1;
        }
        return ans;
    }
};