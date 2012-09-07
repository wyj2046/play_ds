#include <iostream>
#include <string>

using namespace std;

int kmp_find(const string& target, const string& pattern)
{
    int target_length = target.size();
    int pattern_length = pattern.size();

    int* overlay_array = new int[pattern_length];
    overlay_array[0] = -1;

    int index = 0;
    for (int i = 1; i < pattern_length; ++i)
    {
	index = overlay_array[i-1];
	while (index >= 0 && pattern[i] != pattern[index+1])
	{
	    index = overlay_array[index];
	}

	if (pattern[i] == pattern[index+1])
	{
	    overlay_array[i] = index + 1;
	}
	else
	{
	    overlay_array[i] = -1;
	}
    }

    int target_index = 0;
    int pattern_index = 0;

    while (target_index < target_length && pattern_index < pattern_length)
    {
	if (target[target_index] == pattern[pattern_index])
	{
	    ++target_index;
	    ++pattern_index;
	}
	else if (pattern_index == 0)
	{
	    ++target_index;
	}
	else
	{
	    pattern_index = overlay_array[pattern_index-1] + 1; 
	}
    }

    delete [] overlay_array;
    
    if (pattern_index == pattern_length)
    {
	return target_index - pattern_length;
    }
    else
    {
	return -1;
    } 
}

int main(int argc, char *argv[])
{
    cout << kmp_find("goodgoogle", "google") << endl;
    return 0;
}
