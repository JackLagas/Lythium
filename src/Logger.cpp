#include "Logger.h"

#include <iostream>
#include <stdexcept>
#include <chrono>
#include <ctime>
#include <filesystem>

namespace Lythium{

    bool Logger::is_initialized = false;
    std::string Logger::logFile = "";
    LOG_LEVEL Logger::log_level = LOG_LEVEL::ERROR;

    Logger::Logger(std::string friendlyName): logName(friendlyName){
        if(!this->is_initialized){
            throw std::logic_error("The Logger has not been initialized!");
        }

    }

    void Logger::Init(std::string logFilePath, LOG_LEVEL _log_level){

        std::cout << "Test" << std::endl;
        
        logFile = logFilePath;
        std::filesystem::path filePath{logFile + "/latest.log"};

        auto currentTimeChrono = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(currentTimeChrono);

        if(std::filesystem::exists(filePath)){

            std::time_t t = std::time(0); 
            std::tm* now = std::localtime(&t);
            std::string newName = "log";
            newName.append(std::to_string(now->tm_year + 1900));
            newName.append(std::to_string(now->tm_mon + 1));
            newName.append(std::to_string(now->tm_mday));
            newName.append(std::to_string(now->tm_hour));
            newName.append(std::to_string(now->tm_min));
            newName.append(std::to_string(now->tm_sec));
            

            std::rename((logFile + "latest.log").c_str(), (logFile + newName + ".log").c_str());

        }
        std::ofstream file;
        file.open((logFile + "latest.log").c_str(), std::ios::out);

        if(!file){
            std::cout << "Error creating file!" << std::endl;
        }
        

        file << std::ctime(&currentTime);

        file.close();

        log_level = _log_level;
        
        is_initialized = true;

    }



}