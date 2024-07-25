#include "FileIOTool.h"

// public
FileIOTool::FileIOTool()
{}

FileIOTool::~FileIOTool()
{}

string FileIOTool::readFile(const string& filePath, size_t chunkSize) {
    ifstream inputFile(filePath, ios::in | ios::binary);
    if (!inputFile.is_open()) {
        throw runtime_error("Error: Unable to open file. It may not exist or cannot be accessed.");
    }

    string content;
    char* buffer = new char[chunkSize];
    if (!buffer) {
        inputFile.close();
        throw runtime_error("Error: Memory allocation failed.");
    }

    while (inputFile.read(buffer, chunkSize) || inputFile.gcount() > 0) {
        content.append(buffer, inputFile.gcount());
    }

    if (inputFile.bad()) {
        delete[] buffer;
        inputFile.close();
        throw runtime_error("Error: File read error.");
    }

    delete[] buffer;
    inputFile.close();
    return content;
}

bool FileIOTool::writeFile(const string& filePath, const string& content) {
    ifstream existingFile(filePath);
    if (existingFile.is_open()) {
        existingFile.close();
        throw runtime_error("Error: File already exists.");
    }

    bool success = writeFileForce(filePath, content);
    return success;
}

bool FileIOTool::writeFileForce(const string& filePath, const string& content) {
    ofstream outputFile(filePath, ios::out | ios::binary | ios::trunc);
    if (!outputFile.is_open()) {
        throw runtime_error("Error: Unable to open file for writing.");
    }

    outputFile.write(content.c_str(), content.size());

    if (outputFile.bad()) {
        outputFile.close();
        throw runtime_error("Error: File write error.");
    }

    outputFile.close();
    return true;
}
