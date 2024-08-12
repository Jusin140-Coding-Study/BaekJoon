#include <iostream>

using namespace std;

long long D[202][202];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    long long K;
    cin >> N >> M >> K;

    for (int i = 0; i <= N + M; ++i) {
        for (int j = 0; j <= i; ++j) {

            if (j == 0 || j == i) {

                D[i][j] = 1;

            }
            else {
                D[i][j] = D[i - 1][j] + D[i - 1][j - 1];

                if (D[i][j] > 1000000000) {
                    D[i][j] = 1000000001;
                }
            }
        }
    }

    if (D[N + M][M] < K) {
        cout << -1;
    }
    else {

        while (!(N == 0 && M == 0)) {

            if (D[N + M - 1][M] >= K) {
                cout << "a";
                N--;
            }
            else {

                cout << "z";
                K = K - D[N - 1 + M][M];
                M--;

            }

        }


    }



    return 0;
}

