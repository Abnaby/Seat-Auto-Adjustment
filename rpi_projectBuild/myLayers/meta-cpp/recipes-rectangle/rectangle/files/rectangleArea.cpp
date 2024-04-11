#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    // Open the output file
    std::ofstream outputFile("out.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error: Failed to open file out.txt" << std::endl;
        return 1;
    }

    // Write command-line arguments to the file
    for (int i = 0; i < argc; ++i) {
        outputFile << "Argument " << i << ": " << argv[i] << std::endl;
    }

    // Close the output file
    outputFile.close();

    std::cout << "Arguments written to out.txt" << std::endl;

    return 0;
}
