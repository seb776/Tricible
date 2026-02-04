#include <string>
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>
#include <direct.h>
#include <Windows.h>

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
}