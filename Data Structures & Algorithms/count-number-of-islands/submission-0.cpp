class Solution {
public:
    void bfs(vector<vector<char>>& grid , int i , int j){
    if(grid[i][j] == '1'){
        grid[i][j] = '0'; 
        vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , 1} , {0 , -1}};
        for(auto d : directions){
            int r = i + d[0] , c = j + d[1];
            if(r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size()){
                bfs(grid , r , c );
            }
        }
    }
    else{
        return;
    }
}
int numIslands(vector<vector<char>>& grid) {
    if(!grid.size()){
        return 0;
    }
    int ans = 0;
    for(int i =0 ; i < grid.size() ;i++){
        for(int j = 0; j< grid[0].size() ; j+=1){
            if(grid[i][j] == '1'){
                bfs(grid ,i , j);
                ans+=1;
            }
        }
    }
    return ans;
}
};
