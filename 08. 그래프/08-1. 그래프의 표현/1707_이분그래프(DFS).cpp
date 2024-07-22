#include <iostream>
#include <vector>

using namespace std;

static bool isBipartite = true;
static vector<vector<int>> v;

void DFS(int node, vector<vector<int>>& v, vector<bool>& check, vector<int>& group);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> K;

    for (int i = 0; i < K; ++i) {
        int V, E;
        cin >> V >> E;

        isBipartite = true;

        v.clear();
        v.resize(V + 1, {});
        vector<bool> checked(V + 1, false);
        vector<int> groups(V + 1, -1);

        for (int j = 0; j < E; ++j) {
            int s, e;
            cin >> s >> e;
            v[s].push_back(e);
        }


        for (int k = 1; k < v.size(); ++k) {

            if (groups[k] != -1)
                continue;

            fill(checked.begin(), checked.end(), false);
            DFS(k, v, checked, groups);

            if (!isBipartite)
                break;

        }

        if (isBipartite) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}

void DFS(int node, vector<vector<int>>& v, vector<bool>& check, vector<int>& group) {

    if (!isBipartite)
        return;

    check[node] = true;

    bool checkBipartite = false;

    int nextGroup;

    if (0 == group[node]) {
        nextGroup = 1;
    }
    else if (1 == group[node]) {
        nextGroup = 0;
    }
    else if (-1 == group[node]) {
        group[node] = 0;
        nextGroup = 1;
    }


    for (int i = 0; i < v[node].size(); ++i) {

        int next = v[node][i];

        if (check[next]) {

            if (nextGroup != group[next]) {
                isBipartite = false;
                return;
            }

        }
        else {
            group[next] = nextGroup;
            DFS(next, v, check, group);
        }
    }

}