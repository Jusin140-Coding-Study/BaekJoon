#include <iostream>
#include <limits.h>

using namespace std;

int N;
int distances[101][101];

void Floyd();

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int num;
            cin >> num;

            if (0 == num) {
                distances[i][j] = INT_MAX;
            }
            else {
                distances[i][j] = 1;
            }
            
        }
    }

    Floyd();

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (INT_MAX == distances[i][j]) {
                cout << 0 << " ";
            }
            else {
                cout << 1 << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}


void Floyd() {

    for (int k = 1; k <= N; ++k) {
        for (int s = 1; s <= N; ++s) {
            for (int e = 1; e <= N; ++e) {
                if (INT_MAX != distances[s][k] && INT_MAX != distances[k][e]) {
                    distances[s][e] = min(distances[s][e], distances[s][k] + distances[k][e]);
                }
            }
        }
    }


}
