// **Problem Statement: Continuous Median Sum**

// You are given an array of **N** integers. Your task is to compute the sum of all **medians** formed by continuously selecting symmetric elements around the middle of the sorted array.

// ### **Definition of the Sum of Medians:**
// 1. **Sort the array** in non-decreasing order.
// 2. **Find the middle element(s):**  
//    - If \( N \) is **odd**, the median is the middle element.  
//    - If \( N \) is **even**, the median is the average of the two middle elements.  
// 3. **Expand symmetrically:**  
//    - Select pairs of elements **left** (`i`) and **right** (`j`) from the center.
//    - Add to the sum using the formula:  
//      \[
//      \left( \frac{{arr[i] + arr[j]}}{2} \right) + \max(arr[i], arr[j])
//      \]
//    - Continue until all elements are used.

// ### **Input Format:**
// - The first line contains a single integer **N** \((1 \leq N \leq 10^5)\) — the size of the array.
// - The second line contains **N** space-separated integers **A[i]** \((1 \leq A[i] \leq 10^9)\).

// ### **Output Format:**
// - Print a single integer — the **sum of all computed medians**.

// ### **Example 1**
// #### **Input**
// ```
// 4
// 1 2 3 4
// ```
// #### **Processing Steps**
// - Sorted array: **[1, 2, 3, 4]**
// - Middle: **Median = (2, 3)**
// - Pairs formed:  
//   - (2,3) → **(2+3)/2 + max(2,3) = 2 + 3 = 5**
//   - (1,4) → **(1+4)/2 + max(1,4) = 2 + 4 = 6**
// - Sum = **5 + 6 = 11**

// #### **Output**
// ```
// 11
// ```

// ### **Example 2**
// #### **Input**
// ```
// 5
// 3 1 4 1 5
// ```
// #### **Processing Steps**
// - Sorted array: **[1, 1, 3, 4, 5]**
// - Middle: **Median = 3**
// - Pairs formed:
//   - Single middle element: **3**
//   - (1,4) → **(1+4)/2 + max(1,4) = 2 + 4 = 6**
//   - (1,5) → **(1+5)/2 + max(1,5) = 3 + 5 = 8**
// - Sum = **3 + 6 + 8 = 17**

// #### **Output**
// ```
// 17
// ```

// ---

// ### **CodeChef Style C++ Solution**
// ```cpp
#include <bits/stdc++.h>  // Universal library for competitive programming
using namespace std;

typedef long long ll;  // Typedef for long long

int main() {
    ll n;  
    cin >> n;
    
    vector<ll> arr(n);
    for (ll i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());  // Sort the array

    ll ans = 0;
    ll i = n / 2;  // Mid index
    ll j = n / 2;
    i--;  // Move left pointer
    
    if (n & 1) j++;  // If odd, right pointer moves forward
    if (n & 1) ans += arr[n / 2];  // If odd, add the middle element
    
    while (i >= 0 && j < n) {
        ans += (((arr[i] + arr[j]) / 2) + max(arr[i], arr[j]));
        i--, j++;  
    }
    
    cout << ans << endl;
    return 0;
}


