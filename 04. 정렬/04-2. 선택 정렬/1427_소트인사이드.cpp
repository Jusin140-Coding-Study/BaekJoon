#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string N;
    cin >> N;

    vector<int> numbers(N.size(), 0);

    for (int i = 0; i < N.size(); ++i) {
        numbers[i] = N[i] - '0';
    }

    sort(numbers.begin(), numbers.end(), greater<int>());

    for (auto& iter : numbers) {
        cout << iter;
    }

    return 0;
}