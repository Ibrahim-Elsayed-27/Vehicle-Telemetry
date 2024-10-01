#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <iomanip>

class Logger {
public:
    // Get the Singleton instance and set the log file path (declaration)
    static Logger& GetInstance(const std::string& filePath = "");

    // Method to log a message (declaration)
    void Log(const std::string& message);

    private:
    // Private constructor and destructor (declarations)
    Logger();
    ~Logger();

    // Disallow copying (declarations)
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    std::ofstream logFile;
    bool isInitialized = false;

    // Set the log file path (declaration, forward declaration for Logger)
    void SetLogFile(const std::string& filePath);
};

#endif // LOGGER_HPP