#include "../headers/logger.hpp"

/// @brief Constructor for the Logger class
/// @details Initializes the logger with isInitialized set to false
Logger::Logger() : isInitialized(false) {}

/// @brief Destructor for the Logger class
/// @details Closes the log file if it's open
Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

/// @brief Gets the singleton instance of the Logger
/// @param filePath The path to the log file
/// @return Reference to the Logger instance
Logger& Logger::GetInstance(const std::string& filePath) {
    static Logger instance;
    if (!filePath.empty() && !instance.isInitialized) {
        instance.SetLogFile(filePath);
        instance.isInitialized = true;
    }
    return instance;
}

/// @brief Logs a message to the file
/// @param message The message to be logged
void Logger::Log(const std::string& message) {
    if (logFile.is_open()) {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);
        logFile << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S") << " - " << message << std::endl;
    } else {
        std::cerr << "Log file is not open!" << std::endl;
    }
}

/// @brief Sets the log file path
/// @param filePath The path to the log file
void Logger::SetLogFile(const std::string& filePath) {
    if (logFile.is_open()) {
        logFile.close();
    }
    logFile.open(filePath, std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file: " << filePath << std::endl;
        throw std::runtime_error("Failed to open log file: " + filePath);
    }
}