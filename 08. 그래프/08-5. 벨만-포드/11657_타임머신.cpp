#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> edge;
vector<edge> graph;
vector<long long> minDistance;

int N, M;
bool isCycle = false;

void BellmanFord();

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    graph.resize(M);
    minDistance.resize(N + 1, LLONG_MAX);

    for (int i = 0; i < M; ++i) {

        int a, b, c;
        cin >> a >> b >> c;

        graph[i] = { a, b, c };
    }

    minDistance[1] = 0;
    BellmanFord();

    if (isCycle) {
        cout << -1;
    }
    else {
        for (int i = 2; i < (int)minDistance.size(); ++i) {

            if (LLONG_MAX == minDistance[i]) {
                cout << -1 << "\n";
            }
            else {
                cout << minDistance[i] << "\n";
            }
        }

    }

    return 0;
}


void BellmanFord() {

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < M; ++j) {

            edge temp = graph[j];

            int s = get<0>(temp);
            int e = get<1>(temp);
            int t = get<2>(temp);

            if (minDistance[s] != LLONG_MAX &&
                minDistance[s] + t < minDistance[e]) {
                minDistance[e] = minDistance[s] + t;
            }
        }
    }

    for (int j = 0; j < M; ++j) {

        edge temp = graph[j];

        int s = get<0>(temp);
        int e = get<1>(temp);
        int t = get<2>(temp);
        int prevVal = minDistance[e];

        if (minDistance[s] != LLONG_MAX &&
            minDistance[s] + t < minDistance[e]) {
            isCycle = true;
            break;
        }

    }


}
