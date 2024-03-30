#include "kr1_05.h"

kr1_05::kr1_05() {

}

kr1_05::kr1_05(std::string path) {
    std::ifstream file (path, std::ios::binary);
    if (file.is_open()) {
        std::string row;
        while (std::getline(file, row)) {
            std::istringstream iss(row);
            std::string word;
            student unit;
            int count = 0;
            while (iss >> word) {
                if (count == 0) { unit.number = word; }
                else if (count == 1) { unit.first_name = word; }
                else if (count == 2) { unit.birthday = word; }
                else if (count == 3) { unit.group = word; }
                else if (count == 4) { unit.result.subject = word; }
                else if (count == 5) { unit.result.date = word; }
                else { unit.result.mark = std::stoi(word); }
                count++;
            }
            this->list.push_back(unit);
        }
    }
    else {
        throw std::runtime_error("File does not exist");
    }
    file.close();
}

kr1_05 &kr1_05::operator= (const kr1_05 &obj) {
    if (this != &obj) {
        this->list = obj.list;
    }
    return *this;
}

std::ostream& operator<< (std::ostream& os, const kr1_05& obj) {
    std::string toOut;
    for (student unit: obj.list) {
        std::string row;
        row = unit.number + " " + unit.first_name + " " + unit.birthday + " " + unit.group + " " + unit.result.subject + " " + unit.result.date + " " + std::to_string(unit.result.mark) + "\n";
        toOut = toOut + row;
    }
    os << toOut;
    return os;
}

void kr1_05::toFile(std::string filename) {
    std::string toOut;
    for (student unit: this->list) {
        std::string row;
        row = unit.number + " " + unit.first_name + " " + unit.birthday + " " + unit.group + " " + unit.result.subject + " " + unit.result.date + unit.result.date + "\n";
        toOut = toOut + row;
    }
    std::ofstream file(filename.c_str(), std::ios::binary);
    file.write(toOut.c_str(), toOut.size());
}

std::vector <student> kr1_05::search (int mark) {
    std::vector <student> result;
    for (student unit: this->list) {
        if (unit.result.mark < mark) {
            result.push_back(unit);
        }
        else {
            continue;
        }
    }
    return result;
}

float kr1_05::calculate (std::string subject) {
    float sum = 0;
    int count = 0;
    for (student unit: this->list) {
        if (unit.result.subject == subject) {
            sum = sum + unit.result.mark;
            count++;
        }
        else {
            continue;
        }
    }
    return sum / count;
}

void kr1_05::pushBack(student unit) {
    this->list.push_back(unit);
}

void kr1_05::removeItems (int count) {
    if (count < 0 || count > this->list.size()) {
        throw std::out_of_range("Invalid count value");
    }
    auto it = this->list.begin();
    std::advance(it, count);
    this->list.erase(it, this->list.end());
}