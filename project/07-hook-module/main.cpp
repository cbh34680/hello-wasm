// UTF-8N CRLF
#include <cstdio>

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