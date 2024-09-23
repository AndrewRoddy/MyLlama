#include <iostream>
#include <cstdlib>  // For std::system
#include <sstream>
//#include <fstream> // For reading files
#include <unistd.h> // For sleep() // In seconds

using std::cin; using std::cout; using std::endl;
using std::string; using std::system;

void Llama(
    string prompt="STOP",
    string length = "20",
    string system_prompt = "In english and in one sentance "
    ){
    std::ostringstream oss; // Used to concatenate strings

    // Adds length and system prompt to the length
    // Adds 6 because Q: and A: is 6 characters long!
    length += prompt.length() + system_prompt.length() + 6; 

    // Deletes output.txt
    system("del output.txt");

    sleep(1);

    oss << "cd ..\\llama.cpp && del ..\\MyLlama\\output.txt && .\\llama-cli.exe -m .\\models\\llama-2-7b-chat.Q2_K.gguf --predict " << length << " --prompt \"Q:"<< system_prompt << prompt << " A: \" > ..\\MyLlama\\output.txt";
    
    string command;
    command = oss.str();

    system(command.c_str());
}

int main() {
    string prompt;
    string length = "20";

    cout << "Enter your prompt: ";
    std::getline(cin, prompt);

    Llama(prompt, length);
}
