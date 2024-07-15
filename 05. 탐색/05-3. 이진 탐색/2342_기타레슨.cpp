#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int start = 0;
    int end = 0;

    vector<int> v(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        end += v[i];
        
        if (start < v[i])
            start = v[i];
    }

    int mid = 1;

    int answer = 0;
    while (start <= end) {
        mid = (start + end) / 2;

        int currentSum = 0;
        int count = 1;

        for (int i = 0; i < N; ++i) {
            if (currentSum + v[i] > mid) {
                currentSum = v[i];
                ++count;
            }
            else {
                currentSum += v[i];
            }
        }

        if (count <= M) {
            answer = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    cout << answer;

    return 0;
}
