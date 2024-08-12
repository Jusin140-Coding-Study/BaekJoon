#include <iostream>

using namespace std;

long long DP[101][10];
long long MOD = 1000000000;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= 9; ++i) {
        DP[1][i] = 1;
    }


    for (int i = 2; i <= N; ++i) {

        DP[i][0] = DP[i - 1][1];
        DP[i][9] = DP[i - 1][8];

        for (int j = 1; j <= 8; ++j) {

            DP[i][j] = (DP[i - 1][j + 1] + DP[i - 1][j - 1]) % MOD;
        }
    }

    long long answer = 0;

    for (int i = 0; i < 10; ++i) {

        answer = (answer + DP[N][i]) % MOD;

    }

    cout << answer;


    return 0;
}

