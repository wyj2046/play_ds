#include <iostream>
#include <string>

using namespace std;

int traditional_match(const string& target, const string& pattern)
{
    int target_length = target.size();
    int pattern_length = pattern.size();

    int target_index = 0;
    int pattern_index = 0;

    while (target_index < target_length && pattern_index < pattern_length)
    {
	if (target[target_index] == pattern[pattern_index])
	{
	    ++target_index;
	    ++pattern_index;
	}
	else
	{
	    target_index = target_index - pattern_index + 1;
	    pattern_index = 0;
	}
    }

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
    cout << traditional_match("goodgoogle", "google") << endl;
    return 0;
}
