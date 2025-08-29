class Solution {
private:
    
    bool isSafe(vector<vector<int>>& maze, vector<vector<int>> &visited,
                int n, int newx, int newy){

        if(newx >= 0 && newx < n && newy >= 0 && newy < n){
            if(maze[newx][newy] == 1 && visited[newx][newy] == 0){
                return true;
            }
        }
        return false;
    }
    
    void solve(vector<vector<int>>& maze,int n, vector<string>& ans,
            vector<vector<int>> &visited,int srcx, int srcy, string &path){
        
        if(srcx == n-1 && srcy == n-1){
            ans.push_back(path);
            return;
        }
        
        visited[srcx][srcy] = 1;
        
        // Down
        int newx = srcx + 1;
        int newy = srcy;
        if(isSafe(maze, visited, n, newx, newy)){
            path.push_back('D');
            solve(maze, n, ans, visited, newx, newy, path);
            path.pop_back();
        }
        
        // Right
        newx = srcx;
        newy = srcy + 1;
        if(isSafe(maze, visited, n, newx, newy)){
            path.push_back('R');
            solve(maze, n, ans, visited, newx, newy, path);
            path.pop_back();
        }
        
        // Up
        newx = srcx - 1;
        newy = srcy;
        if(isSafe(maze, visited, n, newx, newy)){
            path.push_back('U');
            solve(maze, n, ans, visited, newx, newy, path);
            path.pop_back();
        }
        
        // Left
        newx = srcx;
        newy = srcy - 1;
        if(isSafe(maze, visited, n, newx, newy)){
            path.push_back('L');
            solve(maze, n, ans, visited, newx, newy, path);
            path.pop_back();
        }
        
        visited[srcx][srcy] = 0;
    } 
    

public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        
        vector<string> ans;
        int n = maze.size();
        
        if(maze[0][0] == 0){
            return ans;
        }
        
        vector<vector<int>> visited(n, vector<int>(n, 0));
        string path = "";
        
        solve(maze, n, ans, visited, 0, 0, path);
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
