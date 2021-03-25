#include "Logger.h"

#include <iostream>

namespace Cosmic{

    void Logger::Trace(const char* msg)
    {
        Print(msg,LogLevel::TRACE);
    }

    void Logger::Info(const char* msg)
    {
        Print(msg,LogLevel::INFO);
    }


    void Logger::Warn(const char* msg)
    {
        Print(msg,LogLevel::WARN);
    }

    void Logger::Error(const char* msg)
    {
        Print(msg,LogLevel::ERROR);
    }

    void Logger::AssertIsTrue(bool expr, const char* msg, LogLevel level)
    {
        if(expr){
            Print(msg,level);
        }
    }

    void Logger::AssertIsFalse(bool expr, const char* msg, LogLevel level)
    {
        AssertIsTrue(!expr,msg,level);
    }

    void Logger::Assert(const char* msg, LogLevel level)
    {
        Print(msg,level);
    }

    void Logger::Print(const char* msg, LogLevel level) 
    {
        switch (level)
        {
            case LogLevel::TRACE:
                std::cout << LogColour.GREY << "[TRACE]: " << LogColour.END << msg << std::endl;
                break;
            case LogLevel::INFO:
                std::cout << LogColour.GREEN << "[INFO]: " << LogColour.END << msg << std::endl;
                break;
            case LogLevel::WARN:
                std::cout << LogColour.YELLOW << "[WARNING]: " << LogColour.END << msg << std::endl;
                break;
            case LogLevel::ERROR:
                std::cout << LogColour.RED << "[ERROR]: " << LogColour.END << msg << std::endl;
                break;
        }
    }

}