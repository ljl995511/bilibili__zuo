#pragma once
int process_sum(int* arr, int L, int R);
int merge_sum(int* arr, int L, int M, int R);
void swap_Lands(int* arr, int a, int b);
void merge(int* arr, int L, int R, int M);
int partition1(int* arr, int L, int R);
pair<int, int>partition2(int* arr, int L, int R);
void process_quick_sort1(int* arr, int L, int R);
void process_quick_sort2(int* arr, int L, int R);
void quick_sort3(int* arr, int L, int n);
void process_quick_sort3(int* arr, int L, int R);


//!!!!不一定有序才能二分 

//二分法查找有序数组中是否有这个值
template<class T>
bool Bisection(T* arr, int n, int num)
{
	if (arr == nullptr || n == 0) return false;
	int L = 0;
	int R = n - 1;
	int mid = 0;
	//只要左小于右就一直二分
	while (L < R) {
		mid = L + ((R - L) >> 1);
		if (arr[mid] == num)
			return true;
		else if (arr[mid] > num) R = mid - 1;//如果中间值大于目标值，则说明目标值一定在中间的左侧，所以将右侧的R索引指到mid的左边
		else L = mid + 1;//如果中间值小于目标值，则说明目标值一定中间的右侧，所以将左侧的索引直接右移到中间值索引的右侧
	}
	return arr[L] == num;//最后跳出循环时再判断一次arr[L]是因为每次计算中间值mid时如果取整
	                     //则是直接去掉小数部分,所以当R等于L+1时，mid就等于了L.....

}



//二分法找有序数组中>=某个数最左侧的位置
template<class T>
int Bisection_Greater(T* arr, int n, T value) {
	if (arr == nullptr || n == 0) return -1;
	int L = 0;
	int R = n - 1;
	int index = -1;//用来记录最左位置
	while (L <= R)
	{
		int mid = L + ((R - L) >> 1);
		//如果mid大于value，然后 R来到mid左边继续二分
		//如果mid小于或等于value,则令L来到mid右边，index==mid ,继续二分找可以等于value的值
		if (arr[mid] > value) {
			//index = mid;
			R = mid - 1;
		}
		else {
			index = mid;
			L = mid + 1;
		}

	}
	return index;

}



//二分法找有序数组中<=某个数最右侧的位置
template<class T>
int Bisection_Less(T* arr, int n, T value) {
	if (arr == nullptr || n == 0) return -1;
	int L = 0;
	int R = n - 1;
	int index = -1;
	while (L <= R)
	{
		int mid = L + ((R - L) >> 1);
		if (arr[mid] > value) R = mid - 1;
		else {
			index = mid;
			L = mid + 1;
		}
	}
	return index;

}



//二分法找局部最小值（数组无序，相邻不等）
//关于局部最小的定义
/*  1)   0  1  中局部最小为0
*   2）  N-1  N  中如果N<N-1 则局部最小为N
*   3)   如果  i-1  i  i+1 中 i既比i-1小也比i+1小,则i 为局部最小
*/
template<class T>
int Local_mini(T* arr, int n) {
	if (arr[0] < arr[1])
		return 0;
	if (arr[n - 1] < arr[n - 2])
		return n-1;
	int L = 0;
	int R = n - 2;
	int mid = 0;
	while (L < R)
	{
		mid = L + ((R - L) >> 1);
		//中间值大于左侧,则左侧必有一个局部最小，左侧二分
		if (arr[mid] > arr[mid - 1]) {
			R = mid - 1;
		}
		//中间值大于右侧小于左侧，则必有一个局部最小在右侧,右侧二分
		else if (arr[mid] > arr[mid + 1])
			L = mid + 1;
		//若中间值既小于右侧又小于左侧,则mid即为局部最小，直接return  mid
		else return mid;
	}
	return L;
}



//某一种数出现了奇数次，其他数均出现了偶数次,直接遍历数组,异或
int Onling_index(int* arr, int n)
{
	int result = 0;
	for (int i = 0; i < n; i++)
		result ^= arr[i];
	return result;
}



//提取整型数的最右侧的一个1
int Index_Far_Right(int value)
{
	int result = 0;
	result = value & ((~value) + 1);
	return result;
}




//数组中一定两种数出现了奇数次，其他数均出现了偶数次
//找到并打印这两种数
void Double_Odd(int* arr, int n)
{
	int eor = 0;
	int result = 0;
	int result2 = 0;
	for (int i = 0; i < n; i++)
		eor ^= arr[i];
	//eor 为奇数次的两个数的异或
	int eor1 = eor & ((~eor) + 1);//eor1为这个数组中某位为1的那个分类
	//利用这个分界点将这两个奇数次的数分离出来
	for (int i = 0; i < n; i++) {
		if (arr[i] & eor1)
			result ^= arr[i];
	}
	result2 = eor ^ result;
	cout << "这两个奇数分别是 :  " << result << endl;
	cout << "  与  " << result2 << endl;
}



//找出二进制1的个数
int bit1counts(int N)
{
	int count = 0;
	while (N != 0) {
		int rightOne = N & ((~N) + 1);//提取出来最右侧的1
		count++;
		N^= rightOne;//异或最右侧1，直到N==0为止
	}
	return count;
}


//递归求数组最大值
/*
* 
*/
int process(int* arr, int L,int R) {
	if (L == R)
		return arr[L];
	int mid = L + ((R - L) >> 1);
	int leftMax = process(arr, L, mid);
	int rightMax = process(arr, mid + 1, R);
	return leftMax > rightMax ? leftMax : rightMax;
}

//递归排序
void merge_sort(int* arr, int L, int R)
{
	if (L == R)
		return;
	else {
		int M = L + ((R - L) >> 1);
		merge_sort(arr, L, M);
		merge_sort(arr, M+1, R);
		merge(arr, L, R, M);

	}
}


//归并
void merge(int* arr, int L, int R , int M) {
	int* help = new int[R - L + 1];//创建一个中间数组，用于存储排序好后的值,创建R-L+1的原因是R-L时减了0位置，所有加上0位置
	int i = 0;//help数组的下标
	int p1 = L;//p1为左组部分的下标
	int p2 = M + 1;//P2为右组的下标,加1是从Mid+1位置开始
	while (p1 <= M && p2 <= R)//循环插入help数组直到任何一边组遍历结束
	{
		help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];//后++的意思是先用再加
	}
	//下面的是判断任何一边组未遍历完的话，就插入到help数组中
	while (p1 <= M)
		help[i++] = arr[p1++];
	while (p2 <= R)
		help[i++] = arr[p2++];
	//用新的数组更改旧的数组
	for (i = 0; i < (R - L + 1); i++)
		arr[L + i] = help[i];
	delete[] help;
}



//归并排序2
void merge_sort2(int* arr,int n) {
	if (arr == nullptr || n < 2)
		return;
	int mergeSize = 1;//当前有序的数组长度默认第一位已经有序
	while (mergeSize < n)
	//当mergeSize大于等于n时，说明数组已经全部有序
	{
		int L = 0;//每一次进循环时，令L=0
		while (L < n)
		{
			int M = L + mergeSize - 1;//循环中每次更改中间值，既将数组分为左组右组的中间下标
			if (M >= n)//当M>=n时，说明左组已经完全有序
				break;
			int R = M + mergeSize > n - 1 ? n - 1 : M + mergeSize;
			//因为R可能已经不够平均分为右组
			merge(arr, L, R, M);//通过merge函数将左组和右组通过归并整合起来
			L = R + 1;//移动L使得L移动到下一个分块的区域
		}
		if (mergeSize > n / 2) {
			break;//当mergeSize>数组长度的一半时，说明整个数组已经有序了
		}
		mergeSize <<= 1;//每次循环都将已经有序的数组数X2
	}
}


/*递归求小和*/
//既要排序，也要求小和（小和:每一个数左边比自己小的数的总和）
int sum_small(int* arr, int n)
{
	if (arr==nullptr || n < 2)
		return 0;
	return process_sum(arr, 0, n - 1);
}


int process_sum(int* arr, int L, int R)
{
	//当L==R时，递归结束，最后剩下的那个数，一定没有小和
	if (L == R)
		return 0;
	int M = L + ((R - L) >> 1);//位运算求平均值
	return process_sum(arr, L, M) + process_sum(arr, M + 1, R) + merge_sum(arr, L, M, R);
	//递归进行排序的同时记录下小数的总和
}


//注释跟之前的merger归并排序一样，仅仅额外多了一个求小和
int merge_sum(int* arr, int L, int M, int R)
{
	int* help = new int[R - L + 1];
	int i = 0;
	int res = 0;
	int p1 = L;
	int p2 = M + 1;
	while (p1 <= M && p2 <= R)
	{
		res += arr[p1] < arr[p2] ? (R - p2 + 1) * arr[p1] : 0;
		help[i++] = arr[p1] >= arr[p2] ? arr[p2++] : arr[p1++];
	}
	while (p1 <= M)
		help[i++] = arr[p1++];
	while (p2 <= R)
		help[i++] = arr[p2++];
	for (i = 0; i < R - L + 1; i++)
	{
		arr[L+i] = help[i];
	}
	delete[] help;
	return res;
}

//既要排序，也要求小和（小和:每一个数左边比自己小的数的总和）
/*递归求小和*/


/*三色类似旗问题*/
/*荷兰国旗*/
//将数组的左半边规定为  小于区   中间为等于区   右边为大于区
//即arr[ x<index    x==index   x>index   ]
void netherLandsFlag(int* arr, int n, int index)
{
	if (arr == nullptr || n < 2)
		return;
	int less = -1;
	int more = n + 1;
	int i = 0;
	while (i < more)
	{
		if (arr[i] < index) swap_Lands(arr, ++less, i++);
		else if (arr[i] > index) swap_Lands(arr, i, --more);
		else i++;
	}
}

void swap_Lands(int* arr, int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}


//快排1.0,每次搞定一个数，通过荷兰国旗问题获得搞定的那个数
void quick_sort1(int* arr, int L, int n) {
	if (arr == nullptr || n < 2)
		return;
	process_quick_sort1(arr, L, n - 1);
}


//快排1.0的递归排序方法
void process_quick_sort1(int* arr, int L, int R)
{
	if (L >= R)
		return;
	int M = partition1(arr, L, R);
	process_quick_sort1(arr, L, M-1);
	process_quick_sort1(arr, M + 1, R);
}

//荷兰国旗类问题，每次搞定一个数并将该数的下标返回
int partition1(int* arr, int L, int R)
{
	int less = L - 1;
	int more = R;
	int index = L;
	while (index < more)
	{
		if (arr[index] < arr[R])swap_Lands(arr, index++, ++less);
		else if (arr[index] > arr[R])swap_Lands(arr, index, --more);
		else index++;
	}
	swap_Lands(arr, more, R);
	return more;
}


/*快排2.0*/
void quick_sort2(int* arr, int L, int n)
{
	if (arr == nullptr || n < 2)
		return;
	process_quick_sort2(arr, L, n - 1);
}

/*快排2.0的递归*/
void process_quick_sort2(int* arr, int L, int R)
{
	if (L >= R)
		return;
	pair<int,int> M = partition2(arr, L, R);
	process_quick_sort2(arr, L, M.first-1);
	process_quick_sort2(arr, M.second+1, R);
}


/*快排2.0的具体实现，每次搞定一批数，并将区间返回*/
/*pair 可以每次返回两个值，tuple(元组)可以每次返回三个或者更多值，如果使用tuple作为函数类型，返回值值应该是 make_tuple(....)*/
pair<int, int>partition2(int* arr, int L, int R)
{
	int less = L - 1;
	int more = R;
	int index = L;
	while (index < more)
	{
		if (arr[index] < arr[R]) swap_Lands(arr, index++, ++less);
		else if (arr[index] > arr[R]) swap_Lands(arr, index, --more);
		else index++;
	}
	swap_Lands(arr, more, R);
	return make_pair(less + 1, more);
}

/*快排1.0与快排2.0的最差情况都是O(n^2)*/
/*但是快排3.0是随机选择一个数*/
/*随机选择后通过数学期望计算后得出快排3.0的时间复杂度为O(n*logn)*/

void quick_sort3(int* arr, int L, int n)
{
	if (arr==nullptr||n<2)
		return;
	process_quick_sort3(arr, L, n - 1);
}

void process_quick_sort3(int* arr, int L, int R)
{
	if (L >= R)
		return;
	srand((int)time(0));
	swap_Lands(arr, R, L+rand()%(R-L+1));
	pair<int, int> M = partition2(arr, L, R);
	process_quick_sort3(arr, L, M.first - 1);
	process_quick_sort3(arr, M.second + 1, R);
}