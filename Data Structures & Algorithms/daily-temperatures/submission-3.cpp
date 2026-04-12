class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      stack<pair<int , int>> st;
      vector<int> ans(temperatures.size() , 0); 
      for(int i = 0; i < temperatures.size() ;i++){
        int temp = temperatures[i];
        while(!st.empty() && temp > st.top().first ){
            ans[st.top().second] = i - st.top().second;
            st.pop();
        }
        st.push({temp , i});
      } 
      return ans; 
    }
};