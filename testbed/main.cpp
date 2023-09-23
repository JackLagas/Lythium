#include <iostream>

#include <Logger.h>
#include <fstream>
#include <filesystem>
#include <format>



int main(){

    
    std::filesystem::create_directory("log");
    Lythium::Logger::Init("./log/", Lythium::LOG_LEVEL::DEBUG);
    Lythium::Logger logger("Test");

    logger.Warn("{}", 5);
    logger.Debug("{}", "This is a debug message");
    logger.Trace("{}", "hello");
    logger.Error("{}", "Uh oh");
    
}