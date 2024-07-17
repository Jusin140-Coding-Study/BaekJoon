#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

struct comp {
    bool operator()(int a, int b) {
        if (a < 0 && b < 0) {
            return b < a;
        }
        else {
            return a < b;
        }
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, comp> q;

    int N;
    cin >> N;
    int zeroCount = 0;
    bool isMinus = false;

    for (int i = 0; i < N; ++i) {

        int num;
        cin >> num;
        q.push(num);

    }

    int answer = 0;

    while (!q.empty()) {

        if (isMinus && q.size() == 1)
            break;

        int num1 = q.top();
        q.pop();

        int num2 = -1001;

        if (!q.empty()) {
            num2 = q.top();
        }

        // 0
        if (0 == num1) {

            if (1 == q.size() % 2) {
                isMinus = true;
            }
            
            
        }
        //양수
        else if (num1 > 0) {

            if (1 == num1 || 1 == num2) {
                answer += num1;
                continue;
            }

            if (num2 > 0) {
                answer += num1 * num2;
                q.pop();
            }
            else {
                answer += num1;
            }
            
        }
        //음수
        else {
            if (-1001 != num2 && num2 <= 0) {
                answer += num1 * num2;
                q.pop();
            }
            else {
                answer += num1;
            }
        }

    }


    cout << answer;

    return 0;
}
