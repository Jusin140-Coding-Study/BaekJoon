#include <iostream>

using namespace std;

int T;
int D[31][31];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; ++i) {

        int N, M;
        cin >> N >> M;

        fill_n(D[0], 31 * 31, 0);

        for (int j = 0; j <= M; ++j) {

            D[j][j] = 1;
            D[j][1] = j;

        }

        for (int j = 2; j <= M; ++j) {

            for (int k = 2; k < j; ++k) {

                D[j][k] = D[j - 1][k - 1] + D[j - 1][k];

            }

        }

        cout << D[M][N] << "\n";

    }




    return 0;
}

