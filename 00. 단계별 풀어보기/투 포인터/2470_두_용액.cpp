#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <cmath>

using namespace std;

vector<long long> liquids;
long long currentMin = LLONG_MAX;
long long answer[2];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    liquids.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> liquids[i];
    }

    sort(liquids.begin(), liquids.end());

    int start = 0;
    int end = N - 1;

    while (end > start) {

        if (abs(liquids[start] + liquids[end]) < currentMin) {
            answer[0] = liquids[start];
            answer[1] = liquids[end];
            currentMin = abs(liquids[start] + liquids[end]);
        }

        if (liquids[start] + liquids[end] < 0) {
            ++start;
        }
        else if (liquids[start] + liquids[end] > 0) {
            --end;
        }

        if (0 == currentMin)
            break;

    }


    cout << answer[0] << " " << answer[1];


    return 0;
}

