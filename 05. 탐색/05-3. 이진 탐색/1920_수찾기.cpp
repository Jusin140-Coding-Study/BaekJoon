#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> arr1(N, 0);

    for (int i = 0; i < N; ++i) {

        cin >> arr1[i];

    }

    sort(arr1.begin(), arr1.end(), less<int>());

    int M;
    cin >> M;

    for (int i = 0; i < M; ++i) {
        int findNum;
        cin >> findNum;

        int start = 0;
        int end = N - 1;
        int mid = 1;

        bool isFind = false;

        while (start <= end) {

            mid = (start + end) / 2;

            if (findNum == arr1[mid]) {
                cout << 1 << "\n";
                isFind = true;
                break;
            }
            else if (findNum < arr1[mid]) {
                end = mid - 1;
            }
            else if (findNum > arr1[mid]) {
                start = mid + 1;
            }

        }

        if (!isFind)
            cout << 0 << "\n";

    }

    return 0;
}