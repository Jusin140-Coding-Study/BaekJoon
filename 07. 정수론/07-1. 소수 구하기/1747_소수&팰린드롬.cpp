#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

bool isPallindrome(int num);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;
    cin >> N;

    vector<bool> arr(1100000, true);

    arr[1] = false;
    arr[0] = false;


    for (int i = 2; i <= sqrt(1100000); ++i) {

        if (false == arr[i])
            continue;

        for (int j = i + i; j < 1100000; j += i) {
            arr[j] = false;
        }
    }

    for (int i = N; i < 1100000; ++i) {

        if (true == arr[i] && isPallindrome(i)) {
            cout << i;
            return 0;
        }
    }

    return 0;
}


bool isPallindrome(int num) {

    string s = to_string(num);

    for (int j = 0; j < s.size() / 2; ++j) {
        if (s[j] != s[s.size() - 1 - j]) {
            return false;
        }
    }

    return true;
}