/*
2023数据结构考研复习指导
Page: 18
Problem: 01 - 09
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <random>
using namespace std;
#define MaxSize 20
default_random_engine RAND;
typedef struct {
	int data[MaxSize]; //静态方式存储数据
	int length; //表长
}SqList;
void init(SqList& L) //初始化表长
{
	L.length = 0;
} 
SqList creat(int n,bool order) //随机生成 n 个 1 - 10的整数,order为true时生成的顺序表有序
{
	SqList sqList;
	init(sqList);
	sqList.length = n;
	for (int i = 0;i < n;i++) {
		sqList.data[i] = RAND() % 10 + 1;
	}
	if (order) {
		sort(sqList.data, sqList.data + sqList.length);
	}
	return sqList;
}
bool insert(SqList& L, int i, int e) // 向表中的第i个位置插入元素e
{
	if (i < 1 || i > L.length + 1) return false; //判断插入位置是否有效 
	if (L.length >= MaxSize) return false; //当前存储空间已满,不能插入  
	for (int j = L.length;j >= i;j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}
bool erase(SqList& L, int i, int& e) //删除表中第i个元素,并存储删除的的值e
{
	if (L.length == 0){
		cout << "表为空,非法删除! " << endl;
		return false; //表为空,不能删除
	}
	if (i < 1 || i > L.length) {
		cout << "删除位置非法! " << endl;
		return false; //判断删除位置是否有效
	}
	e = L.data[i - 1];
	for (int j = i;j < L.length;j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}
void print(SqList L) {
	if (L.length == 0) {
		cout << "表为空" << endl;
	}
	else {
		for (int i = 0;i < L.length;i++) {
			cout << L.data[i] << " ";
		}
		cout << "\n";
	}
}
bool eraseMinElem(SqList& L, int& e) //01删除最小的元素,空缺位置由最后一个元素填补
{
	if (L.length == 0) {
		cout << "表为空,非法删除! " << endl;
		return false; //表为空,不能删除
	}
	//寻找最小值
	int min1 = 0x3f3f3f3f;
	for (int i = 0;i < L.length;i++) 
		min1 = min(min1, L.data[i]);
	e = min1;
	//删除最小值,并用最后一个元素进行填补空缺位置,若最小元素在最后一个位置，则直接删除
	for (int i = 0;i < L.length;i++) {
		if (L.data[i] == min1 && i != L.length - 1) {
			L.data[i] = L.data[L.length - 1];
			break;//若有多个最小元素，只删除遇到的第一个最小的元素
		}
	}
	L.length--;
	return true;
}

bool reverse(SqList& L) //02使用双指针逆置表中的所有元素
{
	if (L.length == 0) {
		cout << "表为空，无法操作" << endl;
		return false;
	}
	//空间复杂度：O(1)
	//时间复杂度：O(n)
	for (int i = 0, j = L.length - 1;i < j;i++,j--) {
		swap(L.data[i], L.data[j]);
	}
	return true;
}
bool eraseAllx(SqList& L, int x) //03删除所有元素值为x的元素
{
	if (L.length == 0) {
		cout << "表为空,无法操作! " << endl;
		return false; //表为空,不能删除
	}
	//空间复杂度：O(1)
	//时间复杂度：O(n)
	int cnt = 0;
	for (int i = 0;i < L.length;i++) {
		if (L.data[i] == x) cnt++;
		else L.data[i - cnt] = L.data[i];
	}
	L.length -= cnt;
	return true;
}
bool eraseAllLR(SqList&L,int l,int r,bool flag) //04 & 05删除所有值在[l,r]区间内的所有元素,若flag=1，则包含边界，否则不包含边界
{
	if (flag) l--, r++;
	if (l > r) {
		cout << "范围限定出错！请保证输入的第一个数小于等于第二个数！" << endl;
		return false;
	}
	if (L.length == 0) {
		cout << "表为空,非法删除! " << endl;
		return false; //表为空,不能删除
	}
	int cnt = 0;
	for (int i = 0, j = 0;i < L.length;i++) {
		if (L.data[i] > l && L.data[i] < r) cnt++;
		else L.data[i - cnt] = L.data[i];
	}
	L.length -= cnt;
	return true;
}

bool removeDuplicate(SqList& L) //06去重操作
{
	bool vis[20] = { false };
	int cnt = 0;
	for (int i = 0, j = 0;i < L.length;i++) {
		if(vis[L.data[i]]) cnt++;
		else {
			vis[L.data[i]] = true;
			L.data[j++] = L.data[i];
		}
	}
	L.length -= cnt;
	return true;
}

SqList merge(SqList L1, SqList L2) //07合并两个有序顺序表 
{
	SqList retL;
	init(retL);
	int i, j;
	for (i = 0, j = 0;i < L1.length && j < L2.length;) {
		if (L1.data[i] <= L2.data[j]) retL.data[retL.length++] = L1.data[i++];
		else retL.data[retL.length++] = L2.data[j++];
	}
	while(i < L1.length) retL.data[retL.length++] = L1.data[i++];
	while(j < L2.length) retL.data[retL.length++] = L2.data[j++];
	return retL;
}
void reverse(int data[], int l, int r) //逆置data数组中l到r之间的二元素，包括边界
{
	for (int i = l, j = r;i < j;i++, j--) {
		swap(data[i], data[j]);
	}
}
void Swap(int data[], int m, int n) //08 将前m个元素在前，n个元素在后，更改为n个元素在前，m个元素在后
{
	/*
	a[1],a[2],a[3],b[1],b[2],b[3],b[4]
	step1: b[4],b[3],b[2],b[1],a[3],a[2],a[1]
	step 2 3: b[1],b[2],b[3],b[4],a[1],a[2],a[3]
	*/
	reverse(data, 0, m + n - 1);//先将整个数组逆置
	reverse(data, 0, n - 1);//逆置前n个元素
	reverse(data, n, m + n - 1);//逆置后m个元素
}

bool binarySearch(SqList &L,int x) //09 二分查找
{
	int l = 0;
	int r = L.length - 1;
	while(l < r) {
		int mid = l + r >> 1;
		if (L.data[mid] >= x) r = mid; //此种方法找的是第一个大于等于x的元素的位置
		else l = mid + 1;
	}
	if (L.data[l] == x) {
		if (l + 1 < L.length) {
			swap(L.data[l], L.data[l + 1]);
		}
		//若已经是最后一个元素，则无需与后继元素交换，因为无后继元素
		return true;
	}
	else {
		for (int i = L.length;i > l;i--)
			L.data[i] = L.data[i - 1];
		L.data[l] = x;
		L.length++;
		return false;
	}
}
int main() {
	RAND.seed(time(0));
	SqList sqList; init(sqList); //初始化随机顺序表
	SqList sqListOrder; init(sqListOrder); //初始化有序顺序表
	cout << "请输入构造的顺序表长度: ";
	int n; cin >> n;
	if (n > MaxSize) {
		cout << "表长有限，无法容纳这么多元素" << endl;
		return 0;
	}
	sqList = creat(n, false);
	sqListOrder = creat(n, true);
	cout << "sqList: ";
	print(sqList);
	cout << "sqListOrder: ";
	print(sqListOrder);
	int e;
	bool response;
	
	cout << "<---01 删除最小的元素, 并用最后一个元素填补空缺--->" << endl;
	SqList tempList = sqList; //使用随机顺序表
	response = eraseMinElem(tempList, e);
	if (response) {
		cout << "Before: ";
		print(sqList);
		cout << "After: ";
		print(tempList);
		cout << "被删除的元素值为：" << e << endl;
	}
	cout << "<---02 逆置顺序表中的所有元素--->" << endl;
	tempList = sqList; //使用随机顺序表
	response = reverse(tempList);
	if (response) {
		cout << "Before: ";
		print(sqList);
		cout << "After: ";
		print(tempList);
	}

	cout << "<---03 删除表中所有的x--->" << endl;
	tempList = sqList;//使用随机顺序表
	int idx = RAND() % n;//从顺序表中随便取一个位置
	int x = tempList.data[idx];//以随机选出的位置上的值作为被删除的数
	cout << "删除表中所有的" << x << endl;
	response = eraseAllx(tempList,x);
	if (response) {
		cout << "Before: ";
		print(sqList);
		cout << "After: ";
		print(tempList);
	}
	
	cout << "<---04 删除表中元素值在给定区间范围内的数（不包含边界）--->" << endl;
	tempList = sqList;
	int l = RAND() % 10 + 1;
	int r = RAND() % 10 + 1;
	if (r < l) swap(l, r);//此处保证左边界小于右边界
	cout << "左边界: " << l << ", 右边界: " << r << endl;
	response = eraseAllLR(tempList, l, r, false);
	if (response) {
		cout << "Before: ";
		print(sqList);
		cout << "After: ";
		print(tempList);
	}

	cout << "<---05 删除表中元素值在给定区间范围内的数（包含边界）--->" << endl;
	tempList = sqList;
	l = RAND() % 10 + 1;
	r = RAND() % 10 + 1;
	if (r < l) swap(l, r);//此处保证左边界小于右边界
	cout << "左边界: " << l << ", 右边界: " << r << endl;
	response = eraseAllLR(tempList, l, r, true);
	if (response) {
		cout << "Before: ";
		print(sqList);
		cout << "After: ";
		print(tempList);
	}

	cout << "<---06 删除表中所有重复的值，剩余的元素按第一次出现的相对位置保持不变--->" << endl;
	tempList = sqList;
	response = removeDuplicate(tempList);
	if (response) {
		cout << "Before: ";
		print(sqList);
		cout << "After: ";
		print(tempList);
	}

	cout << "<---07 合并两个有序顺序表--->" << endl;
	SqList tempListOrder1 = creat(n / 2, true);
	SqList tempListOrder2 = creat(n / 2, true);
	SqList tempListOrder = merge(tempListOrder1, tempListOrder2);
	cout << "list1: ";
	print(tempListOrder1);
	cout << "List2: ";
	print(tempListOrder2);
	cout << "mergeList: ";
	print(tempListOrder);

	cout << "<---08 颠倒前m个元素与后n个元素的位置--->" << endl;
	tempList = sqList;
	int M = RAND() % n;
	int N = n - M;
	cout << "m: " << M << ", n: " << N << endl;
	cout << "Before: ";
	print(sqList);
	Swap(tempList.data,M,N);
	cout << "After: ";
	print(tempList);

	cout << "<---09 二分查找某个元素的值--->" << endl;
	tempList = sqListOrder;//使用有序顺序表
	x = RAND() % 10; //随机生成一个数
	cout << "x: " << x << endl;
	cout << "Before: ";
	print(sqListOrder);
	response = binarySearch(tempList, x);
	if (response) cout << "找到" << x << endl;
	else cout << "未找到" << x << endl;
	cout << "After: ";
	print(tempList);
	return 0;
}