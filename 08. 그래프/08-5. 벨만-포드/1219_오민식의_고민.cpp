#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>

using namespace std;

typedef tuple<int, int, int> edge;

vector<edge> graph;
vector<long long> minDistance;
vector<int> earn;
vector<int> loop;

int n, s, e, m;

bool isCycle = false;

void BellmanFord();

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s >> e >> m;

    graph.resize(m);
    minDistance.resize(n, LLONG_MAX);
    earn.resize(n);

    for (int i = 0; i < m; ++i) {

        int st, ed, price;
        cin >> st >> ed >> price;
        graph[i] = { st, ed, price };

    }

    for (int i = 0; i < n; ++i) {
        cin >> earn[i];
    }

    minDistance[s] = earn[s] * -1;

    BellmanFord();


    if (LLONG_MAX == minDistance[e]) {
        cout << "gg";
        return 0;
    }

    if (isCycle) {
        cout << "Gee";
    }
    else {
        cout << minDistance[e] * -1;
    }


    return 0;
}

void BellmanFord() {

    for (int node = 0; node < n - 1; ++node) {
        for (int i = 0;i < m; ++i) {

            edge temp = graph[i];

            int startNum = get<0>(temp);
            int endNum = get<1>(temp);
            int sePrice = get<2>(temp) - earn[endNum];

            if (minDistance[startNum] != LLONG_MAX &&
                minDistance[startNum] + sePrice < minDistance[endNum]) {
                minDistance[endNum] = minDistance[startNum] + sePrice;
            }
        }
    }


    for (int i = 0; i < m; ++i) {

        edge temp = graph[i];

        int startNum = get<0>(temp);
        int endNum = get<1>(temp);
        int sePrice = get<2>(temp) - earn[endNum];

        if (minDistance[startNum] != LLONG_MAX &&
            minDistance[startNum] + sePrice < minDistance[endNum]) { 
            //isCycle = true;
            loop.push_back(endNum);
        }
    }


    for (int i = 0; i < loop.size(); ++i){
        
        vector<long long> checkDist;
        checkDist.resize(n, LLONG_MAX);
        checkDist[loop[i]] = earn[loop[i]] * -1;

        for (int node = 0; node < n - 1; ++node) {
            for (int j = 0; j < m; ++j) {

                edge temp = graph[j];

                int startNum = get<0>(temp);
                int endNum = get<1>(temp);
                int sePrice = get<2>(temp) - earn[endNum];

                if (checkDist[startNum] != LLONG_MAX &&
                    checkDist[startNum] + sePrice < checkDist[endNum]) {
                    checkDist[endNum] = checkDist[startNum] + sePrice;
                }
            }
        }

        if (LLONG_MAX != checkDist[e]) {
            isCycle = true;
            break;
        }
    }
}
