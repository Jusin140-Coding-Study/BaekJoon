#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> DP;
vector<int> reverseDP;

int N;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    arr.resize(N);
    DP.resize(N);
    reverseDP.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; ++i) {
        DP[i] = 1;
        for (int j = i - 1; j >= 0; --j) {
            if (arr[i] > arr[j]) {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
    }

    for (int i = N - 1; i >= 0; --i) {
        reverseDP[i] = 1;
        for (int j = i + 1; j < N; ++j) {
            if (arr[i] > arr[j]) {
                reverseDP[i] = max(reverseDP[i], reverseDP[j] + 1);
            }
        }
    }

    int answer = 0;

    for (int i = 0; i < N; ++i) {

        answer = max(answer, reverseDP[i] + DP[i] - 1);
    }

    cout << answer;

    return 0;
}

