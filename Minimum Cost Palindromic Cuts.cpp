// Minimum Cost Palindromic Cuts
// \\
// You are given a string S of length N, consisting of lowercase English letters. Your task is to partition the string 
// into the minimum number of palindromic substrings while also minimizing the cost of partitioning.
// The cost of partitioning is defined as the sum of ASCII values of the characters at both ends of each cut. 
// If multiple ways exist to achieve the minimum number of palindromic partitions, select the one with the lowest cost.
// Return the minimum cost required to partition the string. If the string is already a palindrome, return 0.
#include <bits/stdc++.h>
using namespace std;

bool ispal(const string &S, int l, int r) {  // Accept const reference
    while (l < r) {
        if (S[l] != S[r]) return false;
        l++, r--;
    }
    return true;
}

int min_partition_cost(const string &S, int l, int r) {  // Accept const reference
    if (l >= r || ispal(S, l, r)) {
        return 0;
    }

    int mincost = INT_MAX;

    for (int i = l; i < r; i++) {
        if (ispal(S, l, i)) {  
            int cost = S[i] + S[i + 1] + min_partition_cost(S, i + 1, r);
            mincost = min(mincost, cost);
        }
    }

    return mincost;
}

int main() {
    string S;
    getline(cin, S);
    int result = min_partition_cost(S, 0, S.size() - 1);
    cout << result << endl;
    return 0;
}
