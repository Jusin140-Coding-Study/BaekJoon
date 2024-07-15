#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

static int N;

void DFS(vector<vector<int>>& a, int prev, vector<bool>& visit);
void BFS(vector<vector<int>>& a, int start);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, start;

    cin >> N >> M >> start;

    vector<vector<int>> v;
    v.resize(N + 1, {});

    for (int i = 0; i < M; ++i) {
        int s, e;
        cin >> s >> e;

        v[s].push_back(e);
        v[e].push_back(s);
    }

    for (int i = 0; i < N+1; ++i) {
        if (!v[i].empty()) {
            sort(v[i].begin(), v[i].end(), less<int>());
        }
    }

    vector<bool> visited(N + 1, false);
    DFS(v, start, visited);
    cout << "\n";
    BFS(v, start);

    return 0;
}

void DFS(vector<vector<int>>& a, int prev, vector<bool>& visit) {

    visit[prev] = true;
    cout << prev << " ";

    for (int i = 0; i < a[prev].size(); ++i) {
        if (!visit[a[prev][i]]) {
            DFS(a, a[prev][i], visit);
        }
    }

}

void BFS(vector<vector<int>>& a, int start) {

    queue<int> q;
    q.push(start);

    vector<int> visit(N + 1, false);
    visit[start] = true;

    while (!q.empty()) {

        int current = q.front();

        for (int i = 0; i < a[current].size(); ++i) {
            if (!visit[a[current][i]]) {
                q.push(a[current][i]);
                visit[a[current][i]] = true;
            }
        }

        q.pop();
        cout << current << " ";
    }

}
