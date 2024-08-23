#include <iostream>

using namespace std;

long long Triangles[500][500];
long long DP[500][500];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> Triangles[i][j];
        }
    }

    DP[0][0] = Triangles[0][0];

    for (int i = 1; i < N; ++i) {
        DP[i][0] = DP[i - 1][0] + Triangles[i][0];

        for (int j = 1; j <= i; ++j) {
            DP[i][j] = max(Triangles[i][j] + DP[i - 1][j], max(DP[i][j], Triangles[i][j] + DP[i - 1][j - 1]));
        }
    }


    long long answer = 0;

    for (int i = 0; i < N; ++i) {
        answer = max(answer, DP[N - 1][i]);

    }

    cout << answer;

    return 0;
}

