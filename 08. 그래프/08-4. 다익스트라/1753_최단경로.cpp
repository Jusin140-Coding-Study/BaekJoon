#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <limits.h>

using namespace std;

vector<vector<pair<int, int>>> Graphs;
vector<int> Distance;
vector<bool> visited;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

void Dijkstra(int startNode);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v, e, start;
    cin >> v >> e >> start;

    Graphs.resize(v + 1);
    Distance.resize(v + 1, INT_MAX);
    visited.resize(v + 1);

    for (int i = 0; i < e; ++i) {

        int u, v, w;
        cin >> u >> v >> w;

        Graphs[u].push_back({ v, w });
    }

    Distance[start] = 0;
    Dijkstra(start);

    for (int i = 1; i < v + 1; ++i) {

        if (Distance[i] == INT_MAX) {
            cout << "INF" << "\n";
        }
        else {
            cout << Distance[i] << "\n";
        }

    }

    return 0;
}


void Dijkstra(int startNode) {

    q.push({0, startNode});

    while (!q.empty()) {

        pair<int, int> current = q.top();
        q.pop();

        if (visited[current.second])
            continue;

        visited[current.second] = true;

        for (int i = 0; i < (int)Graphs[current.second].size(); ++i) {

            pair<int, int> next = Graphs[current.second][i];
            int index = next.first;
            int value = next.second;

            if (Distance[index] > value + Distance[current.second]) {
                Distance[index] = value + Distance[current.second];
                q.push({ Distance[index], index });
            }       
        }
    }
}
