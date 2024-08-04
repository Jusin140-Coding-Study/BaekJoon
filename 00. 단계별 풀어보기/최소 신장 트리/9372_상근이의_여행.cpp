#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int>> v;
vector<int> parent;

int FindRoot(int& origin);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    //테스트 케이스 반복
    for (int i = 0; i < T; ++i) {

        int edgeCount = 0;
        int answer = 0;

        cin >> N >> M;

        v.resize(M, { 0, 0 });
        parent.resize(N + 1);


        for (int j = 0; j <= N; ++j) {

            parent[j] = j;

        }

        for (int j = 0; j < M; ++j) {

            cin >> v[j].first;
            cin >> v[j].second;

        }


        for (int j = 0; j < M; ++j) {

            int root1 = FindRoot(v[j].first);
            int root2 = FindRoot(v[j].second);

            if (root1 != root2) {

                parent[root1] = root2;
                ++answer;
                ++edgeCount;

            }

            if (edgeCount == N - 1) {
                break;
            }

        }

        cout << answer << "\n";

    }

    return 0;
}


int FindRoot(int& origin) {

    if (origin == parent[origin])
        return origin;

    return parent[origin] = FindRoot(parent[origin]);

}
