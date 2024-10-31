#include<bits/stdc++.h>
using namespace std;
long long calculate(int idx, int fidx, vector<int> &fact, vector<int> &robot, vector<vector<long long>> &dp) {
    if (idx == robot.size()) return 0;
    if (fidx == fact.size()) return 1e12;
    if (dp[idx][fidx] != -1) return dp[idx][fidx];
    long long assign = abs(robot[idx] - fact[fidx]) + calculate(idx + 1, fidx + 1, fact, robot, dp);
    long long skip = calculate(idx, fidx + 1, fact, robot, dp);
    return dp[idx][fidx] = min(assign, skip);
}
long long mindist(vector<int> &robot, vector<vector<int>> &factory) {
    sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end());
    vector<int> fact;
    for (auto &f : factory) {
        for (int j = 0; j < f[1]; j++) fact.push_back(f[0]);
    }
    vector<vector<long long>> dp(robot.size() + 1, vector<long long>(fact.size() + 1, -1));
    return calculate(0, 0, fact, robot, dp);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<int>robot(n) ;
        for(int i=0;i<n;i++){
            cin >> robot[i];
        }
        vector<vector<int>>factory(m,vector<int>(2));
        for(int i=0;i<m;i++){
            cin>>factory[i][0]>>factory[i][1];
        }
        cout<<mindist(robot,factory)<<endl;
    }
    return 0;
}