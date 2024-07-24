#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <limits.h>

using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> Graphs;
vector<bool> Visited;
vector<int> Distance;
int start, endNum;

priority_queue<edge, vector<edge>, greater<edge>> q;

void Dijkstra();

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    Graphs.resize(N + 1);
    Visited.resize(N + 1);
    Distance.resize(N + 1, INT_MAX);

    for (int i = 0; i < M; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        Graphs[u].push_back({ v, t });
    }

    cin >> start >> endNum;

    Distance[start] = 0;
    q.push({ 0, start });

    Dijkstra();

    cout << Distance[endNum];

    return 0;
}


void Dijkstra() {

    while (!q.empty()) {

        edge current = q.top();
        int currentVal = current.first;
        int currentIdx = current.second;

        q.pop();

        if (Visited[currentIdx])
            continue;

        Visited[currentIdx] = true;

        for (int i = 0; i < (int)Graphs[currentIdx].size(); ++i) {

            edge next = Graphs[currentIdx][i];
            int nextVal = next.second;
            int nextIdx = next.first;

            if (Distance[nextIdx] > nextVal + Distance[currentIdx]) {
                Distance[nextIdx] = nextVal + Distance[currentIdx];
                q.push({ Distance[nextIdx], nextIdx });
            }


        }


    }


}
