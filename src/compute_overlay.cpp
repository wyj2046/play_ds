#include <iostream>
#include <string>

using namespace std;

void compute_overlay(const string& pattern)
{
    const int pattern_length = pattern.size();
    int* overlay_array = new int[pattern_length];
    int index = 0;

    overlay_array[0] = -1;
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

    for (int i = 0; i < pattern_length; ++i)
    {
	int output = overlay_array[i] + 1;
	// cout << overlay_array[i] << ' ';
	cout << output << ' ';
    }
    cout << endl;

    delete [] overlay_array;
}

int main(int argc, char *argv[])
{
    string pattern = "ababaaaba";
    compute_overlay(pattern);
    return 0;
}
