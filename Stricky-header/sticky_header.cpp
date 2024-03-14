#include <iostream>
#include <iomanip>
#include <unistd.h>

void clearScreen() {
    // Clear the screen
    std::cout << "\033[2J\033[1;1H";
}

int main() {
    const int HEADER_HEIGHT = 3; // Height of the sticky header
    int scrollOffset = 0;

    // Display some content
    for (int i = 0; i < 100; ++i) {
        std::cout << "Content line " << std::setw(2) << i << std::endl;
    }

    // Display the sticky header
    std::cout << "Sticky Header" << std::endl;
    for (int i = 0; i < HEADER_HEIGHT - 1; ++i) {
        std::cout << std::endl; // Fill the header space
    }

    // Simulate scrolling
    while (true) {
        char input;
        std::cin >> input;

        if (input == 'w' && scrollOffset > 0) { // Scroll up
            scrollOffset--;
        } else if (input == 's' && scrollOffset < 100 - HEADER_HEIGHT) { // Scroll down
            scrollOffset++;
        }

        // Redraw the header at the new position
        clearScreen(); // Clear the console
        for (int i = 0; i < 100; ++i) {
            std::cout << "Content line " << std::setw(2) << i << std::endl;
        }
        std::cout << "Sticky Header" << std::endl;
        for (int i = 0; i < HEADER_HEIGHT - 1; ++i) {
            std::cout << std::endl; // Fill the header space
        }

        // Move the cursor to the top of the content
        std::cout << "\033[" << HEADER_HEIGHT << "A";
    }

    return 0;
}
