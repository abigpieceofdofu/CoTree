#include "FileIOTool.h"

// public
FileIOTool::FileIOTool()
{}

FileIOTool::~FileIOTool()
{}

bool FileIOTool::exists(const filesystem::path& path)
{
    try
    {
        return std::filesystem::exists(path);
    }
    catch (const std::filesystem::filesystem_error& e)
    {
        throw runtime_error("Filesystem error: " + string(e.what()));
    }
}

string FileIOTool::readFile(const string& filePath, size_t chunkSize)
{
    ifstream inputFile(filePath, ios::in | ios::binary);
    if (!inputFile.is_open())
    {
        throw runtime_error("Error: Unable to open file. It may not exist or cannot be accessed.");
    }

    string content;
    char* buffer = new char[chunkSize];
    if (!buffer)
    {
        inputFile.close();
        throw runtime_error("Error: Memory allocation failed.");
    }

    while (inputFile.read(buffer, chunkSize) || inputFile.gcount() > 0)
    {
        content.append(buffer, inputFile.gcount());
    }

    if (inputFile.bad())
    {
        delete[] buffer;
        inputFile.close();
        throw runtime_error("Error: File read error.");
    }

    delete[] buffer;
    inputFile.close();
    return content;
}

bool FileIOTool::writeFile(const string& filePath, const string& content)
{
    if (exists(filePath))
    {
        throw runtime_error("Error: File already exists.");
    }

    bool success = writeFileForce(filePath, content);
    return success;
}

bool FileIOTool::writeFileForce(const string& filePath, const string& content)
{
    filesystem::path path(filePath);

    if (!createDirectories(path))
    {
        throw runtime_error("Error: Unable to create necessary directories.");
    }
    
    ofstream outputFile(filePath, ios::out | ios::binary | ios::trunc);
    if (!outputFile.is_open())
    {
        throw runtime_error("Error: Unable to open file for writing.");
    }

    outputFile.write(content.c_str(), content.size());

    if (outputFile.bad())
    {
        outputFile.close();
        throw runtime_error("Error: File write error.");
    }

    outputFile.close();
    return true;
}

bool FileIOTool::createDirectories(const filesystem::path& path)
{
    try
    {
        if (!exists(path.parent_path()))
        {
            create_directories(path.parent_path());
        }
        return true;
    }
    catch (const filesystem::filesystem_error& e)
    {
        throw runtime_error("Filesystem error: ");
        return false;
    }
}