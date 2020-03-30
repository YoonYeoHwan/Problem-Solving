class Solution {
public:
    int maximum_area = 0;
    vector<int> start{0, 0};
    
    int dfs(int row, int column, vector<vector<int>>& island, vector<vector<bool>>& check) {
        if(row < 0 || column < 0 || row >= island.size()
           || column >= island[0].size() || island[row][column] == 0
           || check[row][column] == true) return 0;
        
        check[row][column] = true;
        
        return dfs(row + 1, column, island, check) +
            dfs(row - 1, column, island, check) +
            dfs(row, column + 1, island, check) +
            dfs(row, column - 1, island, check) + 1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> check(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                start[0] = i; start[1] = j;
                if(grid[i][j] == 1 && check[i][j] == false) {
                    int tmp = dfs(i, j, grid, check);
                    maximum_area = tmp > maximum_area ? tmp : maximum_area;
                }
            }
        }
        return maximum_area;
    }
};
