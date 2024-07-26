#pragma once
#include <iostream>
#include <filesystem>
#include <regex>
#include <QTextBrowser>
#include <QMessageBox>
#include <QMainWindow>

#include "FileIOTool.h"

using namespace std;

class DebugMachine
{
public:
    DebugMachine();
    DebugMachine(string logPath);
    DebugMachine(QTextBrowser* outputWindow);
    DebugMachine(QMainWindow* mainWindow);
    ~DebugMachine();

    void Log(const string& logContent) const;
    void LogTextBrowser(const string& logContent) const;
    void LogMessageBox(const string& logContent) const;
    void LogToFile(const string& logContent) const;

private:
    string logPath;
    QTextBrowser* outputWindow;
    QMainWindow* mainWindow;
};
