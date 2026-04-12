class Solution {
public:
    vector<int> finished; 
    unordered_map<int , vector<int>> preMap;
    unordered_set<int> visted;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i =0 ; i< numCourses ;i++){
            preMap[i] = {};
        }
        for(const auto& p : prerequisites){
            preMap[p[0]].push_back(p[1]);
        }
        for(int i =0 ; i< numCourses ;i++){
            if(!dfs(i)){
                return {};
            }
        }
        return finished;
    }
    bool dfs(int i){
        if(visted.count(i)){
            return false;
        }
        if(preMap[i].empty()){
            if(!(find(finished.begin(), finished.end(), i) != finished.end())){
                finished.push_back(i);
            }
            return true;
        }

        visted.insert(i);
        for(int j = 0 ; j < preMap[i].size() ;j++){
            if(!dfs(preMap[i][j])){
                return false;
            }
        }
        visted.erase(i);
        preMap[i].clear();
        if(!(find(finished.begin(), finished.end(), i) != finished.end())){
            finished.push_back(i);
        }
        return true;
    }
};
