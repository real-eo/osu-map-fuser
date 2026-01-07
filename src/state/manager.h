#pragma once


// Windows based Manager-class
#if defined(_WIN32) || defined(_WIN64)

#include "managers/win.h"                                           // ! DEFINES `Manager` CLASS FROM `BaseManager`
using Manager = WinManager;


// TODO: Other platforms can be added here
#else
#error "Unsupported platform"

#endif
