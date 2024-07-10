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
    vector<char> answer;
    vector<int> origin(N, 0);

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> origin[i];
    }

    int target = 0;
    int index = 1;
    
    while (true) {

        if (nums.empty() || nums.top() < origin[target]) {

            if (origin[target] >= index) {
                nums.push(index);
                answer.push_back('+');
                ++index;
            }
            else {
                break;
            }
        }
        else if(nums.top() == origin[target]){
            nums.pop();
            answer.push_back('-');
            ++target;
        }
        else{

            nums.pop();
            answer.push_back('-');

        }


        if (nums.empty() && index > N)
            break;

    }


    if (target == N) {
        for (auto& iter : answer) {
            cout << iter << "\n";
        }

    }
    else {
        cout << "NO" << "\n";
    }


    return 0;
}