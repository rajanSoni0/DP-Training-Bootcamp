#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    vector<string> ans;
    string p = "DLRU";
    vector<vector<int>> dir = {{1,0},{0,-1},{0,1},{-1,0}};
    
    bool isSafe(int x, int y, int n,
                vector<vector<int>>& maze,
                vector<vector<bool>>& vis) {
        return (x >= 0 && x < n &&
                y >= 0 && y < n &&
                maze[x][y] == 1 &&
                !vis[x][y]);
    }
    
    void backTrack(vector<vector<int>>& maze,
                   vector<vector<bool>>& vis,
                   int i, int j, int n,
                   string& path) {
        if(i == n-1 && j == n-1) {
            ans.push_back(path);
            return;
        }
        
        for(int k = 0; k < 4; k++) {
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            
            if(isSafe(x, y, n, maze, vis)) {
                vis[x][y] = true;
                path.push_back(p[k]);
                backTrack(maze, vis, x, y, n, path);
                path.pop_back();
                vis[x][y] = false;
            }
        }
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        ans.clear();
        
        if(maze[0][0] == 0 || maze[n-1][n-1] == 0)
            return {};
        
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        string path = "";
        
        vis[0][0] = true;
        backTrack(maze, vis, 0, 0, n, path);
        
        return ans;
    }
};
