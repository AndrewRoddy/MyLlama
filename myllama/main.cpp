#include <iostream>
#include <cstdlib>  // For std::system
#include <sstream>
#include <fstream> // For file operations
#include <unistd.h> // For sleep() // In seconds

using std::cin; using std::cout; using std::endl;
using std::string; using std::system;


struct Config {
    int length;
    string system_prompt;
    string output_file;
    string model_name;
};

string get_json_string(const string& json, const string& key) {
    string search = "\"" + key + "\"";
    size_t pos = json.find(search);
    if (pos == string::npos) return "";
    pos = json.find(":", pos);
    size_t start = json.find("\"", pos + 1) + 1;
    size_t end = json.find("\"", start);
    return json.substr(start, end - start);
}

int get_json_int(const string& json, const string& key) {
    string search = "\"" + key + "\"";
    size_t pos = json.find(search);
    if (pos == string::npos) return 0;
    pos = json.find(":", pos) + 1;
    while (pos < json.size() && json[pos] == ' ') pos++;
    string num;
    while (pos < json.size() && json[pos] >= '0' && json[pos] <= '9')
        num += json[pos++];
    return std::stoi(num);
}

Config load_config(const string& path = "config.json") {
    std::ifstream file(path);
    string json((std::istreambuf_iterator<char>(file)),
                 std::istreambuf_iterator<char>());
    file.close();

    Config config;
    config.length = get_json_int(json, "length");
    config.system_prompt = get_json_string(json, "system_prompt");
    config.output_file = get_json_string(json, "output_file");
    config.model_name = get_json_string(json, "model_name");
    return config;
}

string clean_output (string raw){
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

    // Removes the first space
    if (!cleaned.empty())
        cleaned = cleaned.substr(1,cleaned.size());

    return cleaned;
}

void Llama(
    string prompt="STOP",
    int length = 1000,
    string system_prompt = "In english, ",
    string output_file = "output.txt",
    string model_name = "llama-2-7b-chat.Q2_K.gguf"
    ){

    std::ostringstream oss; // Used to concatenate strings

    // Ensure output_file exists before running
    { std::ofstream touch(output_file, std::ios::app); }

    oss << "cd ..\\llama.cpp && .\\build\\bin\\Release\\llama-completion.exe -m .\\models\\" << model_name << " --predict " << length << " --prompt \"Q:"<< system_prompt << prompt << " A: \" > ..\\myllama\\" << output_file << " 2>nul";
    
    string command;
    command = oss.str();

    system(command.c_str());

    // Create the file if it wasn't created already
    { std::ofstream touch(output_file, std::ios::app); }
    std::ifstream infile(output_file);
    string raw((std::istreambuf_iterator<char>(infile)),
    std::istreambuf_iterator<char>());
    infile.close();
    
    // Clean output_file: remove ANSI escape codes and non-ASCII characters
    string cleaned = clean_output(raw);
    
    std::ofstream outfile(output_file);
    outfile << cleaned;
    outfile.close();
}

int main() {
    Config config = load_config();
    string prompt;  

    cout << "Enter your prompt: ";
    std::getline(cin, prompt);

    Llama(prompt, config.length, config.system_prompt, config.output_file, config.model_name);
}
