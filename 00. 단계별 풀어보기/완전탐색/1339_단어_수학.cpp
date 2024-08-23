#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int N;
vector<string> arr;
vector<long long> numbers;

long long answer = 0;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    arr.resize(N);
    numbers.resize(26);
   

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; ++i) {
        int currentCount = 1;
        for (int j = arr[i].size() - 1; j >= 0; --j) {
            numbers[arr[i][j] - 'A'] += currentCount;
            currentCount *= 10;
        }
    }
    
    sort(numbers.begin(), numbers.end(), greater<long long>());

    for (int i = 9; i >= 0; --i) {
        numbers[9 - i] *= i;
    }

    cout << accumulate(numbers.begin(), numbers.end(), 0);


    return 0;
}
