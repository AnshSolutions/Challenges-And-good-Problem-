#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
    // Input format
    // The first line contains two space-separated integers N and K
    int N, K;
    cin >> N >> K;
    
    vector<int> arr(N);
    for (int i = 0; i < N; i++) arr[i] = i + 1; 

    while (K-- && !arr.empty()) {
        vector<int> temp;
        for (int i = 0; i < arr.size(); i++) {
            if ((i % 3) != 0) temp.push_back(arr[i]);
        }
        arr = temp;
    }

    long long sum = 0;
    for (int num : arr) sum = (sum + num) % MOD;

    cout << sum << endl;
    return 0;
}

/*
Sample Test Cases:

Input 1:
10 10

Output 1:
0

Input 2:
10 2

Output 2:
25
*/
