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

extern "C" char** environ;

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

	if (envp)
	{
		std::cout << "envp is not null" << std::endl;
	}
	else
	{
		std::cout << "envp is null" << std::endl;
	}

	std::cout << "environ=[";

    for (char** p=environ; *p; ++p)
	{
		if (p != environ) {
			std::cout << ",";
		}
        std::cout << "'" << *p << "'";
    }

	std::cout << "]" << std::endl;

	std::cout << "from index.html: " << getenv("APP_LOCATION") << std::endl;

	return 0;
}


// EOF