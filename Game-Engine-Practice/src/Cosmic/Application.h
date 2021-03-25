#ifndef APPLICATION_H
#define APPLICATION_H

namespace Cosmic{

    class Application
    {
    public:
        Application();
        virtual ~Application();

        virtual void Run();
    };
}

#endif