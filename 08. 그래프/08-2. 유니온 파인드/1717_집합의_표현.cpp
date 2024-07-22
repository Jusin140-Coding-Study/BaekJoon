#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int Union(int origin);
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


    for (int i = 0; i < M; ++i) {

        int command, num1, num2;
        cin >> command >> num1 >> num2;

        //합집합
        if (0 == command) {

            int First1 = Union(num1);
            int First2 = Union(num2);

            int minNum = min(First1, First2);
            int maxNum = max(First1, First2);

            v[maxNum] = minNum;

            //동일 집합 확인 
        }
        else if (1 == command) {

            int First1 = Find(num1);
            int First2 = Find(num2);

            if (First1 == First2) {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }

        }


    }

    return 0;
}


int Union(int origin) {

    if (origin == v[origin])
        return origin;

    return Union(v[origin]);

}


int Find(int origin) {

    if (origin == v[origin])
        return origin;

    return v[origin] = Find(v[origin]);

}