#include <iostream>

using namespace std;

template <typename T>
void counting_sort(T input_array[], int length, T output_array[], int max_value)
{
    T* count_array = new T[max_value+1];
    for (int i = 0; i <= max_value; ++i)
    {
	count_array[i] = 0;
    }
    
    for (int i = 0; i < length; ++i)
    {
	count_array[input_array[i]] += 1;
    }

    for (int i = 1; i <= max_value; ++i)
    {
	count_array[i] += count_array[i-1];
    }

    for (int i = length-1; i >= 0; --i)
    {
	count_array[input_array[i]] -= 1;    //因为数组下标从0开始，所以这个放在前面！操 问题就是出在这了
	output_array[count_array[input_array[i]]] = input_array[i];
    }
    
    delete [] count_array;
}

template <typename T>
void radix_count_sort(T digit_array[], int max_value, T input_array[], int length)
{
    T* count_array = new T[max_value+1];
    T* temp_array = new T[length];

    for (int i = 0; i <= max_value; ++i)
    {
	count_array[i] = 0;
    }

    for (int i = 0; i < length; ++i)
    {
	++count_array[digit_array[i]];
    }

    for (int i = 1; i <= max_value; ++i)
    {
	count_array[i] += count_array[i-1];
    }

    for (int i = length-1; i >= 0; --i)
    {
	--count_array[digit_array[i]];
	temp_array[count_array[digit_array[i]]] = input_array[i];    // 这里注意，是把待排序的数组赋值
    }

    for (int i = 0; i < length; ++i)
    {
	input_array[i] = temp_array[i];
    }

    delete [] count_array;
    delete [] temp_array;
}

template <typename T>
void radix_sort(T array[], int length)
{
    T* digit_array = new T[length];    // 申请存放基数（某个位数）的空间

    int radix_base = 1;
    bool flag = false;

    while (!flag)
    {
	flag = true;
	radix_base *= 10;
	
	for (int i = 0; i < length; ++i)
	{
	    digit_array[i] = array[i] % radix_base;    // 求出某位数上的数当基数
	    digit_array[i] /= radix_base / 10;
	    if (digit_array[i] > 0)
	    {
		flag = false;
	    }
	}

	if (flag)
	{
	    break;
	}
	radix_count_sort(digit_array, 10, array, length);
    }

    delete [] digit_array;
}

int main(int argc, char *argv[])
{
    int array[] = {43,65,34,5,8,34,23,0,45,34};
    int array_length = sizeof(array) / sizeof(array[0]);

    // int* array_B = new int[array_length];

    // counting_sort(array, array_length, array_B, 5);
    // for (int i = 0; i < array_length; ++i)
    // {
    // 	cout << array_B[i] << ' '; 
    // }
    // cout << endl;
    // delete [] array_B;

    radix_sort(array, array_length);
    for (int i = 0; i < array_length; ++i)
    {
	cout << array[i] << ' ';
    }
    cout << endl;
    
    return 0;
}

