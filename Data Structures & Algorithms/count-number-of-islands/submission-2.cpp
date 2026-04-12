class Solution {
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    void dfs(vector<vector<char>>& grid , int col , int row){
        if(grid[col][row] == '0'){
            return;
        }

        grid[col][row] = '0';

        int rowSize , colSize;
        rowSize = grid[0].size();
        colSize = grid.size();
        cout<<"("<<col<<","<<row<<") Cleard!"<<endl;

        for(int i = 0 ; i< 4;i++){

            int newCol = col + dir[i][0];
            int newRow = row + dir[i][1];
            if(newCol >= 0 && newRow >= 0 && newCol < colSize && newRow < rowSize){
                dfs(grid , newCol , newRow);
            } 

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size()){
            return 0;
        }

        int ans =0;
        for(int i =0 ; i< grid.size();i++){
            for(int j = 0; j< grid[0].size();j++){
                if(grid[i][j]=='1'){
                    dfs(grid , i  ,j);
                    ans+=1;
                }
            }
        }
        for(int i =0 ; i< grid.size();i++){
            for(int j = 0; j< grid[0].size();j++){
                cout<<grid[i][j] << " ";
            }
            cout<<endl;
        }
        return ans;
    }
};
