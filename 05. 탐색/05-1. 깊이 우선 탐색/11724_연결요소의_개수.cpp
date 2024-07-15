#include <iostream>
#include <vector>
#include <stack>

using namespace std;

static int answer = 0;

void DFS(stack<int>& s, vector<vector<int>>& n, vector<bool>& v);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> nodes;
    nodes.resize(N + 1, {});
    vector<bool> visit(N + 1, false);

    stack<int> S;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }

    DFS(S, nodes, visit);

    cout << answer;

    return 0;
}


void DFS(stack<int>& s, vector<vector<int>>& n, vector<bool>& v) {

    if (s.empty()) {
        bool isDone = true;
        for (int i = 1; i < n.size(); ++i) {
            if (!v[i]) {
                isDone = false;
                ++answer;
                s.push(i);
                v[i] = true;
                break;
            }
        }

        if (isDone)
            return;

    }

    int currentNode = s.top();
    s.pop();


    for (int i = 0; i < n[currentNode].size(); ++i) {
        if (!v[n[currentNode][i]]) {
            s.push(n[currentNode][i]);
            v[n[currentNode][i]] = true;
        }
    }

    DFS(s, n, v);
}
