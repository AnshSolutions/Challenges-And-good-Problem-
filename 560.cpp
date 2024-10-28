#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0;
        int sum = 0;
        
        for (int num : nums) {
            sum += num;
            int diff = sum - k;
            if (mp.find(diff) != mp.end()) {
                count += mp[diff];
            }
            mp[sum]++;
        }
        
        return count;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    Solution sol;
    cout << sol.subarraySum(nums, k) << endl;
    
    return 0;
}
