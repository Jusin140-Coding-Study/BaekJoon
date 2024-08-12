#include <iostream>

using namespace std;

int INF = 1000000 * 16 + 1;
int W[16][16];
int D[16][(1 << 16)];
int tsp(int c, int v);
int N;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> W[i][j];
        }
    }

    cout << tsp(0, 1) << "\n";


    return 0;
}

int tsp(int c, int v) {
    if (v == (1 << N) - 1)
        return W[c][0] == 0 ? INF : W[c][0];

    if (D[c][v] != 0)
        return D[c][v];

    int minVal = INF;
    for (int i = 0; i < N; ++i) {
        if ((v & (1 << i)) == 0 && W[c][i] != 0)
            minVal = min(minVal, tsp(i, (v | (1 << i))) + W[c][i]);
    }

    D[c][v] = minVal;
    return D[c][v];

}

