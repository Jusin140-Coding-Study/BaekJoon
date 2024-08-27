#include <iostream>
#include <vector>

using namespace std;


int N;
vector<int> col;
int answer = 0;

bool isAttacked(int _col, int _row) {

    for (int i = 0; i < _col; ++i) {
        if (col[i] == _row || abs(col[i] - _row) == abs(i - _col)) {
            return false;
        }
    }

    return true;

}

void nQueen(int _col, int _count) {

    if (_count == N) {
        ++answer;
        return;
    }


    for (int i = 0; i < N; ++i) {

        if (isAttacked(_col, i)) {
            col[_col] = i;
            nQueen(_col + 1, _count + 1);
        }
    }


}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    col.resize(N);

    nQueen(0, 0);

    cout << answer;

    return 0;
}





//아래는 시간 초과 코드(답은 맞음)-----------------------------------------------------

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int N;
//vector<vector<int>> arr;
//vector<vector<int>> visited;
//
//void DFS(int _depth, int _startIdxX, int _startIdxY);
//void CalcVisited(pair<int, int> _pos, bool _isRemove);
//
//int answer = 0;
//
//int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
//int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
//
//int main() {
//
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    cin >> N;
//    arr.resize(N, vector<int>(N));
//    visited.resize(N, vector<int>(N));
//
//    DFS(0, 0, 0);
//
//    cout << answer;
//
//    return 0;
//}
//
//
//void DFS(int _depth, int _startIdxX, int _startIdxY) {
//
//    if (N == _depth) {
//        ++answer;
//        return;
//    }
//
//    for (int i = _startIdxY; i < N * N; ++i) {
//
//        int curX = i % N;
//        int curY = i / N;
//
//        if (0 == visited[curY][curX]) {
//            CalcVisited({ curY, curX }, false);
//            ++visited[curY][curX];
//            DFS(_depth + 1, 0, i + 1);
//            --visited[curY][curX];
//            CalcVisited({ curY, curX }, true);
//        }
//    }
//}
//
//
//void CalcVisited(pair<int, int> _pos, bool _isRemove) {
//
//    
//    for (int i = 0; i < 8; ++i) {
//        int posX = _pos.second;
//        int posY = _pos.first;
//
//        while (posX + dx[i] >= 0 && posX + dx[i] < N &&
//            posY + dy[i] >= 0 && posY + dy[i] < N) {
//
//            posY += dy[i];
//            posX += dx[i];
//
//            if (_isRemove) {
//                
//                --visited[posY][posX];
//            }
//            else {
//                ++visited[posY][posX];
//            }
//        }
//    }
//}
//
