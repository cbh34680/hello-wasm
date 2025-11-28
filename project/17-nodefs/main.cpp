// UTF-8N CRLF
#include <emscripten.h>
#include <iostream>
#include <chrono>
#include <fstream>
#include <cstdlib>

static void print_args(int argc, char** argv);

int main(int argc, char** argv, char** envp)
{
	print_args(argc, argv);

	std::string esFullPath{ argv[1] };

	// 現在のファイルの内容を表示
	if (std::ifstream ifs{esFullPath})
	{
		std::cout << ifs.rdbuf();
		ifs.close();
	}

	// 現時刻を追加で書き込み
	if (std::ofstream ofs{esFullPath, std::ios::app})
	{
		auto now = std::chrono::system_clock::now();
		std::time_t t = std::chrono::system_clock::to_time_t(now);
		std::tm tm = *std::localtime(&t);
		char buf[64];
		std::strftime(buf, sizeof(buf), "%Y/%m/%d %H:%M:%S", &tm);
		ofs << "|C++: " << buf << std::endl;
		ofs.close();
	}

	return EXIT_SUCCESS;
}

void print_args(int argc, char** argv)
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
}

// EOF