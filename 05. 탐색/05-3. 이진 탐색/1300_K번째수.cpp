#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int start = 1;
    int end = K;

    int answer = 0;


    while (end >= start) {

        int mid = (end + start) / 2;
        int smallNum = 0;

        for (int i = 1; i <= N; ++i) {

            smallNum += min((mid / i), N);

        }

        if (smallNum >= K) {
            end = mid - 1;
            answer = mid;
        }
        else{
            start = mid + 1;
        }

    }

    cout << answer;

    return 0;
}
