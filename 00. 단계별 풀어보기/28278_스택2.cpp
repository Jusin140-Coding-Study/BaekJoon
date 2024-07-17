#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N;
    cin >> N;
    stack<int> nums;
    vector<int> answer;
         
    for (int i = 0; i < N; ++i) {

        int command;
        cin >> command;

        if (1 == command) {
            int X;
            cin >> X;
            nums.push(X);

        }
        else if (2 == command) {
            if (nums.empty()) {
                answer.push_back(-1);
            }
            else {
               
                answer.push_back(nums.top());
                nums.pop();
            }
        }
        else if (3 == command) {
            answer.push_back(nums.size());
        }
        else if (4 == command) {
            if (nums.empty()) {
                answer.push_back(1);
            }
            else {
                answer.push_back(0);

            }

        }
        else if (5 == command) {
            if (nums.empty()) {
                answer.push_back(-1);
            }
            else {
                answer.push_back(nums.top());
            }
        }
    }


    for (auto& iter : answer) {

        cout << iter << "\n";
    }

    return 0;

}