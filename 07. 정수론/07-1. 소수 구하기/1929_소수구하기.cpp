#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<int> v(N + 1, 0);

    for (int i = 0; i < N + 1; ++i) {
        v[i] = i;
    }

    v[1] = 0;

    for (int i = 2; i <= N; ++i) {

        if (0 == v[i])
            continue;

        int count = 1;

        while (v[i] + v[i] * count <= N) {
            v[v[i] + v[i] * count] = 0;
            ++count;
        }

    }

    for (int i = M; i < N + 1; ++i) {
        if (0 != v[i]) {
            cout << v[i] << "\n";
        }
    }


    return 0;
}