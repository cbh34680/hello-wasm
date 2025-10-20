// UTF-8N CRLF
#include <emscripten.h>
#include <iostream>
#include <fstream>

extern "C"
EMSCRIPTEN_KEEPALIVE
int increment(int v)
{
	printf("-- increment(%d)\n", v);
	return v + 1;
}

int main(int argc, char** argv, char** envp)
{
	std::cout << "C++ main(argc=" << argc << ", argv=[";

	for (int i=0; i<argc; ++i)
	{
		if (i) {
			std::cout << ",";
		}
		std::cout << "'" << argv[i] << "'";
	}

	std::cout << "])" << std::endl;


	return 0;
}


// EOF