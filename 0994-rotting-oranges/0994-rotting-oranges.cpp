class Solution {
public:

    bool isSafe(int x, int y, int n, int m){
        return x>=0 && x<n && y>=0 && y<m;
    }

    void solve(vector<vector<int>>& grid, int x, int y, int n, int m, int time, vector<vector<int>>& dist){
        if(!isSafe(x,y,n,m) || grid[x][y]==0){
            return;
        }

        if(time >= dist[x][y]) return;

        dist[x][y] = time;

        // up
        solve(grid, x, y-1, n, m, time+1, dist);

        // down
        solve(grid, x, y+1, n, m, time+1, dist);

        // right
        solve(grid, x+1, y, n, m, time+1, dist);

        // left
        solve(grid, x-1, y, n, m, time+1, dist);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m,INT_MAX));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    solve(grid,i,j,n,m,0,dist);
                }
            }
        }

        int maxi = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    if(dist[i][j] == INT_MAX)
                        return -1;

                    maxi = max(maxi, dist[i][j]);
                }
            }
        }

        return maxi;
    }
};

