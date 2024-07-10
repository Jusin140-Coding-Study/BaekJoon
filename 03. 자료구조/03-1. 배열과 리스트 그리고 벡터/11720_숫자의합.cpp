#include <iostream>

using namespace std;

int main() {

    int count = 0;
    int sum = 0;

    cin >> count;

    char arr[101];

    cin >> arr;

    for (int num = 0; num < count; ++num) {
        sum += arr[num] - '0';
    }

    cout << sum;

    return 0;

}