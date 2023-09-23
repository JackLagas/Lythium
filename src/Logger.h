#ifndef LYTHIUM_LOGGER_H
#define LYTHIUM_LOGGER_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdarg>
#include <format>
#include <string_view>

namespace Lythium{

    enum LOG_LEVEL{
        INFO = 0,
        TRACE = 1,
        DEBUG = 2,
        WARN = 3,
        ERROR = 4,
        FATAL = 5,
    };

    class Logger{
    private:
        const std::string log_types[6] = {"Info", "Trace", "Debug", "Warning", "Error", "Fatal"};
        static std::string logFile;
        static bool is_initialized;
        static LOG_LEVEL log_level;
        std::string logName;

        template <typename... Args>
        void Log(LOG_LEVEL level, const std::string_view message, Args&&... args){
            if(level >= log_level){
                std::string finalMessage = std::format("[{}] {}: ", this->logName, log_types[level]);
                finalMessage += std::vformat(message, std::make_format_args(args...));

                std::cout << finalMessage << std::endl;

                std::ofstream file;
                file.open((logFile + "latest.log").c_str(), std::ios_base::app);

                file << finalMessage << "\n";
                file.close();
            }
        }

    public:
        
        Logger(std::string friendlyName);
        static void Init(std::string logFilePath, LOG_LEVEL _log_level);


    #ifndef NDEBUG
        template <typename... Args>
        void Info(const std::string_view message, Args&&... args){
            Log(LOG_LEVEL::INFO, message, args...);
        }
        template <typename... Args>
        void Trace(const std::string_view message, Args&&... args){
            Log(LOG_LEVEL::TRACE, message, args...);
        }
    #else

        template <typename... Args>
        void Info(const std::string_view message, Args&&... args){
        }
        template <typename... Args>
        void Trace(const std::string_view message, Args&&... args){
        }

    #endif
        template <typename... Args>
        void Debug(const std::string_view message, Args&&... args){
            Log(LOG_LEVEL::DEBUG, message, args...);
        }
        template <typename... Args>
        void Warn(const std::string_view message, Args&&... args){
            Log(LOG_LEVEL::WARN, message, args...);
        }
        template <typename... Args>
        void Error(const std::string_view message, Args&&... args){
            Log(LOG_LEVEL::ERROR, message, args...);
        }
        template <typename... Args>
        void Fatal(const std::string_view message, Args&&... args){
            Log(LOG_LEVEL::FATAL, message, args...);
        }
       


    };
}



#endif