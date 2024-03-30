#ifndef PRACTICUMATTESTATION_KR1_05_H
#define PRACTICUMATTESTATION_KR1_05_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

struct grade {
    std::string subject;
    std::string date;
    int mark;
};

struct student {
    std::string number;
    std::string first_name;
    std::string birthday;
    std::string group;
    grade result;
};

class kr1_05 {
private:
    std::vector <student> list;

public:
    kr1_05();
    kr1_05 (std::string path);
    kr1_05& operator= (const kr1_05 &obj);
    friend std::ostream& operator<< (std::ostream& os, const kr1_05& obj);
    void toFile (std::string filename);
    std::vector <student> search (int mark);
    float calculate (std::string subject);
    void pushBack (student unit);
    void removeItems (int count);
};



#endif //PRACTICUMATTESTATION_KR1_05_H

