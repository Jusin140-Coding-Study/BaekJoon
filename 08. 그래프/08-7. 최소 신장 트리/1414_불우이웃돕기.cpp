#include <iostream>
#include <vector>
#include <limits.h>
#include <numeric>
#include <algorithm>

using namespace std;

struct edge {
    int first, second, value;
};

struct cmp {
    bool operator()(edge& a, edge& b) {
        return a.value < b.value;
    }
};

vector<edge> Graph;
vector<int> Parent;
vector<bool> Connected;

int edgeCount = 0;
int result = 0;
int totalLength = 0;

int Find(int origin);
void Union(int a, int b);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    Parent.resize(N);

    for (int i = 0; i < N; ++i) {

        Parent[i] = i;
    }

    for (int i = 0; i < N; ++i) {

        string input;
        cin >> input;

        for (int j = 0; j < (int)input.size(); ++j) {
            //0
            if ('0' == input[j]) {
                continue;
                //대문자
            }
            else if (input[j] < 'a') {

                Graph.push_back({ i, j, input[j] - 'A' + 27 });
                totalLength += input[j] - 'A' + 27;

                //소문자
            }
            else {
                Graph.push_back({ i, j, input[j] - 'a' + 1 });
                totalLength += input[j] - 'a' + 1;
            }
        }
    }

    sort(Graph.begin(), Graph.end(), cmp());

    bool isAllConnect = false;

    for (int i = 0; i < (int)Graph.size(); ++i) {

        if (Find(Graph[i].first) != Find(Graph[i].second)) {
            ++edgeCount;
            result += Graph[i].value;
            Union(Graph[i].first, Graph[i].second);
        }

        if (edgeCount == N - 1) {

            isAllConnect = true;
            break;

        }

    }

    if (edgeCount == N - 1) {

        isAllConnect = true;

    }


    if (isAllConnect) {
        cout << totalLength - result;
    }
    else {
        cout << -1;
    }


    return 0;
}


int Find(int origin) {
    if (origin == Parent[origin])
        return origin;

    return Parent[origin] = Find(Parent[origin]);
}


void Union(int a, int b) {

    a = Find(a);
    b = Find(b);

    if (a == b)
        return;

    Parent[a] = b;

}
