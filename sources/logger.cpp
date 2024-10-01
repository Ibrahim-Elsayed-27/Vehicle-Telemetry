#include "../headers/logger.hpp" // Include the header file

/// Private empty constructor for the Logger class (prevents object creation).
Logger::Logger() {}

/// Destructor for the Logger class.
/// Closes the log file if it's open.
Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

/// Singleton pattern implementation to get a reference to the Logger instance.
/// @param filePath The path to the log file (optional).
/// @return Reference to the Logger instance.
Logger& Logger::GetInstance(const std::string& filePath) {
    static Logger instance;
    if (!filePath.empty() && !instance.isInitialized) {
        instance.SetLogFile(filePath);
        instance.isInitialized = true;
    }
    return instance;
}

/// Logs a message to the log file.
/// @param message The message to be logged.
void Logger::Log(const std::string& message) {
    if (logFile.is_open()) {
        logFile << message << std::endl;
    } else {
        std::cerr << "Log file is not open!" << std::endl;
    }
}

/// Sets the log file path and opens the file for appending.
/// @param filePath The path to the log file.
void Logger::SetLogFile(const std::string& filePath) {
    logFile.open(filePath, std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file: " << filePath << std::endl;
    }
}