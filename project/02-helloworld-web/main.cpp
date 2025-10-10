// UTF-8N CRLF
#include <cstdio>

extern "C"
{
	extern char __heap_base;
}

int main(int argc, char** argv)
{
	puts(__FILE__);
	printf("heap-base=%lu\n", reinterpret_cast<unsigned long>(&__heap_base));

	return 0;
}

// EOF