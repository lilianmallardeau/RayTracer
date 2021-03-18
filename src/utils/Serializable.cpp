//
// Created by lilian on 02/03/2021.
//

#include "Serializable.h"
#include <iostream>
#include <fstream>

void Serializable::serializeToFile(std::string filename) {
    std::ofstream file(filename, std::ios::trunc);
    file << toJSON().dump(4);
    file.close();
}
