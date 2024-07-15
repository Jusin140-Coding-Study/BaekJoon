#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;



int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> A(N, {0, 0});

    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        A[i] = { n , i };
    }

    sort(A.begin(), A.end(), less<pair<int, int>>());
    int max = -1000000;

    for (int i = 0; i < N; ++i) {

        int index = A[i].second - i;

        if (max < index) {
            max = index;
        }

    }

    cout << max + 1;
   
    return 0;
}