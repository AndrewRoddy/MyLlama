#include <iostream>
#include <thread>
#include <atomic>
#include <conio.h> // Include for _kbhit and _getch
#include <vector>
#include <algorithm>

// Global variables
std::atomic<bool> running(true);
std::vector<char> board = {'_','_','_','_','_','_','O','_','_','_','_','_','_'};
// Input handling function
void handleInput() {
    while (running) {
        if (_kbhit()) { // Check if a key has been pressed
            char ch = _getch(); // Read the key press without waiting for Enter
            if (ch == 27) { // ESC key to stop
                running = false;
            } if (ch == 97) {
                std::rotate(board.begin(), board.begin() + 1, board.end());
            } if (ch == 100) {
                std::rotate(board.rbegin(), board.rbegin() + 1, board.rend());
            }
        } else {
            std::cout << "\n\n\n" << std::endl;
            for(char letter : board) {
                    std::cout << letter;
                }
                std::cout << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Small delay to avoid high CPU usage
    }
}

int main() {
    std::thread inputThread(handleInput); // Start input handling thread

    // Main program loop
    while (running) {
        // Perform other tasks here
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    inputThread.join(); // Wait for the input thread to finish

    std::cout << "Program has exited." << std::endl;
    return 0;
}
