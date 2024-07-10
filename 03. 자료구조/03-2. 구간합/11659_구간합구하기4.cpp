//C스타일 입출력(시간복잡도 통과 O)
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

    int totalCount = 0;
    int sumCount = 0;
    scanf_s("%d %d", &totalCount, &sumCount);

    int sums[100001] = { 0 };

    sums[0] = 0;

    for (int count = 0; count < totalCount; ++count) {
        int num;
        scanf_s("%d", &num);
        sums[count + 1] = num + sums[count];
    }

    for (int i = 0; i < sumCount; ++i) {

        int start, end;
        scanf_s("%d %d", &start, &end);
        printf("%d\n", sums[end] - sums[start - 1]);
    }

    return 0;
}


//C++ 스타일 입출력(시간 복잡도 통과x)
//
//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int totalCount, sumCount;
//
//    cin >> totalCount >> sumCount;
//
//    int sums[100001] = {};
//
//    for (int count = 1; count <= totalCount; count++) {
//        int num;
//        cin >> num;
//        sums[count] = num + sums[count - 1 ];
//    }
//
//    for (int i = 0; i < sumCount; i++) {
//
//        int start, end;
//        cin >> start >> end;
//        cout << sums[end] - sums[start - 1] << "\n";
//
//    }
//
//    return 0;
//}