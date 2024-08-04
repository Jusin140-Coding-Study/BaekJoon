#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findRoot(int a, int b);
void BFS(int start);

struct node {
    int parent;
    int depth;
};

vector<node> tree;
vector<vector<int>> graph;
vector<bool> visited;

int N;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    tree.resize(N + 1);
    graph.resize(N + 1);

    for (int i = 0; i < N - 1; ++i) {

        int p, c;
        cin >> p >> c;

        graph[p].push_back(c);
        graph[c].push_back(p);

    }

    BFS(1);

    int M;
    cin >> M;

    for (int i = 0; i < M; ++i) {

        int first, second;
        cin >> first >> second;

        cout << findRoot(first, second) << "\n";

    }

    return 0;
}


int findRoot(int a, int b) {

    while (tree[a].depth != tree[b].depth) {

        if (tree[a].depth > tree[b].depth) {
            a = tree[a].parent;
        }
        else {
            b = tree[b].parent;
        }
    }

    while (a != b) {
        a = tree[a].parent;
        b = tree[b].parent;
    }

    return a;
}


void BFS(int start) {


    queue<int> q;
    q.push(start);

    visited.resize(N + 1, false);
    visited[start] = true;

    int count = 0;
    int currentSize = 1;
    int level = 1;

    while (!q.empty()) {

        int current = q.front();
        q.pop();

        for (int i = 0; i < (int)graph[current].size(); ++i) {

            int next = graph[current][i];

            if (!visited[next]) {
                visited[next] = true;
                tree[next].parent = current;
                tree[next].depth = level;

                q.push(next);
            }
        }


        count++;
        if (count == currentSize) {
            count = 0;
            currentSize = q.size();
            ++level;
        }

    }

}
