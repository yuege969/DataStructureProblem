/*
* 2023王道数据结构考研辅导书
* Page: 18
* Problem：10. 将数组R中保存的序列循环左移p位
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<random>
using namespace std;
default_random_engine RAND;
void method1(int a[],int n,int p) {
	/*
	* 传入数组a,数组长度n, 移动位次p
	* 方法一：设计思想
	* 使用辅助数组进行拷贝，需要额外空间
	* 时间复杂度O(n)
	* 空间复杂度O(n)
	*/
	int b[30];
	for (int i = 0;i < n;i++) {
		b[i] = a[(i + p) % n];//通过位置关系进行赋值
	}
	for (int i = 0;i < n;i++) {
		a[i] = b[i];//将转移后的数组拷贝回a数组中
	}
}
void reverse(int a[], int l, int r) {
	for (int i = l, j = r;i < j;i++, j--) {
		swap(a[i], a[j]);
	}
}
void method2(int a[], int n, int p) {
	/*
	* 方法二：设计思想
	* 通过逆置整个数组以及逆置子数组来实现，不需要额外空间
	* 例向左移动3位的操作：a[0],a[1],a[2],a[3],a[4] -> a[4],a[3],a[2],a[1],a[0] -> a[3],a[4],a[2],a[1],a[0] -> a[3],a[4],a[0],a[1],a[2]
	* 时间复杂度O(n)
	* 空间复杂度O(1)
	*/
	reverse(a, 0, n - 1);
	reverse(a, 0, n - p - 1);
	reverse(a, n - p, n - 1);
}
void print(int a[],int n) {
	for (int i = 0;i < n;i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
int main() {
	int R[30] = { 0 };
	RAND.seed(time(0));
	cout << "请输入序列长度: ";
	int n; cin >> n;
	for (int i = 0;i < n;i++) R[i] = RAND() % 10;
	print(R, n);
	method2(R, n, 3);
	print(R, n);
	return 0;
}