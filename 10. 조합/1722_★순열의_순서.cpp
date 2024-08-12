#include <iostream>

using namespace std;

long long F[21];
long long S[21];
bool visited[21];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, command;
    cin >> N >> command;
    F[0] = 1;

    for (int i = 1; i <= N; ++i) {

        F[i] = F[i - 1] * i;

    }


    if (1 == command) {

        long long K;
        cin >> K;

        for (int i = 1; i <= N; ++i) {
            for (int j = 1, cnt = 1; j <= N; ++j) {

                if (visited[j])
                    continue;

                if (K <= cnt * F[N - i]) {
                    K -= ((cnt - 1) * F[N - i]);
                    visited[j] = true;
                    S[i] = j;

                    break;

                }

                ++cnt;
            }    
        }

        for (int i = 1; i <= N; ++i) {
            cout << S[i] << " ";
        }

    }
    else if (2 == command) {

        long long K = 1;


        for (int i = 1; i <= N; ++i) {

            long long count = 0;
            cin >> S[i];

            for (int j = 1; j < S[i]; ++j) {

                if (!visited[j]) {
                    ++count;
                }

            }

            K += count * F[N - i];
            visited[S[i]] = true;


        }

        cout << K << "\n";


    }



    return 0;
}

