#include<bists/stdc++.h>
using namespace std;
class solution {
    public:
     int solve(vector<int>& candidates) {
        vector<int> bitnumber(24, 0);
        for (int i = 0; i < 24; i++) {
            for (auto num : candidates) {
                if ((num & (1 << i)) != 0) {
                    bitnumber[i]++;
                }
            }
        }
        return *max_element(bitnumber.begin(), bitnumber.end());
    }

};
int manin(){
   int t;
    cin >> t;
    
    while (t--) {
        Solution solution;
        int n;
        cin >> n;
        vector<int> candidates(n);
        
        for (int i = 0; i < n; i++) {
            cin >> candidates[i];
        }
        
        cout << solution.solve(candidates) << endl;
    }
    
    return 0;
}