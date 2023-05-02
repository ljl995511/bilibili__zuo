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


//!!!!��һ��������ܶ��� 

//���ַ����������������Ƿ������ֵ
template<class T>
bool Bisection(T* arr, int n, int num)
{
	if (arr == nullptr || n == 0) return false;
	int L = 0;
	int R = n - 1;
	int mid = 0;
	//ֻҪ��С���Ҿ�һֱ����
	while (L < R) {
		mid = L + ((R - L) >> 1);
		if (arr[mid] == num)
			return true;
		else if (arr[mid] > num) R = mid - 1;//����м�ֵ����Ŀ��ֵ����˵��Ŀ��ֵһ�����м����࣬���Խ��Ҳ��R����ָ��mid�����
		else L = mid + 1;//����м�ֵС��Ŀ��ֵ����˵��Ŀ��ֵһ���м���Ҳ࣬���Խ���������ֱ�����Ƶ��м�ֵ�������Ҳ�
	}
	return arr[L] == num;//�������ѭ��ʱ���ж�һ��arr[L]����Ϊÿ�μ����м�ֵmidʱ���ȡ��
	                     //����ֱ��ȥ��С������,���Ե�R����L+1ʱ��mid�͵�����L.....

}



//���ַ�������������>=ĳ����������λ��
template<class T>
int Bisection_Greater(T* arr, int n, T value) {
	if (arr == nullptr || n == 0) return -1;
	int L = 0;
	int R = n - 1;
	int index = -1;//������¼����λ��
	while (L <= R)
	{
		int mid = L + ((R - L) >> 1);
		//���mid����value��Ȼ�� R����mid��߼�������
		//���midС�ڻ����value,����L����mid�ұߣ�index==mid ,���������ҿ��Ե���value��ֵ
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



//���ַ�������������<=ĳ�������Ҳ��λ��
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



//���ַ��Ҿֲ���Сֵ�������������ڲ��ȣ�
//���ھֲ���С�Ķ���
/*  1)   0  1  �оֲ���СΪ0
*   2��  N-1  N  �����N<N-1 ��ֲ���СΪN
*   3)   ���  i-1  i  i+1 �� i�ȱ�i-1СҲ��i+1С,��i Ϊ�ֲ���С
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
		//�м�ֵ�������,��������һ���ֲ���С��������
		if (arr[mid] > arr[mid - 1]) {
			R = mid - 1;
		}
		//�м�ֵ�����Ҳ�С����࣬�����һ���ֲ���С���Ҳ�,�Ҳ����
		else if (arr[mid] > arr[mid + 1])
			L = mid + 1;
		//���м�ֵ��С���Ҳ���С�����,��mid��Ϊ�ֲ���С��ֱ��return  mid
		else return mid;
	}
	return L;
}



//ĳһ���������������Σ���������������ż����,ֱ�ӱ�������,���
int Onling_index(int* arr, int n)
{
	int result = 0;
	for (int i = 0; i < n; i++)
		result ^= arr[i];
	return result;
}



//��ȡ�����������Ҳ��һ��1
int Index_Far_Right(int value)
{
	int result = 0;
	result = value & ((~value) + 1);
	return result;
}




//������һ�������������������Σ���������������ż����
//�ҵ�����ӡ��������
void Double_Odd(int* arr, int n)
{
	int eor = 0;
	int result = 0;
	int result2 = 0;
	for (int i = 0; i < n; i++)
		eor ^= arr[i];
	//eor Ϊ�����ε������������
	int eor1 = eor & ((~eor) + 1);//eor1Ϊ���������ĳλΪ1���Ǹ�����
	//��������ֽ�㽫�����������ε����������
	for (int i = 0; i < n; i++) {
		if (arr[i] & eor1)
			result ^= arr[i];
	}
	result2 = eor ^ result;
	cout << "�����������ֱ��� :  " << result << endl;
	cout << "  ��  " << result2 << endl;
}



//�ҳ�������1�ĸ���
int bit1counts(int N)
{
	int count = 0;
	while (N != 0) {
		int rightOne = N & ((~N) + 1);//��ȡ�������Ҳ��1
		count++;
		N^= rightOne;//������Ҳ�1��ֱ��N==0Ϊֹ
	}
	return count;
}


//�ݹ����������ֵ
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

//�ݹ�����
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


//�鲢
void merge(int* arr, int L, int R , int M) {
	int* help = new int[R - L + 1];//����һ���м����飬���ڴ洢����ú��ֵ,����R-L+1��ԭ����R-Lʱ����0λ�ã����м���0λ��
	int i = 0;//help������±�
	int p1 = L;//p1Ϊ���鲿�ֵ��±�
	int p2 = M + 1;//P2Ϊ������±�,��1�Ǵ�Mid+1λ�ÿ�ʼ
	while (p1 <= M && p2 <= R)//ѭ������help����ֱ���κ�һ�����������
	{
		help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];//��++����˼�������ټ�
	}
	//��������ж��κ�һ����δ������Ļ����Ͳ��뵽help������
	while (p1 <= M)
		help[i++] = arr[p1++];
	while (p2 <= R)
		help[i++] = arr[p2++];
	//���µ�������ľɵ�����
	for (i = 0; i < (R - L + 1); i++)
		arr[L + i] = help[i];
	delete[] help;
}



//�鲢����2
void merge_sort2(int* arr,int n) {
	if (arr == nullptr || n < 2)
		return;
	int mergeSize = 1;//��ǰ��������鳤��Ĭ�ϵ�һλ�Ѿ�����
	while (mergeSize < n)
	//��mergeSize���ڵ���nʱ��˵�������Ѿ�ȫ������
	{
		int L = 0;//ÿһ�ν�ѭ��ʱ����L=0
		while (L < n)
		{
			int M = L + mergeSize - 1;//ѭ����ÿ�θ����м�ֵ���Ƚ������Ϊ����������м��±�
			if (M >= n)//��M>=nʱ��˵�������Ѿ���ȫ����
				break;
			int R = M + mergeSize > n - 1 ? n - 1 : M + mergeSize;
			//��ΪR�����Ѿ�����ƽ����Ϊ����
			merge(arr, L, R, M);//ͨ��merge���������������ͨ���鲢��������
			L = R + 1;//�ƶ�Lʹ��L�ƶ�����һ���ֿ������
		}
		if (mergeSize > n / 2) {
			break;//��mergeSize>���鳤�ȵ�һ��ʱ��˵�����������Ѿ�������
		}
		mergeSize <<= 1;//ÿ��ѭ�������Ѿ������������X2
	}
}


/*�ݹ���С��*/
//��Ҫ����ҲҪ��С�ͣ�С��:ÿһ������߱��Լ�С�������ܺͣ�
int sum_small(int* arr, int n)
{
	if (arr==nullptr || n < 2)
		return 0;
	return process_sum(arr, 0, n - 1);
}


int process_sum(int* arr, int L, int R)
{
	//��L==Rʱ���ݹ���������ʣ�µ��Ǹ�����һ��û��С��
	if (L == R)
		return 0;
	int M = L + ((R - L) >> 1);//λ������ƽ��ֵ
	return process_sum(arr, L, M) + process_sum(arr, M + 1, R) + merge_sum(arr, L, M, R);
	//�ݹ���������ͬʱ��¼��С�����ܺ�
}


//ע�͸�֮ǰ��merger�鲢����һ���������������һ����С��
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

//��Ҫ����ҲҪ��С�ͣ�С��:ÿһ������߱��Լ�С�������ܺͣ�
/*�ݹ���С��*/


/*��ɫ����������*/
/*��������*/
//����������߹涨Ϊ  С����   �м�Ϊ������   �ұ�Ϊ������
//��arr[ x<index    x==index   x>index   ]
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


//����1.0,ÿ�θ㶨һ������ͨ���������������ø㶨���Ǹ���
void quick_sort1(int* arr, int L, int n) {
	if (arr == nullptr || n < 2)
		return;
	process_quick_sort1(arr, L, n - 1);
}


//����1.0�ĵݹ����򷽷�
void process_quick_sort1(int* arr, int L, int R)
{
	if (L >= R)
		return;
	int M = partition1(arr, L, R);
	process_quick_sort1(arr, L, M-1);
	process_quick_sort1(arr, M + 1, R);
}

//�������������⣬ÿ�θ㶨һ���������������±귵��
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


/*����2.0*/
void quick_sort2(int* arr, int L, int n)
{
	if (arr == nullptr || n < 2)
		return;
	process_quick_sort2(arr, L, n - 1);
}

/*����2.0�ĵݹ�*/
void process_quick_sort2(int* arr, int L, int R)
{
	if (L >= R)
		return;
	pair<int,int> M = partition2(arr, L, R);
	process_quick_sort2(arr, L, M.first-1);
	process_quick_sort2(arr, M.second+1, R);
}


/*����2.0�ľ���ʵ�֣�ÿ�θ㶨һ�������������䷵��*/
/*pair ����ÿ�η�������ֵ��tuple(Ԫ��)����ÿ�η����������߸���ֵ�����ʹ��tuple��Ϊ�������ͣ�����ֵֵӦ���� make_tuple(....)*/
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

/*����1.0�����2.0������������O(n^2)*/
/*���ǿ���3.0�����ѡ��һ����*/
/*���ѡ���ͨ����ѧ���������ó�����3.0��ʱ�临�Ӷ�ΪO(n*logn)*/

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