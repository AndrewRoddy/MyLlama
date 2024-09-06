#include <iostream>
#include <cstdlib>  // For std::system
//#include <sstream>
//#include <fstream> // For reading files
//#include <unistd.h> // For sleep() // In seconds

//using std::cin; using std::cout; using std::endl;
using std::string; using std::system;// using std::ifstream;

void Llama(){
    system("cd ..\\llama.cpp && del ..\\MyLlama\\output.txt && .\\llama-cli.exe -m .\\models\\llama-2-7b-chat.Q2_K.gguf --predict 20 --prompt \"Q:What are the largest planets in the solar system? A: \" > ..\\MyLlama\\output.txt");
}

int main() {

    Llama();
    
    /*
    //system(".\\llama-cli.exe -m .\\llama.cpp\\models\\llama-2-7b-chat.Q2_K.gguf --predict 10 --prompt \"What is your favorite color\" > output.txt");
    //system("cd ..\\llama.cpp && del output.txt && dir > output1.txt");
    //system("cd .. && cd ..\\llama.cpp && dir > output1.txt");

    // Deletes old files
    //system("del output.txt");
    
    //sleep(1);
    //cout << "Deleted";
    //system("dir > output.txt");

    ifstream file("output.txt");
    string line;

    
    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    //string prompt = "1";
    //string file = "output.txt";
    //string size = "1";

    //std::ostringstream oss; // Used to concatenate strings
    //string command;

    //oss << "ls < output.txt";
    
    //command = oss.str();
    //cout << "Executing command: " << command << endl;
    //nt result = system(command.c_str());
    
    //cout << "Executing command: " << command << endl;

    while (prompt != "0") {
        cout << "Prompt: ";
        cin >> prompt;
        std::ostringstream oss; // Used to concatenate strings

        oss << ".\\PersonalC++\\llama.cpp\\llama-cli.exe -m .\\llama.cpp\\models\\llama-2-7b-chat.Q2_K.gguf --predict "<< size << " --prompt \"" << prompt <<"\" > output.txt";
        // Construct the command string
        string command;
        command = oss.str();

        // Print the command to be executed
        cout << "Executing command: " << command << endl;

        // Execute the command
        int result = system(command.c_str());
    }
    */
}
