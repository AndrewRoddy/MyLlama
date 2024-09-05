#include <iostream>
#include <cstdlib>  // For std::system
# include <sstream>
using std::cin; using std::cout; using std::endl;

using std::string; using std::system;

int main() {
    string prompt = "1";
    string file = "output.txt";
    string size = "1";
    while (prompt != "0") {
        cout << "Prompt: ";
        cin >> prompt;

        std::ostringstream oss; // Used to concatenate strings

        oss << ".\\llama.cpp\\llama-cli.exe -m .\\llama.cpp\\models\\llama-2-7b-chat.Q2_K.gguf --predict "<< size << " --prompt \"" << prompt <<"\" > output.txt";
        // Construct the command string
        string command;
        command = oss.str();

        // Print the command to be executed
        cout << "Executing command: " << command << endl;

        // Execute the command
        int result = system(command.c_str());
    }
    return 0;
}
