#include<bits/stdc++.h>
using namespace std;
class solution{
public:
    long long solve(int n, int x) {
               // if(n==1)return x;
        // int count = 1;
        // int ans = x;
        // for (long long i = x + 1; i < pow(10, 8); i++) {
        //     if ((x & i) == x) {
        //         ans = i;
        //         count++;
        //         if (count == n) {
        //             return ans;
        //         }
        //     }
        // }
        // return ans;
      long long   num=x;
     for(int i=1;i<n;i++){
       num=(num+1)|x;
     }
     return num;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
       solution sol;
        cout << sol.solve(n, x) << endl;
    }
    return 0;
}