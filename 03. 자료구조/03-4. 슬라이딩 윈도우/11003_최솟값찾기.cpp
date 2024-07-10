#include <iostream>
#include <deque>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;

    cin >> N >> L;

    deque<pair<int, int>> nums = {};

    int index = 1;

    for (int i = 1; i <= N; ++i) {
        int num;
        cin >> num;

        while (!nums.empty() && nums.back().second > num) {
            nums.pop_back();
        }

        nums.push_back({ i , num });

        if (nums.front().first <= i - L) {
            nums.pop_front();
        }

        cout << nums.front().second<< " ";

    }

    return 0;
}