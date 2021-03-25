#ifndef LOGGER_H
#define LOGGER_H

#include <string>

namespace Cosmic{

    enum class LogLevel{
        TRACE=1,
        INFO,
        WARN,
        ERROR
    };

    static const struct LogColour{
        const char* BLACK="\033[0;30m";
        const char* RED="\033[0;31m";
        const char* GREEN="\033[0;32m";
        const char* YELLOW="\033[0;33m";
        const char* BLUE="\033[0;34m";
        const char* PURPLE="\033[0;35m";
        const char* CYAN="\033[0;36m";
        const char* GREY="\033[0;37m";
        const char* END="\033[0m";
    }LogColour;

    class Logger
    {
    public:
        Logger() = delete;
        ~Logger() = default;

        static void Trace(const char* msg);
        static void Info(const char* msg);
        static void Warn(const char* msg);
        static void Error(const char* msg);

        static void Assert(const char* msg, LogLevel level=LogLevel::TRACE);
        static void AssertIsTrue(bool expr, const char* msg, LogLevel level=LogLevel::TRACE);
        static void AssertIsFalse(bool expr, const char* msg, LogLevel level=LogLevel::TRACE);
    private:
        static void Print(const char* msg, LogLevel level);
    };

}

#endif