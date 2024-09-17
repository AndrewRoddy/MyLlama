#include <iostream>
#include <cstdlib>  // For std::system
#include <sstream>
//#include <fstream> // For reading files
#include <unistd.h> // For sleep() // In seconds

void Llama(std::string prompt="STOP", std::string length = "20", std::string system_prompt = "In english and in one sentance ");