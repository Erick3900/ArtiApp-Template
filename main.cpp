#include <Main.hpp>

#if defined(_WIN32) && !defined(NDEBUG)
#include <Windows.h>
int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow) {
#else
int main()
#endif
{
    Application app;

    if (app.init("Arti App", {860, 640})) {
        return app.run();
    }
    return 0;
}
