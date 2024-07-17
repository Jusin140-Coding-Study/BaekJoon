#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

long long GetLcm(long long a, long long b);
void DFS(int node, vector<vector<tuple<int, int, int>>>& v, vector<bool>& check, vector<long long>& rateVec);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<tuple<int ,int, int>>> v(N);
    vector<bool> checked(N, false);
    vector<long long> rate(N, 1);

    //최소공배수
    long long lcm = 1;

    for (int i = 0; i < N - 1; ++i) {
        int index1, index2, rate1, rate2;

        cin >> index1 >> index2 >> rate1 >> rate2;

        v[index1].push_back({ index2, rate1, rate2 });
        v[index2].push_back({ index1, rate2, rate1 });

        lcm *= (rate2 * rate1) / GetLcm(rate1, rate2);
    }

    rate[0] = lcm;

    DFS(0, v, checked, rate);

    long long result = GetLcm(rate[0], rate[1]);

    for (int i = 2; i < v.size(); ++i) {

        result = GetLcm(result, rate[i]);
    }

    for (int i = 0; i < v.size(); ++i) {

        cout << rate[i] / result << " ";
    }

    return 0;
}


long long GetLcm(long long a, long long b) {

    long long minN = min(a, b);
    long long maxN = max(a, b);

    while (0 != maxN % minN) {

        long long r = maxN % minN;

        long long temp = minN;
        minN = r;
        maxN = temp;
    }

    return minN;
}

void DFS(int node, vector<vector<tuple<int, int, int>>>& v, vector<bool>& check, vector<long long>& rateVec) {

    check[node] = true;

    for (int i = 0; i < v[node].size(); ++i) {
        int next = get<0>(v[node][i]);
        
        if (check[next])
            continue;

        rateVec[next] = (rateVec[node] * get<2>(v[node][i])) / get<1>(v[node][i]);
        DFS(next, v, check, rateVec);
    }

}
