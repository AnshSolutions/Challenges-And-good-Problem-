#include<bits?stdc++.h>
using namespace std;

    class Solution {
   public:
    vector<int> solve(vector<int>& nums, int maximumBit) {
          int n=nums.size();
           vector<int>zorprefix(n,0);
           int  ans=0;
           for(int i=0;i<n;i++){
             ans^=nums[i];
             zorprefix[i]=ans;
           }
           int a=pow(2,maximumBit);
           vector<int>res;
           for(int i=zorprefix.size()-1;i>=0;i--){
              res.push_back((a-1)^zorprefix[i]);
           }
           return res;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, maxbits;
        cin>>n>>maxbits;
       
         
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        Solution sol;
        vector<int>ans=sol.solve(nums,maxbits);
        for(auto val:ans){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}