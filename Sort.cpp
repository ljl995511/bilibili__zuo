#include "Sort.h"

bool Select_sort(int* arr, int n)
{
	if (arr == nullptr || n < 2)
		return 0;
	// 0 -- n-1
	// 1 -- n-1
	// 2 -- n-1
	for (int i = 0; i < n-1;i++) {// i -- n-1
		//最小值在哪个位置上 i -- n-1
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			minIndex = arr[j] < arr[minIndex] ? j : minIndex;
		}
		swap_arr(arr, i, minIndex);
	}
}

void swap_arr(int*& arr, int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

bool bubbleSort(int* arr, int n)
{
	if (arr == nullptr || n < 2)
		return -1;
	//0 -- n-1
	//0 -- n-2
	//0 -- n-3
	for (int e = n - 1; e > 0; e--) {//0 -- e
		//0 1
		//1 2
		//2 3
		//e-1 e
		//做比较
		for (int i = 0; i < e; i++) {
			if (arr[i] > arr[i + 1])
				swap_bubble(arr, i, i + 1);
		}
	}
}

void swap_bubble(int*& arr, int i, int j)
{
	//i和j是一个位置的话，会出错
	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
	//这里的交换位置使用了异或的运算
	//即：令a(1)=a^b ===>>此时的a(1)==a^b,b==b
	//      b=a(1)^b == a^b^b == a  ,  =====>此时的a(1)不变，仍然等于a^b-----b的值发生了改变b==a
	//   然后令a=a(1)^b == a^b^a ==  b  即完成了互换数值
}

bool insertionSort(int* arr, int n)//这是插入排序
{
	if (arr == nullptr || n < 2) return 0;//判断数组是否为空，或者是否只有一个数
	//这是第一层，令i为数组最后一个元素的索引号
	for (int i = 1; i < n; i++) {
		//第二层循环，令J等于i的前一个元素
		//arr往前看
		//0-2有序
		//0-3有序
		//0-4有序
		//以此类推
		for (int j =i -1; j >= 0 && arr[j] > arr[j+1]; j--) {
			swap_bubble(arr, j,j+1);
		}
	}
}