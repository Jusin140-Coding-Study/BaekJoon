#include <iostream>
#include <vector>

using namespace std;

void MergeSort(vector<int>& a, int start, int end);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> nums(N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    MergeSort(nums, 0, N - 1);
        
    for (int i = 0; i < N; ++i) {

        cout << nums[i] << "\n";

    }

    return 0;
}


void MergeSort(vector<int>& a, int start, int end) {

    if (start == end)
        return;

    int middle = (start + end) / 2;

    MergeSort(a, start, middle);
    MergeSort(a, middle + 1, end);

    vector<int> result(end - start + 1, 0);

    int pivot1 = start;
    int pivot2 = middle + 1;

    int k = end + 1, j = middle + 1;
    int count = 0;


    while (pivot2 < k && pivot1 < j) {

        if (a[pivot1] >= a[pivot2]) {
            result[count] = a[pivot2];
            ++pivot2;
            ++count;
        }
        else if (a[pivot1] < a[pivot2]) {
            result[count] = a[pivot1];
            ++pivot1;
            ++count;
        }
    }

    if (pivot2 < k) {
        for (int i = pivot2; i < k; ++i) {
            result[count] = a[i];
            ++count;
        }
    }
    else if (pivot1 < j) {

        for (int i = pivot1; i < j; ++i) {
            result[count] = a[i];
            ++count;
        }
    }

    for (int i = start; i <= end; ++i) {
        a[i] = result[i - start];
    }

}