#include <bits/stdc++.h>
using namespace std;


int smallestMaxDifference(vector<int>& arr, int N, int K)  {
    multiset<int> window;
    int minMaxDiff = INT_MAX;
    for(int i=0;i<K;i++){
        window.insert(arr[i]);
    }
    minMaxDiff = min(minMaxDiff, *window.rbegin() - *window.begin());
    for(int i=K;i<N;i++){
         window.erase(window.find(arr[i - K]));
         window.insert(arr[i]);
         minMaxDiff = min(minMaxDiff, *window.rbegin() - *window.begin());
    }
   return minMaxDiff;
}

int main() {
    int N, K;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cin >> K;

    cout << smallestMaxDifference(arr, N, K) << endl;
    return 0;
}