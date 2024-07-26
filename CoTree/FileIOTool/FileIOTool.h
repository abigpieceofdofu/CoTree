#pragma once
#include <fstream>
#include <filesystem>

using namespace std;

class FileIOTool
{
public:
    FileIOTool();
    ~FileIOTool();

    static bool exists(const filesystem::path& path);
    static string readFile(const std::string& filePath, size_t chunkSize = 50 * 1024 * 1024); // 50 MB
    static bool writeFile(const string& filePath, const string& content);
    static bool writeFileForce(const string& filePath, const string& content);
    static bool createDirectories(const filesystem::path& path);
};
