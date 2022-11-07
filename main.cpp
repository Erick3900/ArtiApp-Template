#include <Main.hpp>

#if defined(_WIN32) && !defined(NDEBUG)
#    include <Windows.h>
#    define main_entry_point                                                                                           \
        int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)
#else
#    define main_entry_point int main()
#endif

main_entry_point {
    Application app;

    if (app.init("Arti App", { 860, 640 })) {
        return app.run();
    }
    return 0;
}
