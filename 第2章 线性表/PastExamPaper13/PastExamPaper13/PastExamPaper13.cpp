/*
* 2023王道数据结构P19 13题
* 题意分析：找出数组中未出现过的最小正整数
* 算法思想：使用标记数组将出现过的正数都做上标记,再从1往后遍历出未被标记的正整数
* 时间复杂度：O(n)
* 空间复杂度：O(n)
*/
#include<iostream>
using namespace std;
int findMissMin(int A[], int n) {
	bool* vis = (bool *)malloc(sizeof(bool) * n);
	memset(vis, false, sizeof(bool) * n);
	for (int i = 0;i < n;i++) {
		if (A[i] > 0) vis[A[i] - 1] = true;
	}
	int res = 0;
	while (vis[res]) res++;
	return res + 1;
}
int main() {
	int a[20] = { 0 };
	int n; cin >> n;
	for (int i = 0;i < n;i++) cin >> a[i];
	int res = findMissMin(a, n);
	cout << res;
	return 0;
}