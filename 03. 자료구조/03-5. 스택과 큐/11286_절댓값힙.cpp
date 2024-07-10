#include <iostream>
#include <queue>
#include <vector>

using namespace std;


//우선 순위 큐 사용 o

struct compare {
    bool operator()(int n1, int n2){
        
        int absN1 = abs(n1);
        int absN2 = abs(n2);
    
        if (absN1 == absN2) {
            return n1 > n2;
        }
        else {
            return absN1 > absN2;
        }
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, compare> nums;
    vector<int> answer;

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {

        int num;
        cin >> num;

        if (0 == num) {

            if (nums.empty()) {
                answer.push_back(0);
            }
            else
            {
                answer.push_back(nums.top());
                nums.pop();
            }


        }
        else {
            nums.push(num);
        }
    }

    for (auto& iter : answer) {

        cout << iter << "\n";
    }

    return 0;
}



//우선 순위 큐 사용 x (시간 초과)
//
//int main() {
//
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    queue<pair<int, int>> nums;
//    vector<int> answer;
//
//    int N;
//    cin >> N;
//
//    for (int i = 0; i < N; ++i) {
//
//        int num;
//        cin >> num;
//
//        if (0 == num) {
//
//            if (nums.empty()) {
//                answer.push_back(0);
//            }
//            else {
//
//                pair<int, int> min = nums.front();
//                pair<int, int > start = nums.front();
//                nums.pop();
//
//                for (int i = 0; i < nums.size(); ++i) {
//                    if (min.first > nums.front().first) {
//                        nums.push(min);
//                        min = nums.front();
//                        nums.pop();
//
//                    }
//                    else if (min.first < nums.front().first) {
//                        pair<int, int> temp = nums.front();
//                        nums.push(temp);
//                        nums.pop();
//
//                    }
//                    else if (min.first == nums.front().first) {
//                        if (min.second > nums.front().second) {
//                            nums.push(min);
//                            min = nums.front();
//                            nums.pop();
//                        }
//                        else {
//                            pair<int, int> temp = nums.front();
//                            nums.push(temp);
//                            nums.pop();
//                        }
//
//                    }
//                }
//
//                answer.push_back(min.second);
//            }
//
//
//        }
//        else {
//
//            if (num < 0) {
//                nums.push({ num * -1, num });
//
//            }
//            else {
//                nums.push({ num, num });
//            }
//        }
//    }
//
//    for (auto& iter : answer) {
//
//        cout << iter << "\n";
//    }
//
//    return 0;
//}