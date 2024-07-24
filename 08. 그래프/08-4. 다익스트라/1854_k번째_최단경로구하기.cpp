#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, int> edge;
vector<vector<int>> Graph;
priority_queue<edge, vector<edge>, greater<edge>> q;
vector<priority_queue<int>> Distance;

static int n, m, k;

void Dijkstra();

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    vector<int> vSide(n + 1, 0);

    Graph.resize(n + 1, vSide);
    Distance.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        Graph[u][v] = w;
    }

    q.push({ 0, 1 });
    Distance[1].push(0); 

    Dijkstra();

    for (int i = 1; i < n + 1; ++i) {
        if (k == Distance[i].size()) {
            cout << Distance[i].top() << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }

    return 0;
}

void Dijkstra() {

    while (!q.empty()) {

        edge current = q.top();
        int currentVal = current.first;
        int currentIdx = current.second;

        q.pop();

        for (int i = 1; i < (int)Graph[currentIdx].size(); ++i) {

            int next = Graph[currentIdx][i];

            if (0 != next) {

                if (Distance[i].size() < k) {
                    Distance[i].push({ Graph[currentIdx][i] + currentVal });
                    q.push({ Graph[currentIdx][i] + currentVal, i });
                }
                else if (Graph[currentIdx][i] + currentVal < Distance[i].top()) {
                    Distance[i].pop();
                    Distance[i].push({ Graph[currentIdx][i] + currentVal });
                    q.push({ Graph[currentIdx][i] + currentVal , i });
                }

            }

        }
    }
}
