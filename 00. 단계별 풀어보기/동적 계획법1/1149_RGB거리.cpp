#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int N;
//RGB ¼ø¼­
vector<vector<int>> prices;
vector<vector<int>> DP;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    prices.resize(N, vector<int>(3));
    DP.resize(N, vector<int>(3));

    for (int i = 0; i < N; ++i) {
        cin >> prices[i][0];
        cin >> prices[i][1];
        cin >> prices[i][2];

        DP[i][0] = INT_MAX;
        DP[i][1] = INT_MAX;
        DP[i][2] = INT_MAX;
    }

    DP[0][0] = prices[0][0];
    DP[0][1] = prices[0][1];
    DP[0][2] = prices[0][2];

    for (int i = 0; i < N - 1; ++i) {

        DP[i + 1][0] = min(DP[i][1] + prices[i + 1][0], DP[i][2] + prices[i + 1][0]);
        DP[i + 1][1] = min(DP[i][0] + prices[i + 1][1], DP[i][2] + prices[i + 1][1]);
        DP[i + 1][2] = min(DP[i][0] + prices[i + 1][2], DP[i][1] + prices[i + 1][2]);
    }

    cout << min(min(DP[N - 1][0], DP[N - 1][1]), DP[N - 1][2]);

    return 0;
}

