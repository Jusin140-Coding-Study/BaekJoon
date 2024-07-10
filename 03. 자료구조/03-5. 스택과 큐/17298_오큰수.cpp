#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    stack<int> nums;
    stack<int> temp;
    vector<int> answer;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        nums.push(num);
    }

    while (N != answer.size()) {
        if (temp.empty()) {
            answer.push_back(-1);
            temp.push(nums.top());
            nums.pop();
        }
        else {
            if (temp.top() > nums.top()) {
                answer.push_back(temp.top());
                temp.push(nums.top());
                nums.pop();
            }
            else {
                temp.pop();
            }
        }
    }

    for (int i = N - 1; i >= 0; --i) {

        cout << answer[i] << " ";
    }


    return 0;
}