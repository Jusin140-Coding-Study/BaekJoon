/*
* @title    : 10989번 수 정렬하기 3(브론즈1)-계수정렬
* @content  : 기수정렬
* @author   : 손동찬
* @date     : 240712
* @time     : 1600 ms
* @memory   : 2180 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> v(10000, 0);

    for (int i = 0; i < N; ++i)
    {
        int iNum;
        cin >> iNum;
        v[iNum-1]++;
    }

    for (int i = 0; i < v.size(); ++i)
        if (v[i] != 0)
            for(int j = 0; j < v[i] ; ++j)
                cout << i+1 << "\n";
        
    return 0;
}