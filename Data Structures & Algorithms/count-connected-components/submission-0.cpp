class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int , vector<int>> map;
        unordered_set<int> visted;
        for(const auto item : edges){
            map[item[0]].push_back(item[1]);
            map[item[1]].push_back(item[0]);
        }
        int ans = 0;
        for(int i =0 ; i< n ;i++){
            if(!visted.count(i)){
                /* for(auto x : visted){
                    cout << x << " " ;
                } */
                dfs(i , map , visted);
                cout << "count up ! :" << ans << endl;
                ans+=1;
            }
        }
        return ans;
    }

    void dfs(int i , unordered_map<int,vector<int>>& map,unordered_set<int>& visted ){
        if(visted.count(i)){
            return;
        }
        visted.insert(i);
        cout << " i: " << i << endl;
        for(const auto& item: map[i]){
            dfs(item , map , visted);
        }
    }
};
