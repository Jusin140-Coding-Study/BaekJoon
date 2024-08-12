#include <iostream>

using namespace std;

int T;
int D[15][15];
int answer = 0;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; ++i) {

        int K, N;
        cin >> K >> N;

        fill_n(D[0], 15 * 15, 0);

        answer = 0;

        for (int j = 1; j <= N; ++j) {

            D[0][j] = j;
        }

        for (int j = 1; j <= K; ++j) {

            D[j][1] = D[j - 1][1];
        }

        for (int j = 1; j <= K; ++j) {
            for (int k = 2; k <= N; ++k) {
                D[j][k] = D[j][k-1] + D[j - 1][k];
            }
        }


        

        cout << D[K][N] << "\n";


    }


    return 0;
}

