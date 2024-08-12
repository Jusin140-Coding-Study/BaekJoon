#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int N;
vector<pair<int, int>> M;
static long long D[502][502];
int Execute(int _s, int _e);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    M.resize(N + 1);
    fill_n(&D[0][0], 502 * 502, -1);

    for (int i = 1; i <= N; ++i) {

        int y, x;
        cin >> y >> x;
        M[i] = make_pair(y, x);

    }

    cout << Execute(1, N) << '\n';



    return 0;
}


int Execute(int s, int e) {

    int result = INT_MAX;

    if (D[s][e] != -1)
        return D[s][e];

    if (s == e)
        return 0;

    if (s + 1 == e)
        return M[s].first * M[s].second * M[e].second;

    for (int i = s; i < e; ++i) {
        result = min(result, M[s].first * M[i].second * M[e].second + Execute(s, i) + Execute(i + 1, e));
    }

    return D[s][e] = result;
}
