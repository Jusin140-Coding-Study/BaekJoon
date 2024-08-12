#include <iostream>
#include <vector>

using namespace std;
vector<int> DP;
vector<int> L;
vector<int> R;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    DP.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> DP[i];
    }

    L.resize(N);
    L[0] = DP[0];
    int result = L[0];

    for (int i = 1; i < N; ++i) {
        L[i] = max(DP[i], DP[i] + L[i - 1]);
        result = max(L[i], result);
    }

    R.resize(N);
    R[N - 1] = DP[N - 1];

    for (int i = N - 2; i >= 0; --i) {
        R[i] = max(DP[i], R[i + 1] + DP[i]);
    }

    for (int i = 1; i < N - 1; ++i) {

        int temp = L[i - 1] + R[i + 1];
        result = max(result, temp);

    }

    cout << result << "\n";

    return 0;
}

