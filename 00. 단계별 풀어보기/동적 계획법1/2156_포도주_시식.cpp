#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> amount;
vector<int> DP;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    amount.resize(N + 1);
    DP.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> amount[i];
    }

    DP[0] = 0;
    DP[1] = amount[1];
    DP[2] = amount[1] + amount[2];


    for (int i = 3; i <= N; ++i) {
        DP[i] = max(DP[i - 3] + amount[i - 1] + amount[i] , max(DP[i - 1], DP[i - 2] + amount[i]));
    }

    cout << DP[N];

    return 0;
}
