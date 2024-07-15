#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> P(N, 0);
    vector<int> sums(N + 1, 0);

    sums[0] = 0;

    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    //»ðÀÔ Á¤·Ä
    
    for (int i = 1; i < N; ++i){
    
        int target = i;
        int value = P[i];

        for (int j = i - 1; j >= 0; --j) {

            if (P[j] < P[i]) {
                target = j + 1;
                break;
            }

            if (j == 0) {
                target = 0;
            }

        }

        for (int k = i; k > target; --k) {

            P[k] = P[k  - 1];

        }

        P[target] = value;
    
    }


   // sort(P.begin(), P.end(), less<int>());

    for (int i = 1; i < N + 1; ++i) {

        sums[i] = sums[i - 1] + P[i - 1];

    }

    cout << accumulate(sums.begin(), sums.end(), 0);

    return 0;
}