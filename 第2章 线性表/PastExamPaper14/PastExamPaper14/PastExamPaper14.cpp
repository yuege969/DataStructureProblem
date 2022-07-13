/*
* 2023王道数据结构P13 14题
* 题意分析：分别从三个有序数组中拿出一个数，并计算出定义的距离的最小值
* 思路分析：若取出三个值分别为a,b,c,且a<b<c,则定义的距离为2*(c-a),因此可每次固定c来找a使得c-a最小
* 时间复杂度：O(n)
* 空间复杂度：O(1)
*/
#include <iostream>
using namespace std;
int dist(int a, int b) {
    if (a > b) return a - b;
    return b - a;
}
bool judge(int a, int b, int c) {
    if (a <= b && a <= c) return true;
    return false;
}
int findMinDist(int A[], int B[], int C[], int n1, int n2, int n3) {
    int minD = 0x3f3f3f3f;
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2 && k < n3 && minD > 0) {
        //cout << A[i] << " " << B[j] << " " << C[k] << endl;
        int D = dist(A[i], B[j]) + dist(B[j], C[k]) + dist(A[i], C[k]);
        if (D < minD) minD = D;
        if (judge(A[i], B[j], C[k]))i++;
        else if (judge(B[j], A[i], C[k])) j++;
        else k++;
    }
    return minD;
}
int main()
{
    int A[20] = { 0 }, B[20] = { 0 }, C[20] = { 0 };
    int n1, n2, n3; cin >> n1 >> n2 >> n3;
    for (int i = 0;i < n1;i++) cin >> A[i];
    for (int i = 0;i < n2;i++) cin >> B[i];
    for (int i = 0;i < n3;i++) cin >> C[i];
    int res = findMinDist(A, B, C, n1, n2, n3);
    cout << res;
    return 0;
}
