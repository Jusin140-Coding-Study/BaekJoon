#include <iostream>

using namespace std;

long long DP[101][101][101];
long long MOD = 1000000007;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L, R;
    cin >> N >> L >> R;

    DP[1][1][1] = 1;

    for (int i = 2; i <= N; ++i) {

        for (int j = 1; j <= L; ++j) {

            for (int k = 1; k <= R; ++k) {

                DP[i][j][k] =
                    (DP[i - 1][j][k] * (i - 2) +
                    (DP[i - 1][j][k - 1] +
                        DP[i - 1][j - 1][k]))
                        % MOD;
            }
        }
    }

    cout << DP[N][L][R];

    return 0;
}

