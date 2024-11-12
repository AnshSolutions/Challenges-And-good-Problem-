#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
   int findmaxbeauty(const vector<vector<int>>& items, int maxp) {
        int left = 0, right = items.size() - 1;
        int max_index = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (items[mid][0] <= maxp) {
                max_index = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (max_index == -1) return 0;

        int max_beauty = 0;
        for (int i = 0; i <= max_index; ++i) {
            max_beauty = max(max_beauty, items[i][1]);
        }

        return max_beauty;
    }

    vector<int> solve(vector<vector<int>>& items, vector<int>& queries) {
        int n = queries.size();
        sort(items.begin(), items.end());
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int maxprice = queries[i];
            ans[i] = findmaxbeauty(items, maxprice);
        }
        return ans;
    }
};
int main() {
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        vector<vector<int>>arr(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;i<n;j++){
                cin>>arr[m][n];
            }
    }
    int s;
    vector<int>q(s);
    for(int i=0;i<s;i++){
        cin>>q[i];
    }
    Solution sol;
     vector<int>ans=sol.solve(arr,q);
     for(int i=0;i<s;i++){
        cout<<ans[i]<<" ";
     }
     cout<<endl;
    }
}