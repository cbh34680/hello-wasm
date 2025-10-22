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

int main(int argc, char** argv)
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

	std::cout << "open: " << argv[1] << std::endl;
	std::ifstream ifs{ argv[1] };
	if (ifs)
	{
	    std::string line;
    	while (std::getline(ifs, line))
		{
	        std::cout << "DATA: " << line << std::endl;
    	}
	}
	else
	{
		std::cerr << "file open error" << std::endl;
	}

	return 0;
}

// EOF