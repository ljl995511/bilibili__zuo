#include<iostream>
#include<ctime>
#include<vector>
#include"Stack.h"
//#include"¶ÔÊýÆ÷.h"
#include"DoubleList.h"
#include"List.h"
//#include"QuEue.h"
#include"Sort.h"
#include"BisecTion.h"
//#include"DoubleList_Stack.h"
extern const int MAX=20;
using namespace std;


int main() {
	int arr[] = {2,1,5,8,9,6,3,4,3,5,4,7,6,8,9,5,1,2,4,17,4,5,28,4,4,42,45,12};
	//int ar[10] = { 1,2,3,4,5,6,8,9,10};
	quick_sort3(arr, 0,28);
	for (int i = 0; i < 28; i++)
		cout << arr[i] << "   ";
	//cout <<process(arr, 0, 8);
	return 0;
}