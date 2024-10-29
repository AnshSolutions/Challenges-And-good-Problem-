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