#include "对数器.h"
#include<istream>
#include<stdlib.h>
#include<time.h>
using namespace std;


int* generateRandomArray(int maxSize, int maxValue)
{
    //rand()产生一个随机数
    srand(time(NULL));
    int* arr = new int[(int)((maxSize + 1) * (float)(rand()/(rand()+1)))];
    for (int i = 0; i < (int)((maxSize + 1) * (float)(rand() / (rand() + 1))); i++) {
        srand(time(NULL));
        arr[i] = (int)((maxValue + 1) * rand()) - (int)(maxValue * rand());
    }
    return arr;
}
