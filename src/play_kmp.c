#include <stdio.h>
#include <stdlib.h>


void get_next(const char* pattern, int next[])
{
    next[1] = 0;
    int i = 1; //后缀
    int j = 0; //前缀

    int pattern_length = atoi(pattern);
    while (i < pattern_length)
    {
	if (j == 0 || pattern[i] == pattern[j])
	{
	    ++i;
	    ++j;
	    next[i] = j;
	}
	else
	{
	    j = next[j];
	}
    }
}

void get_nextval(const char* pattern, int nextval[])
{
    nextval[1] = 0;
    int i = 1;
    int j = 0;

    int pattern_length = atoi(pattern);
    while (i < pattern_length)
    {
	if (j == 0 || pattern[i] == pattern[j])
	{
	    ++i;
	    ++j;
	    if (pattern[i] != pattern[j])
	    {
		nextval[i] = j;
	    }
	    else
	    {
		nextval[i] = nextval[j];
	    }
	}
	else
	{
	    j = nextval[j];
	}
    }

}

int play_kmp(const char* target, const char* pattern)
{
    int target_index = 1;
    int pattern_index = 1;

    int next[255];
    get_next(pattern, next);

    int target_length = atoi(target);
    int pattern_length = atoi(pattern);
    while (target_index <= target_length && pattern_index <= pattern_length)
    {
	if (pattern_index == 0 || target[target_index] == pattern[pattern_index])
	{
	    ++target_index;
	    ++pattern_index;
	}
	else
	{
	    pattern_index = next[pattern_index];
	}
    }

    if (pattern_index > pattern_length)
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
    const char* target = "9godgoogle";
    const char* pattern = "6google";
    int pos = play_kmp(target, pattern);
    printf ("%d\n", pos);
    return 0;
}
