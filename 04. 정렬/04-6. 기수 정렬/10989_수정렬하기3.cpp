#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//계수 정렬

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int arr[10001] = { 0 };

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        ++arr[num];
    }

    for (int i = 0; i < 10001; ++i) {
        for(int j = arr[i]; j > 0 ; --j){
            cout << i << "\n";
        }
    }

    return 0;
}


//기수 정렬 복습 코드(메모리 초과)
//
//int main() {
//
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int N;
//    cin >> N;
//
//    queue<int> numQueue[10];
//    vector<int> A(N, 0);
//
//    for (int i = 0; i < N; ++i) {
//        cin >> A[i];
//    }
//
//    bool isDone = false;
//    int count = 10;
//
//    while (true != isDone && count <= 10000) {
//
//        bool check = true;
//        for (int i = 0; i < N; ++i) {
//            if (A[i] % count != A[i]) {
//                check = false;
//            }
//            numQueue[(A[i] % count) / (count / 10)].push(A[i]);
//        }
//
//        int tempCount = 0;
//        int index = 0;
//        while (tempCount < 10) {
//
//            if (numQueue[tempCount].empty()) {
//                ++tempCount;
//            }
//            else {
//                A[index] = numQueue[tempCount].front();
//                numQueue[tempCount].pop();
//                ++index;
//            }
//        }
//
//        count *= 10;
//
//        if (check)
//            isDone = true;
//
//    }
//
//    for (int i = 0; i < N; ++i) {
//        cout << A[i]<< "\n";
//    }
//
//    return 0;
//}