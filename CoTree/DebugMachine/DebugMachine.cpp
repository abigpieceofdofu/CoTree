#include "DebugMachine.h"

// public
DebugMachine::DebugMachine()
    : outputWindow(nullptr), mainWindow(nullptr)
{}

DebugMachine::DebugMachine(string logPath)
    : logPath(logPath), outputWindow(nullptr), mainWindow(nullptr)
{
    regex pathPattern(R"(^(?:[a-zA-Z]\:|\\)(\\[a-zA-Z0-9_\-]+)+(\.[a-zA-Z0-9]+)?$)");
    if (!regex_match(logPath, pathPattern)) {
        throw std::invalid_argument("Invalid file path format");
    }
}

DebugMachine::DebugMachine(QTextBrowser* outputWindow)
    : outputWindow(outputWindow), mainWindow(nullptr)
{}

DebugMachine::DebugMachine(QMainWindow* mainWindow)
    : outputWindow(nullptr), mainWindow(mainWindow)
{}

DebugMachine::~DebugMachine()
{}


void DebugMachine::Log(const string& logContent) const
{
    cout << logContent << endl;
}

void DebugMachine::LogTextBrowser(const string& logContent) const
{
    if (outputWindow)
    {
        outputWindow->append(QString::fromStdString(logContent));
    }
}

void DebugMachine::LogMessageBox(const string& logContent) const
{
    if (mainWindow)
    {
        QMessageBox::information(mainWindow, "Log", QString::fromStdString(logContent));
    }
}

void DebugMachine::LogToFile(const string& logContent) const
{
    try
    {
        string combinedContent = logContent;
        if (FileIOTool::exists(logPath))
        {
            string existingContent = FileIOTool::readFile(logPath);
            combinedContent = existingContent + logContent;
        }
        
        FileIOTool::writeFileForce(logPath, combinedContent);
    }
    catch (const runtime_error& e) {
        throw runtime_error("Error: Log writing failed. " + string(e.what()));
    }
}
