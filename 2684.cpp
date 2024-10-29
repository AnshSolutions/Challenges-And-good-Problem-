#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& v, int i, int j, int mr, int mc, int prev) {
    if (i < 0 || i >= mr || j >= mc || v[i][j] <= prev) {
        return 0;
    }

    int a1 = solve(v, i - 1, j + 1, mr, mc, v[i][j]);
    int a2 = solve(v, i + 1, j + 1, mr, mc, v[i][j]);
    int a3 = solve(v, i, j + 1, mr, mc, v[i][j]);

    return 1 + max({a1, a2, a3});
}

int main()
{
   int t;
   cin>>t;
   while(t--){
      int mr,mc;
      cin>>mr>>mc;
      vector<vector<int>>v(mr,vector<int>(mc));
       for(int i=0;i<mr;i++){
        for(int j=0;j<mc;j++){
            cin>>v[i][j];
         }
      }
      int ans=INT_MIN;
      for(int i=0;i<mr;i++){
        ans=max(ans,solve(v,i,0,mr,mc,INT_MIN));
       }
    cout<<ans-1<<endl;
   }
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<vector<int>>& grid, int r, int c, int currcol, int currrow, int prev) {
        if (currrow < 0 || currrow >= r || currcol >= c || grid[currrow][currcol] <= prev) {
            return 0;
        }
        if (dp[currrow][currcol] != -1) {
            return dp[currrow][currcol];
        }

        int a1 = solve(grid, r, c, currcol + 1, currrow - 1, grid[currrow][currcol]);
        int a2 = solve(grid, r, c, currcol + 1, currrow + 1, grid[currrow][currcol]);
        int a3 = solve(grid, r, c, currcol + 1, currrow, grid[currrow][currcol]);
        
        return dp[currrow][currcol] = 1 + max({a1, a2, a3});
    }

    int maxMoves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        dp.assign(r, vector<int>(c, -1));

        int maxi = INT_MIN;
        for (int i = 0; i < r; i++) {
            maxi = max(maxi, solve(grid, r, c, 0, i, INT_MIN));
        }
        return maxi - 1;
    }
};
