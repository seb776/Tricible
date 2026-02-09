#include <string>
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>
#include <direct.h>
#include <Windows.h>
#include <functional>
#include <thread>
#include <algorithm>
#include <fstream>

namespace Tricible
{
	std::string GetCurrentDirectory()
	{
		const size_t size = 1024;
		char buffer[size];

		// Call _getcwd to get the current working directory and store it in buffer
		if (getcwd(buffer, size) != NULL)
		{
			return buffer;
		}
		return "";
	}
	std::string PathCombine(const std::string& a, const std::string& b)
	{
		std::experimental::filesystem::path patha = std::experimental::filesystem::path(a);
		patha /= b;
		return patha.string();
	}

	std::string GetCurrentExecutableDirectory()
	{
		const int MAX_PATH_ = 1024;
		wchar_t path[MAX_PATH_];
		GetModuleFileNameW(NULL, path, MAX_PATH_);
		return std::experimental::filesystem::path(path).parent_path().string();
	}

	std::string ReadFile(const std::string& fileName)
	{
		std::ifstream ifs(fileName.c_str(), std::ios::in | std::ios::binary | std::ios::ate);

		std::ifstream::pos_type fileSize = ifs.tellg();
		ifs.seekg(0, std::ios::beg);

		std::vector<char> bytes(fileSize);
		ifs.read(bytes.data(), fileSize);

		return std::string(bytes.data(), fileSize);
	}

	// TODO Fix this implem
	void parallel_fora(size_t start, size_t end, std::function<void(size_t)> func, size_t num_threads = std::thread::hardware_concurrency())
	{
		if (num_threads == 0) num_threads = std::thread::hardware_concurrency();
		if (num_threads == 0) num_threads = 1; // fallback

		size_t total = end - start;
		size_t chunk_size = (total + num_threads - 1) / num_threads; // ceil division

		std::vector<std::thread> threads;

		for (size_t t = 0; t < num_threads; ++t)
		{
			size_t chunk_start = start + t * chunk_size;
			size_t chunk_end = std::fmin(chunk_start + chunk_size, end);

			if (chunk_start >= chunk_end) break; // no work for this thread

			threads.emplace_back([chunk_start, chunk_end, &func]() {
				for (size_t i = chunk_start; i < chunk_end; ++i)
				func(i);
				});
		}

		for (auto& th : threads)
			th.join();
	}
}