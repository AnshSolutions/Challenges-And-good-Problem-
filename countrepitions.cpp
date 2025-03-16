// Bob starts with a string S. Each day, he appends the initial string S to the end of the string he currently 
// has. For example, if S is “xyz”:
// On the first day, the string remains “xyz”.
// On the second day, the string becomes “xyzxyz”.
// On the third day, the string becomes “xyzxyzxyz”.
// Alice has another string T. She wants to know on which day her string T will first appear as a subsequence in Bob’s string.
// To determine this, we need to find the smallest day D such that T is a subsequence of the string Bob has on day D.
// Input Format
// The first line of the input contains Bob's string S.
// The second line of the input contains Alice's string T.
#include <iostream>
#include <string>
using namespace std;

int number_of_days_when_subsequence(string S, string T) {
    int j = 0, D = 1, n = S.size();
    string temp = S;
// What (D - 1) * n is doing?
// When we reach Day D,
// The previous day was Day (D-1),
// So, we start checking from index (D-1) * n
// because before that, we have already checked.
    while (true) {
        for (int i = (D - 1) * n; i < S.size(); i++) {
            if (S[i] == T[j]) {
                j++;
            }
            if (j >= T.size()) {
                return D;
            }
        }
        D += 1;
        S += temp; // Append S again for the next day
    }

    return D;
}

int main() {
    string S, T;
    cin >> S >> T;
    int result = number_of_days_when_subsequence(S, T);
    cout << result << endl;
    return 0;
}
