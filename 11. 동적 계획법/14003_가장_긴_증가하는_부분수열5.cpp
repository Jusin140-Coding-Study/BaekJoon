#include <iostream>

using namespace std;

int N, maxLength;
int B[1000001];
int A[1000001];
int D[1000001];
int ans[1000001];
int BinarySearch(int l, int r, int now);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    int index;
    B[++maxLength] = A[1];
    D[1] = 1;

    for (int i = 2; i <= N; ++i) {
        if (B[maxLength] < A[i]) {
            B[++maxLength] = A[i];
            D[i] = maxLength;
        }
        else {
            index = BinarySearch(1, maxLength, A[i]);
            B[index] = A[i];
            D[i] = index;
        }
    }

    cout << maxLength << "\n";
    index = maxLength;
    int x = B[maxLength] + 1;

    for (int i = N; i >= 1; --i) {
        if (D[i] == index && A[i] < x) {
            ans[index] = A[i];
            x = A[i];
            index--;
        }
    }

    for (int i = 1; i <= maxLength; ++i) {
        cout << ans[i] << " ";
    }


    return 0;
}

int BinarySearch(int l, int r, int now) {

    int mid;

    while (l < r) {
        mid = (l + r) / 2;
        if (B[mid] < now) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }

    return l;

}
