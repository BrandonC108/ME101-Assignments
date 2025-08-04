#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main() {
    const int num_lines = 10000;
    const int row_limit = 372;
    const int col_limit = 378;

    std::ofstream outfile("outputRoads.txt");
    if (!outfile) {
        std::cerr << "Failed to open output.txt for writing.\n";
        return 1;
    }

    std::srand(65); // Set seed for reproducibility

    for (int i = 0; i < num_lines; ++i) {
        if (i % 2 == 0) {
            // C line: C col start end
            int col = std::rand() % col_limit;
            int start = std::rand() % row_limit;
            int end = start + (std::rand() % 16); // Up to 15 steps ahead
            if (end >= row_limit) end = row_limit - 1;
            outfile << "C " << col << " " << start << " " << end << "\n";
        } else {
            // R line: R row start end
            int row = std::rand() % row_limit;
            int start = std::rand() % col_limit;
            int end = start + (std::rand() % 16); // Up to 15 steps ahead
            if (end >= col_limit) end = col_limit - 1;
            outfile << "R " << row << " " << start << " " << end << "\n";
        }
    }

    outfile.close();
    std::cout << "Generated 1000 lines in output.txt\n";
    return 0;
}
