class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n , 0);
        stack<pair<int , int>> temps;
        for(int i =0 ; i< n ;i++){
            int temp = temperatures[i];
            if(temps.size()){
                if(temps.top().first < temp){
                    while(temps.size() && temps.top().first < temp){
                        cout << temp << " > " << temps.top().first << endl; 
                        ans[temps.top().second] = i - temps.top().second;
                        temps.pop();
                    }
                    temps.push({temp , i});
                }
                else{
                   temps.push({temp , i}); 
                }
            }
            else{
                temps.push({temp , i});
            }
        }
        return ans;
    }
};
