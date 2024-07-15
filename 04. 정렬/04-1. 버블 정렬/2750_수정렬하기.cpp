#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> nums(N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {

            if (nums[j] > nums[j + 1]) {
                int temp = 0;
                temp = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = temp;
            }

        }

    }


    for (auto& iter : nums) {

        cout << iter << "\n";

    }


    return 0;
}