class Solution {
public:
    unordered_map<int , vector<int>> node;
unordered_set<int> visiting, visited;
vector<int> ans;

bool dfs(int i){
    if(visiting.count(i)) return false;  // cycle detected
    if(visited.count(i)) return true;    // already processed
    
    visiting.insert(i);
    for(int j: node[i]){
        if(!dfs(j)) return false;
    }
    visiting.erase(i);
    visited.insert(i);
    ans.push_back(i);
    return true;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    for(auto& p: prerequisites){
        node[p[1]].push_back(p[0]); // correct direction
    }
    
    for(int i = 0; i < numCourses; i++){
        if(!dfs(i)){
            return {}; // cycle detected
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

};
