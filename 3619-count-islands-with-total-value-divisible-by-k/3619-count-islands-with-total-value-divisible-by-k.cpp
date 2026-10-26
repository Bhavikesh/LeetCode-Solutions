class Solution {
public:
    int m,n;

    long long dfs(vector<vector<int>>& grid, int i, int j, long long  &sum){
        if(i<0 || i>=m || j<0 || j>=n) return 0;

        if(grid[i][j] == 0) return 0;

        sum += grid[i][j];
        grid[i][j]=0;

        int left = dfs(grid, i, j-1, sum);
        int right = dfs(grid, i, j+1, sum);
        int up = dfs(grid, i-1, j, sum);
        int down = dfs(grid, i+1, j, sum);

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] != 0){
                long long  sum = 0;
                    if(dfs(grid, i, j, sum)%k == 0){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};