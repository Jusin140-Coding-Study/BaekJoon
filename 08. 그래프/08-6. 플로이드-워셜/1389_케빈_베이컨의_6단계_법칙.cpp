#include <iostream>
#include <limits.h>

using namespace std;

int N, M;
int person[101][101];

void Floyd();

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == j) {
                person[i][j] = 0;
            }
            else {
                person[i][j] = INT_MAX;
            }
        }
    }

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        person[a][b] = 1;
        person[b][a] = 1;
    }

    Floyd();

    int minCount = INT_MAX;
    int minIndex = 0;

    for (int i = 1; i <= N; ++i) {
        int current = 0;
        for (int j = 1; j <= N; ++j) {
            current += person[i][j];
        }

        if (current < minCount) {
            minCount = current;
            minIndex = i;
        }

    }

    cout << minIndex;

    return 0;
}

void Floyd() {

    for (int k = 1; k <= N; ++k) {
        for (int s = 1; s <= N; ++s) {
            for (int e = 1; e <= N; ++e) {
                if (person[s][k] != INT_MAX && INT_MAX != person[k][e])
                    person[s][e] = min(person[s][e], person[s][k] + person[k][e]);
            }
        }
    }


}
