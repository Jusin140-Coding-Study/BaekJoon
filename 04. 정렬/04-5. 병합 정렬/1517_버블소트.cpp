#include <iostream>
#include <vector>

using namespace std;

void MergeSort(vector<int>& a, vector<int>& temp, int start, int end, long long& swapCount);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N, 0);
    vector<int> temp(N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    long long answer = 0;

    MergeSort(arr, temp , 0, N - 1, answer);

    cout << answer;

    return 0;
}


void MergeSort(vector<int>& a, vector<int>& temp, int start, int end, long long& swapCount) {
    if (end - start < 1)
        return;

    int middle = start + (end - start) / 2;

    MergeSort(a, temp, start, middle, swapCount);
    MergeSort(a, temp, middle + 1, end, swapCount);


    for (int i = start; i <= end; ++i) {
        temp[i] = a[i];
    }

    vector<int> result(end - start + 1, 0);

    int pivot1 = start;
    int pivot2 = middle + 1;

    int k = start;
    int count = 0;


    while (pivot2 <= end && pivot1 <= middle) {

        if (temp[pivot1] > temp[pivot2]) {
            a[k] = temp[pivot2];
            swapCount = swapCount + pivot2 - k;
            ++pivot2;
            ++k;
        }
        else{
            a[k] = temp[pivot1];
            ++pivot1;
            ++k;
        }
    }


    while (pivot1 <= middle) {
        a[k] = temp[pivot1];
        k++;
        pivot1++;
    }

    while (pivot2 <= end) {
        a[k] = temp[pivot2];
        k++;
        pivot2++;
    }

}

