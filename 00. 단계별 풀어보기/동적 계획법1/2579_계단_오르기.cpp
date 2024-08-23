#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> stairs;
vector<vector<long long>> DP;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    stairs.resize(N + 1);
    DP.resize(N, vector<long long>(3));

    for (int i = 0; i < N; ++i) {
        cin >> stairs[i];
    }

    if (1 == N) {
        
        cout << stairs[0];
        return 0;
    }

    DP[0][1] = stairs[0];
    DP[1][1] = stairs[1];
    DP[1][2] = stairs[1] + stairs[0];

    for (int i = 2; i < N; ++i) {
        DP[i][1] = max(DP[i - 2][1] + stairs[i], DP[i - 2][2] + stairs[i]);
        DP[i][2] = DP[i - 1][1] + stairs[i];
    }

    cout << max(DP[N - 1][1], DP[N - 1][2]);

    return 0;
}

