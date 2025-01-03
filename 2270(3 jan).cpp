#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pre(n, 0);
        long long ts = nums[0];
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            ts += nums[i];
            pre[i] = pre[i - 1] + nums[i];
        }
        int c = 0;
        for (int i = 0; i < n - 1; i++) {
            long long currsum = pre[i];
            long long remsum = ts - currsum;
            if (currsum >= remsum) {
                c++;
            }
        }
        return c;
    }
    //gfg code
    long subarrayXor(vector<int> &arr, int k) {
       long long ans=0;
       long long curr=0;
       unordered_map<int,int>mp;
       for(auto a:arr){
           curr^=a;
           if(curr==k)ans++;
           if(mp.find(curr^k)!=mp.end()){
               ans+=mp[curr^k];
           }
           mp[curr]++;
       }
       return ans;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Input handling
    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int n;
        cin >> n; // Size of the array
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        int k;
        cin>>k;
        
        // Solution object
        Solution sol;
        cout << sol.waysToSplitArray(nums) << "\n";
        cout << sol.subarrayXor(nums,k) << "\n";
    }
    return 0;
}
