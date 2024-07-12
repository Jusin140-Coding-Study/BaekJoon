/*
* @title    : 2750�� �� �����ϱ�(�����2)
* @content  : ��������
* @author   : �յ���
* @date     : 240711
* @time     : 0ms
* @memory   : 2020 KB
* @state    : �Ϸ�
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
    vector<int> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];

    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = 0; j < N - 1 - i; ++j)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }

    for (int& it : v)
        cout << it << "\n";

    return 0;
}