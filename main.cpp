// #include <iostream>

// int main(int argc, char** argv) {
//     (void)argc; (void)argv;

//     std::cout << "it works\n";

//     return 0;
// }

#include "Application.h"


int main(int argc, char** argv) {
    (void)argc; (void)argv;
    
    // TODO: Use preprocessor directives to enable debug mode in debug builds only
    // Set debug logging
    DEBUG::enabled = true;
    
    // Create and run application
    Application app("osu! map splicer - prototype", 1200, 720);

    if (!app.init()) {
        std::cerr << "Failed to initialize application\n";
        return 1;
    }

    return app.run();
}