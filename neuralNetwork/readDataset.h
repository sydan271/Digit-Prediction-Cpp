#ifndef READDATASET_H
#define READDATASET_H
//got this from stackoverflow, it reads a csv file and stores the data in a vector of vectors
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

// This function takes empty vectors and fills them with the CSV data
void load_mnist_csv(const std::string& filename, std::vector<std::vector<double>>& X_data, std::vector<int>& Y_labels);

#endif // READDATASET_H