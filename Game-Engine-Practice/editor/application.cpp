#include "../src/Cosmic.h"

#include <iostream>

class Editor : Cosmic::Application
{
public:
    Editor() {}
    ~Editor() {}
    void Run() override { std::cout << "Running Editor Application..." << std::endl; }
};

int main(void)
{   
    Editor ed;
    ed.Run();

    Cosmic::Logger::Trace("This is a trace message!");
    Cosmic::Logger::Info("This is an info message!");
    Cosmic::Logger::Warn("This is a warning message!");
    Cosmic::Logger::Error("This is an error message!");

    return 0;
}