#include <iostream>
#include <cstdlib>  // For std::system
#include <sstream>
#include <fstream> // For file operations
#include <unistd.h> // For sleep() // In seconds

using std::cin; using std::cout; using std::endl;
using std::string; using std::system;

void Llama(
    string prompt="STOP",
    string length = "1000",
    string system_prompt = "In english, "
    ){
    std::ostringstream oss; // Used to concatenate strings

    // Adds length and system prompt to the length
    // Adds 6 because Q: and A: is 6 characters long!
    length += prompt.length() + system_prompt.length() + 6; 

    // Create output.txt if it doesn't exist, otherwise clear it
    {
        std::ifstream check("output.txt");
        if (!check.good()) {
            std::ofstream create("output.txt");
        }
    }

    sleep(1);

    oss << "cd ..\\llama.cpp && del ..\\myllama\\output.txt && .\\build\\bin\\Release\\llama-completion.exe -m .\\models\\llama-2-7b-chat.Q2_K.gguf --predict " << length << " --prompt \"Q:"<< system_prompt << prompt << " A: \" > ..\\myllama\\output.txt";
    
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
