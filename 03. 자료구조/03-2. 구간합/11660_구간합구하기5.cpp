#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> arr(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> sums(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; ++i) {

        for (int j = 1; j <= N; ++j) {
            cin >> arr[i][j];
            sums[i][j] = sums[i][j - 1] + sums[i - 1][j] - sums[i -1][j - 1] + arr[i][j];
        }
    }

    for (int i = 0; i < M; ++i) {

        int row1, row2, col1, col2;

        cin >> row1 >> col1 >> row2 >> col2;

        cout << sums[row2][col2] - sums[row2][col1 - 1] - sums[row1 - 1][col2] + sums[row1 - 1][col1 - 1] << "\n";
        
    }


    return 0;
}