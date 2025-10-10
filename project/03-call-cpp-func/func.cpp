// UTF-8N CRLF
#include <emscripten.h>
#include <cstdio>
#include <cstring>
#include <numeric>

extern "C"
EMSCRIPTEN_KEEPALIVE
int increment(int v)
{
	printf("-- increment(%d)\n", v);
	return v + 1;
}

extern "C"
EMSCRIPTEN_KEEPALIVE
char* str_repeat(const char* str, int num)
{
	printf("-- str_repeat(%s, %d)\n", str, num);
	char* ret = (char*)malloc(strlen(str) * num + 1);
	ret[0] = '\0';

	for (int i=0; i<num; ++i) {
		strcat(ret, str);
	}

	return ret;
}

extern "C"
EMSCRIPTEN_KEEPALIVE
int sum(const int* nums, int len)
{
	printf("-- sum(%d..%d)\n", nums[0], nums[len - 1]);
	return std::accumulate(nums, nums + len, 0);
}

// EOF