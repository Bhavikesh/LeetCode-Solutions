class Solution {
public:
    int memo[101][101][201];
    bool isSafe(int x, int y, int n, int m, vector<vector<bool>> &visited, vector<vector<char>> &grid){
        if((x>=0 && x<n) && (y>=0 && y<m) && visited[x][y]==false) return true;
        return false;
    }

    bool solve(int x, int y, int n, int m, vector<vector<char>>& grid, vector<vector<bool>> &visited, int depth){
        depth += grid[x][y]=='('?1:-1;

        if(depth < 0){
            return false;
        }

        if(x==n-1 && y==m-1){
            return depth==0;
        }


        int remaining = (n-1-x)+(m-1-y);

        if(depth > remaining) return false;

        if(memo[x][y][depth] != -1){
            return memo[x][y][depth];
        }

        visited[x][y] = true;
        bool down = false;
        bool right = false;

        // down
        int nx = x+1;
        int ny = y;
        if(isSafe(nx, ny, n, m, visited, grid)){
            down = solve(nx, ny, n, m, grid, visited, depth);
        }


        // right
        nx = x;
        ny = y+1;
        if(!down && isSafe(nx, ny, n, m, visited, grid)){
            right = solve(nx, ny, n, m, grid, visited, depth);
        }

        visited[x][y] = false;

        return memo[x][y][depth] = down || right;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m,false));

        if(grid[0][0]==')' || grid[n-1][m-1]=='(') return false;

        memset(memo, -1, sizeof(memo));
        int depth = 0;

        return solve(0 , 0, n, m, grid, visited, depth);

    }
};