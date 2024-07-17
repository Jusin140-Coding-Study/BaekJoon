#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    long long K;
    cin >> N >> K;

    vector<int> v(N, 0);

    int answer = 0;

    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    for (int i = N - 1; i >= 0; --i) {

        if (K >= v[i]) {

            int count = K / v[i];

            K -= count * v[i];
            answer += count;

            if (0 == K)
                break;
        }

    }

    cout << answer;

    return 0;
}