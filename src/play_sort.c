#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


void swap(int* x, int* y)    //如果两个数相等，就不执行位运算交换。因为如果两数相等，结果会是0
{
    if (*x != *y)
    {
	*y = *x ^ *y;
	*x = *x ^ *y;
	*y = *x ^ *y;
    }
}

void bubble_sort0(int array[], int length)
{
    for (int i = 0; i < length-1; ++i)
    {
	for (int j = i+1; j < length; ++j)
	{
	    if (array[i] > array[j])
	    {
		swap(&array[i], &array[j]);
	    }
	}
    }
}

void bubble_sort(int array[], int length)
{
    for (int i = 0; i < length-1; ++i)
    {
	for (int j = length-1; j >= i; --j)  // 注意j是从后往前循环
	{
	    if (array[j] > array[j+1])
	    {
		swap(&array[j], &array[j+1]);
	    }
	}
    }
}

void bubble_sort2(int array[], int length)
{
    bool is_disorder = true;
    for (int i = 0; i < length-1 && is_disorder; ++i)
    {
	is_disorder = false;
	for (int j = length-1; j >= i; --j)
	{
	    if (array[j] > array[j+1])
	    {
		swap(&array[j], &array[j+1]);
		is_disorder = true;
	    }
	}
    }
}

void select_sort(int array[], int length)
{
    for (int i = 0; i < length-1; ++i)
    {
	int min_index = i;
	for (int j = i+1; j < length; ++j)
	{
	    if (array[min_index] > array[j])
	    {
		min_index = j;
	    }
	}
	if (min_index != i)
	{
	    swap(&array[i], &array[min_index]);
	}
    }
}

void insert_sort(int array[], int length)
{
    for (int i = 1; i < length; ++i)    //尚未排序的部分
    {
	for (int j = i; j >= 1; --j)    //已经排好序的部分
	{
	    if (array[j-1] > array[j])
	    {
		swap(&array[j-1], &array[j]);
	    }
	}
    }
}

void shell_sort(int array[], int length)    //所用算法在编程珠玑p211
{
    int increment = 0;
    for (increment = 1; increment < length; increment = 3*increment + 1)    //求增量
    {
	;
    }

    while (increment > 0)
    {
	increment /= 3;    //增量不断减小，直至为0
	for (int i = increment; i < length; ++i)    //这个地方开始类似插入排序
	{
	    for (int j = i; j >= increment; j -= increment)
	    {
		if (array[j-increment] > array[j])
		{
		    swap(&array[j-increment], &array[j]);
		}
		else
		{
		    break;
		}
	    }
	}
    }
}

// 堆排序参考算法导论伪代码
void max_heapify(int array[], int heap_size, int index)
{
    int left_index = 2*index;
    int right_index = 2*index+1;

    int largest_index = 0;
    
    if (left_index < heap_size && array[left_index] > array[index])
    {
	largest_index = left_index;
    }
    else
    {
	largest_index = index;
    }

    if (right_index < heap_size && array[right_index] > array[largest_index])
    {
	largest_index = right_index;
    }

    if (largest_index != index)
    {
	swap(&array[index], &array[largest_index]);
	max_heapify(array, heap_size, largest_index);
    }
}
// 堆排序参考算法导论伪代码
void build_max_heap(int array[], int length)
{
    int heap_size = length;
    for (int i = length/2; i >= 0; --i)
    {
	max_heapify(array, heap_size, i);
    }
}
// 堆排序参考算法导论伪代码
void heap_sort(int array[], int length)
{
    build_max_heap(array, length);

    int heap_size = length;
    for (int i = length-1; i >= 1; --i)
    {
	swap(&array[0], &array[i]);
	--heap_size;
	max_heapify(array, heap_size, 0);
    }
}

#define INFINITE 10000

// 归并排序参考算法导论伪代码
void merge(int array[], int p, int q, int r)
{
    int left_length = q - p + 1;
    int right_length = r - q;
    
    int* left_array = (int*)malloc(sizeof(int) * (left_length+1));
    int* right_array = (int*)malloc(sizeof(int) * (right_length+1));
    
    for (int i = 0; i < left_length; ++i)
    {
	left_array[i] = array[p+i];
    }
    for (int j = 0; j < right_length; ++j)
    {
	right_array[j] = array[q+j+1];
    }

    left_array[left_length] = INFINITE;
    right_array[right_length] = INFINITE;

    int left_index = 0;
    int right_index = 0;

    for (int array_index = p; array_index <= r; ++array_index)
    {
	if (left_array[left_index] <= right_array[right_index])
	{
	    array[array_index] = left_array[left_index];
	    ++left_index;
	}
	else
	{
	    array[array_index] = right_array[right_index];
	    ++right_index;
	}
    }
}

// 归并排序参考算法导论伪代码
void merge_sort(int array[], int left, int right)
{
    if (left < right)
    {
	int center = (left+right)/2;
	merge_sort(array, left, center);
	merge_sort(array, center+1, right);
	merge(array, left, center, right);
    }
}


// 快排参考算法导论伪代码
/* int partition(int array[], int p, int r) */
/* { */
/*     int x = array[r]; */
/*     int i = p-1; */
/*     for (int j = p; j <= r-1; ++j) */
/*     { */
/* 	if (array[j] <= x) */
/* 	{ */
/* 	    ++i; */
/* 	    swap(&array[i], &array[j]); */
/* 	} */
/*     } */
/*     swap(&array[i+1], &array[r]); */
/*     return i + 1; */
/* } */

int partition(int array[], int low, int high)
{
    int temp = array[high];
    int j = low - 1;
    for (int i = low; i < high; ++i)
    {
	if (array[i] <= temp)
	{
	    ++j;
	    swap(&array[i], &array[j]);
	}
    }
    swap(&array[j+1], &array[high]);
    return j+1;
}

// 快排参考算法导论伪代码
/* void quick_sort(int array[], int p, int r) */
/* { */
/*     if (p < r) */
/*     { */
/* 	int q = partition(array, p, r); */
/* 	quick_sort(array, p, q-1); */
/* 	quick_sort(array, q+1, r); */
/*     } */
/* } */

void quick_sort(int array[], int low, int high)
{
    if (low < high)
    {
	int pivot = partition(array, low, high);
	quick_sort(array, low, pivot-1);
	quick_sort(array, pivot+1, high);
    }
}

int random(int m, int n)
{
    srand((unsigned)time(NULL));
    return m + rand()%(n-m+1);
}

int random_partition(int array[], int low, int high)
{
    int i = random(low, high);
    swap(&array[i], &array[high]);
    return partition(array, low, high);
}

int main(int argc, char *argv[])
{
    // int array[] = {2, 8, 7, 1, 3, 5, 6, 4};
    int array[] = {256, 19, 3, 21, 7, 5, 18};
    int array_length = sizeof(array) / sizeof(array[0]);
    // bubble_sort0(array, array_length);
    // bubble_sort(array, array_length);
    // bubble_sort2(array, array_length);
    // select_sort(array, array_length);
    // insert_sort(array, array_length);
    // shell_sort(array, array_length);
    // heap_sort(array, array_length);
    // merge_sort(array, 0, array_length);
    quick_sort(array, 0, array_length-1);    //快排这个地方调用的时候第三个参数到底减不减1？效果都一样
					     //调用时第三个参数应该为array_length-1，
					     //因为算法导论中的数组是这么写的A[p,r] A[r]为边界元素
    for (int i = 0; i < array_length; ++i)
    {
	printf ("%d ", array[i]);
    }
    printf ("\n");
    return 0;
}


// From Wikipedia -- Merge Sort
/* array A[] has the items to sort; array B[] is a work array */
/* BottomUpSort(int n, array A[n], array B[n]) */
/* { */
/*     int width; */
 
/*     /\* each 1-element run in A is already "sorted". *\/ */
 
/*     /\* Make successively longer sorted runs of length 2, 4, 8, 16... until whole array is sorted*\/ */
/*     for (width = 1; width < n; width = 2 * width) */
/*     { */
/* 	int i; */
 
/* 	/\* array A is full of runs of length width *\/ */
/* 	for (i = 0; i < n; i = i + 2 * width) */
/*         { */
/* 	    /\* merge two runs: A[i:i+width-1] and A[i+width:i+2*width-1] to B[] *\/ */
/* 	    /\*  or copy A[i:n-1] to B[] ( if(i+width >= n) ) *\/ */
/* 	    BottomUpMerge(A, i, min(i+width, n), min(i+2*width, n), B); */
/*         } */
 
/* 	/\* now work array B is full of runs of length 2*width *\/ */
/* 	/\* copy array B to array A for next iteration *\/ */
/* 	/\*   a more efficient implementation would Swap the roles of A and B *\/ */
/* 	CopyArray(A, B, n); */
/* 	/\* now array A is full of runs of length 2*width *\/ */
/*     } */
/* } */
 
/* BottomUpMerge(array A[], int iLeft, int iRight, int iEnd, array B[]) */
/* { */
/*     int i0 = iLeft; */
/*     int i1 = iRight; */
/*     int j; */
 
/*     /\* while there are elements in the left or right lists *\/ */
/*     for (j = iLeft; j < iEnd; j++) */
/*     { */
/* 	/\* if left list head exists and is <= existing right list head *\/ */
/* 	if (i0 < iRight && (i1 >= iEnd || A[i0] <= A[i1])) */
/*         { */
/* 	    B[j] = A[i0]; */
/* 	    i0 = i0 + 1; */
/*         } */
/* 	else */
/*         { */
/* 	    B[j] = A[i1]; */
/* 	    i1 = i1 + 1; */
/*         } */
/*     } */
/* } */
