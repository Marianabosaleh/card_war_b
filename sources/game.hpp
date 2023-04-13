#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "player.hpp"
#include "card.hpp"
#include <vector>
#include <array>
using namespace std;
namespace ariel {}
using namespace ariel;



class Game{
    Player& player1;
    Player& player2;
    vector<Card> cards;
    bool over;
    void create();
    void shuffle();
    void split();
    std::string log;
    std::string last;


    public:
    Game();
    Game(Player& player1,Player& player2);
    void playTurn();
    void printLastTurn(); 
    void playAll(); 
    void printWiner(); 
    void printLog(); 
    void printStats();

};
