/*
* 2023王道P18 12题
* 题意分析：找出数组中出现次数大于n/2的元素,n为数组长度
* 算法思路：目标元素的数量一定比剩余的其他所有的元素的数量多
* 遍历整个数组的所有元素，标记出一个可能是主元素的数；
* 在遍历一遍进行验证
*/
#include<iostream>
using namespace std;
int findMain(int A[], int n) {
	int cnt = 0, x = -1;
	for (int i = 0;i < n;i++) {
		if (cnt == 0) x = A[i], cnt = 1;
		else if (cnt != 0 && x != A[i]) cnt--;
		else if (cnt != 0 && x == A[i]) cnt++;
	}
	if (cnt) {
		int c = 0;
		for (int i = 0;i < n;i++) {
			if (A[i] == x) c++;
		}
		if (c > n / 2) return x;
	}
	return -1;
}
int main() {
	int a[20] = { 0 };
	int n; cin >> n;
	for (int i = 0;i < n;i++) cin >> a[i];
	int res = findMain(a, n);
	cout << res;
	return 0;
}