#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int FindFirstNum(int origin);
int Find(int origin);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    v.resize(N + 1);

    for (int i = 0; i < N + 1; ++i) {
        v[i] = i;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {

            int num;
            cin >> num;

            if (1 == num) {

                int first1 = FindFirstNum(i);
                int first2 = FindFirstNum(j);

                v[first1] = first2;
            }
        }
    }

    int prevNum = -1;

    for (int i = 0; i < M; ++i) {

        int num;
        cin >> num;

        num = num - 1;

        if (prevNum == -1) {
            prevNum = num;
        }

        int findNum1 = Find(num);
        int findNum2 = Find(prevNum);

        if (findNum1 != findNum2) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";


    return 0;
}


int FindFirstNum(int origin) {

    if (origin == v[origin])
        return origin;

    return FindFirstNum(v[origin]);

}

int Find(int origin) {

    if (origin == v[origin])
        return origin;

    return v[origin] = Find(v[origin]);

}

