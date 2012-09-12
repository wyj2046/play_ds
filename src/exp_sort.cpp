#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void bubble_sort0(vector<T>& array)
{
    size_t length = array.size();
    for (int i = 0; i < length-1; ++i)
    {
	for (int j = i + 1; j < length; ++j)
	{
	    if (array[i] > array[j])
	    {
		swap(array[i], array[j]);
	    }
	}
    }
}

template <typename T>
void bubble_sort(vector<T>& array)
{
    size_t length = array.size();
    for (int i = 0; i < length-1; ++i)
    {
	for (int j = length-1; j >= 1; --j)
	{
	    if (array[j-1] > array[j])
	    {
		swap(array[j-1], array[j]);
	    }
	}
    }
}

template <typename T>
void bubble_sort2(vector<T>& array)
{
    size_t length = array.size();

    bool is_swap = true;    
    for (int i = 0; i < length-1 && is_swap; ++i)
    {
	is_swap = false;
	for (int j = length-1; j >= 1; --j)
	{
	    if (array[j-1] > array[j])
	    {
		swap(array[j-1], array[j]);
		is_swap = true;
	    }
	}
    }
}

template <typename T>
void select_sort(vector<T>& array)
{
    size_t length = array.size();
    int min_index = 0;
    for (int i = 0; i < length-1; ++i)
    {
	min_index = i;
	for (int j = i+1; j < length; ++j)
	{
	    if (array[min_index] > array[j])
	    {
		min_index = j;
	    }
	}
	if (min_index != i)
	{
	    swap(array[min_index], array[i]);
	}
    }
}

template <typename T>
void insert_sort(vector<T>& array)
{
    size_t length = array.size();
    for (int i = 1; i < length; ++i)
    {
	for (int j = i; j >= 1; --j)    // 注意j的范围
	{
	    if (array[j-1] > array[j])
	    {
		swap(array[j-1], array[j]);
	    }
	}
    }
}

template <typename T>
void shell_sort(vector<T>& array)
{
    size_t length = array.size();
    
    int increment = 1;    // 注意，增量一定不能在for里定义
    for (; increment < length; increment = 3*increment + 1)
    {
	;
    }

    while (increment > 0)    // 从这个while开始需要反复记住
    {
	increment /= 3;
	for (int i = increment; i < length; ++i)
	{
	    for (int j = i; j >= increment; j -= increment)
	    {
		if (array[j-increment] > array[j])
		{
		    swap(array[j-increment], array[j]);
		}
		else
		{
		    break;
		}
	    }
	}
    }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    vector<int> array;
    const int array_number = 7;
    for (int i = 0; i < array_number; ++i)
    {
	array.push_back(rand() % 100 );
    }

    // bubble_sort0(array);
    // bubble_sort(array);
    // bubble_sort2(array);
    // select_sort(array);
    // insert_sort(array);
    shell_sort(array);
    
    vector<int>::iterator iter;
    for (iter = array.begin(); iter != array.end(); ++iter)
    {
	cout << *iter << ' ';
    }
    cout << endl;
    return 0;
}
