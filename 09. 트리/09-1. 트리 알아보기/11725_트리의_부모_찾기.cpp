#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> nodes;
vector<int> parentNode;

vector<bool> visited;

//시간 : 56ms
void DFS(int start);
//시간 : 52ms
void BFS(int start);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    nodes.resize(N + 1);
    parentNode.resize(N + 1);
    visited.resize(N + 1);

    for (int i = 0; i < N - 1; ++i) {
        int parent, child;
        cin >> parent >> child;

        nodes[parent].push_back(child);
        nodes[child].push_back(parent);

    }


    BFS(1);

    for (int i = 2; i <= N; ++i) {

        cout << parentNode[i] << "\n";

    }


    return 0;
}


void DFS(int value) {


    if (visited[value])
        return;

    visited[value] = true;

    for (int i = 0; i < (int)nodes[value].size(); ++i) {

        int cur = nodes[value][i];

        if (!visited[cur]) {
            parentNode[cur] = value;
            DFS(cur);
        }
    }
}


void BFS(int start) {

    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        for (int i = 0; i < (int)nodes[cur].size(); ++i) {

            int next = nodes[cur][i];

            if (!visited[next]) {
                parentNode[next] = cur;
                q.push(next);
                visited[next] = true;
            }
        }

    }


}