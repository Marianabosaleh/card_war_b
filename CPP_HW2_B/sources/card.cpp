#include <iostream>
#include <fstream>
#include <sstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include "card.hpp"
using namespace std;
namespace ariel {}
using namespace ariel;


Card::Card(string type,int number){
   
    this->type=type;
    this->number=number;
}


void Card::settype(string type){
    this->type=type;
}
void Card::setnumber(int number){
    this->number=number;
}
string Card::gettype(){
    return this->type;
}

int Card::getnumber(){
    return this->number;
}