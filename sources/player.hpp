#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "card.hpp"
#include <string>
#include <vector>
using namespace std;
namespace ariel {}
using namespace ariel;

class Player{
    std::string name;
    std::vector<Card> deck;

    int win;
    int loss;
    int draw;
    int points;
 
   public:
    Player();
    Player(string name);
    string getname(){return name;}
    void setname(string new_name);
    vector<Card> getdeck(){return deck;}
    void pushCard (Card card);
    Card removeCard ();
    int stacksize();
    int cardesTaken();
    void adddraw();
    void addloss();
    void addwin(int points_);
    int getdraw();
    int getloss();
    int getwin();
};
