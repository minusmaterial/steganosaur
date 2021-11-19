#pragma once
#include "lodepng.h"
#include "typedefs.h"
#include "utils.h"
#include <iostream>
#include <string>

Image load(const char* filename); 

std::string decodeMessage(Image img);
