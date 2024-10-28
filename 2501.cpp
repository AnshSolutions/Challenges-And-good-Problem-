#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int solve(vector<int>&nums){
        int ans=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(auto a:nums){
            int cs=0;
            int curr=a;
            while(binary_search(nums.begin(),nums.end(),curr)){
                cs++;
                curr=curr*curr;

            }
            ans=max(ans,cs);
        }
            return ans>=2?ans:-1;

}
};
int main() {
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution sol;
    cout<<sol.solve(nums)<<endl;
    return 0;
}