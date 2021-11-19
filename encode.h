#pragma once
#include "lodepng.h"
#include "typedefs.h"
#include "utils.h"
#include <iostream>
#include <string>

void save(const char* filename, Image img);
void encodeMessage(std::string message, Image * img);
