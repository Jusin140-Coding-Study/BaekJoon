#include <iostream>
#include <vector>

using namespace std;

int N, V;

vector<pair<int, int>> arr;
vector<vector<int>> DP;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> V;

    arr.resize(N + 1);
    DP.resize(N + 1, vector<int>(V + 1));

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= V; ++j) {

            if (j - arr[i].first >= 0) {
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - arr[i].first] + arr[i].second);
            }
            else {
                DP[i][j] = DP[i - 1][j];
            }
        }
    }

    cout << DP[N][V];

    return 0;
}

