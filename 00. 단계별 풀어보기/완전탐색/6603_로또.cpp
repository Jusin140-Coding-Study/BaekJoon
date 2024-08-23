#include <iostream>
#include <vector>

using namespace std;

vector<int> partition;
void DFS(int _depth, vector<int> _arr, vector<bool> _visited);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num = 1;


    while (cin >> num && num != 0) {

        partition.clear();

        vector<bool> visit(num, false);
        vector<int> numbers(6, 0);
        partition.resize(num);

        for (int i = 0; i < num; ++i) {
            cin >> partition[i];
        }

        DFS(0, numbers, visit);

        cout << "\n";
    }

    return 0;
}

void DFS(int _depth, vector<int> _arr, vector<bool> _visited) {

    if (_depth == 6) {

        for (int i = 0; i < (int)_arr.size(); ++i) {
            cout << _arr[i] << " ";
        }

        cout << "\n";

        return;

    }

    for (int i = 0; i < (int)partition.size(); ++i) {

        if (!_visited[i]) {
            _visited[i] = true;
            _arr[_depth] = partition[i];
            DFS(_depth + 1, _arr, _visited);
        }

    }


}
