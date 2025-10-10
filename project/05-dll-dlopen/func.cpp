// UTF-8N CRLF
#include <emscripten.h>
#include <cstdio>
#include <cstring>
#include <numeric>
#include <dlfcn.h>

using fptr_t = void (*)(const char*...);
fptr_t log_impl;

#define log(...) if (log_impl) log_impl(__VA_ARGS__); else puts("dll load error")

//extern "C" void log_impl(const char* format...);

extern "C"
EMSCRIPTEN_KEEPALIVE
void initSideModule(const char* path)
{
	//dlopen(path, RTLD_NOW | RTLD_GLOBAL);

	if (void* handle = dlopen(path, RTLD_NOW))
	{
		if (fptr_t fptr = (fptr_t)dlsym(handle, "log_impl"))
		{
			log_impl = fptr;
		}
	}
}

extern "C"
EMSCRIPTEN_KEEPALIVE
int increment(int v)
{
	log("-- increment(%d)\n", v);
	return v + 1;
}

extern "C"
EMSCRIPTEN_KEEPALIVE
char* str_repeat(const char* str, int num)
{
	log("-- str_repeat(%s, %d)\n", str, num);
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
	log("-- sum(%d..%d)\n", nums[0], nums[len - 1]);
	return std::accumulate(nums, nums + len, 0);
}

// EOF