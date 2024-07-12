/*
* @title    : 1377번 버블 소트(골드2)
* @content  : 버블정렬
* @author   : 손동찬
* @date     : 240711
* @time     : 348 ms
* @memory   : 25520 KB
* @state    : 완료
*/
#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
                                              
    int N;
    cin >> N;
    multimap<int, int> m;

    for (int i = 0; i < N; ++i)
    {
        int iNum;
        cin >> iNum;
        m.emplace(iNum, i);
    }

    int iMax = 0, iCount = 0;
    for (auto& pair : m)
    {
        iMax = max(iMax, pair.second - iCount);
        iCount++;
    }
    cout << iMax+1 << "\n";

    return 0;
}