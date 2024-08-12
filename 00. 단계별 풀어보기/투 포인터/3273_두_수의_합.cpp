#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> numbers;

int result = 0;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    numbers.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    int x;
    cin >> x;

    int start = 0;
    int end = N - 1;

    while (end > start) {

        if (x == numbers[start] + numbers[end]) {
            ++result;
            --end;
            ++start;

        }
        else if (x < numbers[start] + numbers[end]) {
            --end;
        }
        else {
            ++start;
        }
    }

    cout << result;

    return 0;
}

