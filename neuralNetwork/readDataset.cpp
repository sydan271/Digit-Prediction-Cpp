#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include "readDataset.h"

void load_mnist_csv(const std::string& filename, 
                    std::vector<std::vector<double>>& X_data, 
                    std::vector<int>& Y_labels) {
    
    std::ifstream file(filename);
    std::string line;
    
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << "\n";
        return;
    }

    // Read the file line by line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string val;
        
        // 1. Extract the first column (The Label)
        if (std::getline(ss, val, ',')) {
            Y_labels.push_back(std::stoi(val));
        }
        
        // 2. Extract the remaining 784 columns (The Pixels)
        std::vector<double> pixels;
        pixels.reserve(784); // Optimize memory allocation
        
        while (std::getline(ss, val, ',')) {
            // Convert to double and normalize from 0-255 down to 0.0-1.0
            pixels.push_back(std::stod(val) / 255.0);
        }
        
        X_data.push_back(pixels);
    }
}