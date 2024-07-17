#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {

        int num1, num2;
        cin >> num1 >> num2;

        int multi = num1 * num2;

        int minNum = min(num1, num2);
        int maxNum = max(num1, num2);

        while (0 != maxNum % minNum) {

            num1 = maxNum % minNum;
            num2 = minNum;

            minNum = min(num1, num2);
            maxNum = max(num1, num2);
        }

        cout << multi / minNum << "\n";
    }

    return 0;
}
