#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>
#include "player.hpp"
using namespace std;

Player::Player(){
    name="def";
}

Player::Player(string name){
    this->name=name;
    this->deck={};
    this->win=0;
    this->loss=0;
    this->draw=0;
    this->points=0;
}
void Player::setname(string new_name){
    this->name=new_name;
}
void Player::addwin(int points_) {
    win++;
    this->points += points_;
}

void Player::addloss(){
    loss++;
}
void Player::adddraw(){
    draw++;
}
int Player:: getdraw(){
    return draw;
}
int Player:: getloss(){
    return loss;
}
int Player:: getwin(){
    return win;
}
int Player::stacksize(){
    return deck.size();
}
int Player::cardesTaken(){
    return points;
}

void Player::pushCard (Card card){
    this->deck.push_back(card);
}

Card Player::removeCard (){
    Card card = this->deck.back();
    this->deck.pop_back();
    return card;
}