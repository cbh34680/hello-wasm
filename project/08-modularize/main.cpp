// UTF-8N CRLF
#include <emscripten.h>
#include <cstdio>

extern "C"
EMSCRIPTEN_KEEPALIVE
int increment(int v)
{
	printf("-- increment(%d)\n", v);
	return v + 1;
}

int main(int argc, char** argv)
{
	printf("C++ main(argc=%d, argv=[", argc);

	for (int i=0; i<argc; ++i)
	{
		if (i) {
			printf(",");
		}
		printf("'%s'", argv[i]);
	}

	puts("])");

	return 0;
}


// EOF