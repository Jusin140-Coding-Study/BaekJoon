#include <iostream>
#include <vector>

using namespace std;

static int N;

void DFS(vector<vector<int>>& a, int count, int& answer , int currentNum);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    if (N == 1) {
        
        cout << 2 << "\n";
        cout << 3 << "\n";
        cout << 5 << "\n";
        cout << 7 << "\n";

        return 0;

    }

    vector<vector<int>> A;
    A.resize(10, {});

    A[1] = {1, 3 ,5, 7, 9};
    A[2] = {1, 3 ,5, 7, 9};
    A[3] = {1, 3 ,5, 7, 9};
    A[5] = {1, 3 ,5, 7, 9};
    A[7] = {1, 3 ,5, 7, 9};
    A[9] = { 1, 3 ,5, 7, 9};

    int count = 0;
    int answer = 0;

    for (int i = 2; i < 9; ++i) {
        if(!A[i].empty())
            DFS(A, 2, answer, i);
    }

    return 0;
}


void DFS(vector<vector<int>>& a, int count, int& answer, int currentNum) {

    if (N < count)
        return;

    for (int i = 0; i < 10; ++i) {

        if (!a[i].empty()) {
            int current = (currentNum* 10) + i;

            bool isMinor = true;

            if (0 == current % 2)
                continue;

            for (int k = 2; k < current / 2; ++k) {

                if (0 == current % k) {
                    isMinor = false;
                    break;
                }

            }

            if (isMinor && N == count) {
                cout << current << "\n";

            }else if(isMinor && N > count){

                DFS(a, count + 1, answer, current);
            }
        }
    }
}


//에라토스테네스의 체(시간초과)
//int main() {
//
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int N;
//    cin >> N;
//
//    int maxNumber = 1;
//
//    for (int i = 0; i < N; ++i) {
//        maxNumber *= 10;
//    }
//
//    vector<bool> arr(maxNumber, true);
//
//    for (int i = 2; i < maxNumber / (10 * N); ++i) {
//        if (arr[i]) {
//            for (int j = 2 * i; j < maxNumber; j += i) {
//                if (arr[j]) {
//                    arr[j] = false;
//                }
//            }
//        }
//    }
//
//    for (int i = maxNumber / 10 * 2; i < maxNumber; ++i) {
//        if (arr[i]) {
//
//            bool isMinor = true;
//
//            for (int k = maxNumber / 10; k > 0; k /= 10) {
//             
//                if (!arr[i / k]) {
//                     isMinor = false;
//                     break;
//                }
//            }
//
//            if(isMinor)
//               cout << i << "\n";
//        }
//    }
//
//
//    return 0;
//}