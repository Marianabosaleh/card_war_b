#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <string>
using namespace std;
namespace ariel {}
using namespace ariel;



class Card{
    std::string type;
    int number;

    public:
    Card(string type,int number);


    void settype(string type);
    void setnumber(int number);
    string gettype();
    int getnumber();

    
};

    