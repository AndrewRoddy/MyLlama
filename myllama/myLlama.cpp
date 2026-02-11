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

    oss << "cd ..\\llama.cpp && del ..\\myllama\\output.txt && .\\build\\bin\\Release\\llama-completion.exe -m .\\models\\llama-2-7b-chat.Q2_K.gguf --predict " << length << " --prompt \"Q:"<< system_prompt << prompt << " A: \" > ..\\myllama\\output.txt 2>nul";
    
    string command;
    command = oss.str();

    system(command.c_str());

    // Clean output.txt: remove ANSI escape codes and non-ASCII characters
    std::ifstream infile("output.txt");
    string raw((std::istreambuf_iterator<char>(infile)),
                std::istreambuf_iterator<char>());
    infile.close();

    string cleaned;
    for (size_t i = 0; i < raw.size(); i++) {
        // Skip ANSI escape sequences (ESC [ ... final_char)
        if (raw[i] == '\x1b' && i + 1 < raw.size() && raw[i + 1] == '[') {
            i += 2; // skip ESC and [
            while (i < raw.size() && raw[i] != 'm' && raw[i] != 'H'
                   && raw[i] != 'J' && raw[i] != 'K' && raw[i] != 'A'
                   && raw[i] != 'B' && raw[i] != 'C' && raw[i] != 'D')
                i++;
            continue;
        }
        // Keep only printable ASCII, newlines, and tabs
        if ((raw[i] >= 32 && raw[i] <= 126) || raw[i] == '\n' || raw[i] == '\t')
            cleaned += raw[i];
    }

    std::ofstream outfile("output.txt");
    outfile << cleaned;
    outfile.close();
}

int main() {
    string prompt;
    string length = "20";

    cout << "Enter your prompt: ";
    std::getline(cin, prompt);

    Llama(prompt, length);
}
