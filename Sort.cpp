#include "Sort.h"

bool Select_sort(int* arr, int n)
{
	if (arr == nullptr || n < 2)
		return 0;
	// 0 -- n-1
	// 1 -- n-1
	// 2 -- n-1
	for (int i = 0; i < n-1;i++) {// i -- n-1
		//��Сֵ���ĸ�λ���� i -- n-1
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
		//���Ƚ�
		for (int i = 0; i < e; i++) {
			if (arr[i] > arr[i + 1])
				swap_bubble(arr, i, i + 1);
		}
	}
}

void swap_bubble(int*& arr, int i, int j)
{
	//i��j��һ��λ�õĻ��������
	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
	//����Ľ���λ��ʹ������������
	//������a(1)=a^b ===>>��ʱ��a(1)==a^b,b==b
	//      b=a(1)^b == a^b^b == a  ,  =====>��ʱ��a(1)���䣬��Ȼ����a^b-----b��ֵ�����˸ı�b==a
	//   Ȼ����a=a(1)^b == a^b^a ==  b  ������˻�����ֵ
}

bool insertionSort(int* arr, int n)//���ǲ�������
{
	if (arr == nullptr || n < 2) return 0;//�ж������Ƿ�Ϊ�գ������Ƿ�ֻ��һ����
	//���ǵ�һ�㣬��iΪ�������һ��Ԫ�ص�������
	for (int i = 1; i < n; i++) {
		//�ڶ���ѭ������J����i��ǰһ��Ԫ��
		//arr��ǰ��
		//0-2����
		//0-3����
		//0-4����
		//�Դ�����
		for (int j =i -1; j >= 0 && arr[j] > arr[j+1]; j--) {
			swap_bubble(arr, j,j+1);
		}
	}
}