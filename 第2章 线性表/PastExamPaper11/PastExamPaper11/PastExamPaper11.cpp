/*
* 2023王道数据结构考研辅导书
* Page: 18
* Problem: 找出两个等长的升序序列合并之后的中位数
*/
#include<iostream>
using namespace std;
int findMidPosition1(int A[], int B[], int n) {
	/*
	* 算法设计思想：根据归并排序的思想找到合并之后的第n个元素
	* 时间复杂度：O(n)
	* 空间复杂度：O(1)
	*/
	int cnt = 0;
	int x = -1;
	for (int i = 0, j = 0;i < n && j < n;) {
		if (A[i] <= B[j]) x = A[i++], cnt++;
		else x = B[j++], cnt++;
		if (cnt == n) break;
	}
	return x;
}

int findMidPosition2(int A[], int B[], int n) {
	/*
	* 设计思想：
	* 分别求两个升序序列A、B的中位数,设为a,b,求序列A,B的中位数的过程如下：
	* (1)若a=b,则a或b即为所求中位数,算法结束；
	* (2)若a<b,则舍弃序列A中较小的一半,同时舍弃序列B中较大的一半，要求两次舍弃的长度相等；
	* (3)若a>b,则舍弃序列A中较大的一半,同时舍弃序列B中较小的一半，要求两次舍弃的长度相等；
	* 在保留的两个升序序列中，重复(1)(2)(3),直到两个序列中均只含一个元素为止,较小者即为所求中位数。
	* 时间复杂度：O(logn)
	* 空间复杂度：O(1)
	*/
	int l1 = 0, r1 = n - 1, m1, l2 = 0, r2 = n - 1, m2;//分别表示a和b序列的首位数,末位数和中位数
	while (l1 != r1 || l2 != r2) {
		m1 = l1 + r1 >> 1;
		m2 = l2 + r2 >> 1;
		if (A[m1] == B[m2]) return A[m1];
		else if (A[m1] < B[m2]) {
			if ((l1 + r1) % 2 == 0) //序列长度为奇数
			{
				//舍弃A[m1]之前的数
				//舍弃B[m2]之后的数
				l1 = m1;
				r2 = m2;
			}
			else //序列长度为偶数
			{
				//舍弃A[m1]之前的数包含A[m1]
				//舍弃B[m2]之后的数
				l1 = m1 + 1;
				r2 = m2;
			}
		}
		else if(A[m1] > B[m2]){
			if ((l1 + r1) % 2 == 0) //序列长度为奇数 
			{
				//舍弃B[m2]之前的数
				//舍弃A[m1]之后的数
				l2 = m2;
				r1 = m1;
			}
			else {
				//舍弃B[m1]之前的数包含B[m1]
				//舍弃A[m2]之后的数
				l2 = m2 + 1;
				r1 = m1;
			}
		}
	}
	return A[l1] < B[l2] ? A[l1] : B[l2];
}

int main() {
	int S1[20] = { 0 };
	int S2[20] = { 0 };
	cout << "请输入序列长度：";
	int n; cin >> n;
	for (int i = 0;i < n;i++) cin >> S1[i];
	for (int i = 0;i < n;i++) cin >> S2[i];
	int res = findMidPosition2(S1, S2, n);
	cout << res;
	return 0;
}