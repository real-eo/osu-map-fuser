#include <string>
#include <iostream>

void fatal(std::string const& msg)      { std::cerr << "[audioengine] [fatal] " << msg << "\n"; }
void not_fatal(std::string const& msg)  { std::cerr << "[audioengine] [warn] "  << msg << "\n"; }