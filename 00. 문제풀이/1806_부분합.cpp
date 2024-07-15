#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, S;
    cin >> N >> S;

    vector<int> nums(N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    int start = 0;
    int end = 0;

    long sum = 0;
    int answer = 2147483647;

    while (start <= end) {

        if (S <= sum) {
            int count = end - start;
            answer = (answer > count) ? count : answer; 

            sum -= nums[start++];
        }
        else if (N == end) {
            break;
        }
        else {
            sum += nums[end++];
        }

    }

    if (2147483647 == answer) {
        cout << 0;
    }
    else {

        cout << answer;
    }

    return 0;
}