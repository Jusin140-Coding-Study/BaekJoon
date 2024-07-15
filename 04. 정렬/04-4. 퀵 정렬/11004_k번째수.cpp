#include <iostream>
#include <vector>
using namespace std;

int quickSort(vector<int>& a, int start, int end);
void RequestQuick(vector<int>& a, int start, int end, int K);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> A(N, 0);
    int answer = 0;
    int pivot = 0;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    RequestQuick(A, 0, N - 1,  K - 1);

    cout << A[K - 1];

    return 0;
}


int quickSort(vector<int>& a, int start, int end) {

    if (start + 1 == end) {
        if (a[start] > a[end]) {
            int temp = a[end];
            a[end] = a[start];
            a[start] = temp;
        }
        return end;
    }

    int pivot = (start + end) * 0.5;

    int temp = a[pivot];
    a[pivot] = a[start];
    a[start] = temp;

    pivot = start;
    int pivotValue = a[pivot];

    int i = start + 1, j = end;

    while (j >= i) {

        while (a[j] > pivotValue && j > 0) {
            --j;
        }

        while (a[i] < pivotValue && a.size() - 1 > i) {
            ++i;
        }


        if (i <= j) {
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;

            i++;
            --j;
        }

    }

    a[pivot] = a[j];
    a[j] = pivotValue;
    return j;
}

void RequestQuick(vector<int>& a, int start, int end, int K) {

    int newPivot = quickSort(a, start, end);

    if (K == newPivot) {
        return;
    }
    else if (newPivot > K) {
        RequestQuick(a, start, newPivot - 1, K);
    }
    else{
        RequestQuick(a, newPivot + 1, end, K);
    }


}
