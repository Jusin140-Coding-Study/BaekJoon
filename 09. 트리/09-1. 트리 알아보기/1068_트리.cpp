#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> nodes;
vector<bool> visited;

int start = 0;
int eraseIdx = 0;
int answer = 0;

void DFS(int node, int prev);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    nodes.resize(N);
    visited.resize(N);

    for (int i = 0; i < N; ++i) {
        int value;
        cin >> value;

        //root node
        if (-1 == value) {
            start = i;
        }
        else {
            nodes[i].push_back(value);
            nodes[value].push_back(i);
        }

    }

    cin >> eraseIdx;

    DFS(start, start);

    cout << answer;

    return 0;
}


void DFS(int node, int prev) {

    if (eraseIdx == node) {

        if (node == start) {
            return;
        }

        if (prev != start && 1 == nodes[prev].size() - 1) {
            ++answer;
        }
        else if (prev == start && 1 == nodes[prev].size()) {

            ++answer;
        }

        return;
    }

    visited[node] = true;

    bool isParent = false;

    for (int i = 0; (int)nodes[node].size() > i; ++i) {

        int next = nodes[node][i];

        if (!visited[next]) {
            isParent = true;
            DFS(next, node);
        }
    }

    if (!isParent) {
        ++answer;
    }

}
