#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "game.hpp"
#include <vector>
#include <random>
#include <array>
using namespace std;


Game::Game(Player& player1,Player& player2):player1(player1),player2(player2){
    this->last="";
    this->log="";
    create();
    shuffle();
    split();
    
 
}
void Game::create(){
    for(int num=2;num<15;num++){
        for(string type :{"hearts","clubs","diamonds","spades"}){
            Card card(type,num);
            this->cards.push_back(card);
        }
    }
}
void Game::shuffle(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(cards.begin(),cards.end(),gen);
}
void Game::split(){
    for(int i=0;i<26;i++){
        this->player1.pushCard(this->cards.back());
        this->cards.pop_back();
    }
    for(int i=0;i<26;i++){
        this->player2.pushCard(this->cards.back());
        this->cards.pop_back();
    }      
}

void Game:: playTurn(){
    
    if(this->player1.stacksize()==0 ||this->player2.stacksize()==0){
        throw invalid_argument("there is no more cards");
    }
    if(&this->player1 == &this->player2){
        throw invalid_argument("there is no more cards");
    }
    
        Card player1_card =this->player1.removeCard();
        Card player2_card =this->player2.removeCard();
        

        if(player1_card.getnumber()>player2_card.getnumber()){
            player1.addwin(2);
            player2.addloss();
            last=player1.getname()+"won with"+player1_card.gettype()+to_string(player1_card.getnumber())+"on"+player2.getname()+"with"+player2_card.gettype()+to_string(player2_card.getnumber());
            log+=last=player1.getname()+"won with"+player1_card.gettype()+to_string(player1_card.getnumber())+"on"+player2.getname()+"with"+player2_card.gettype()+to_string(player2_card.getnumber());
        }
        if(player1_card.getnumber()<player2_card.getnumber()){
            player2.addwin(2);
            player1.addloss(); 
            last=player2.getname()+"won with"+player2_card.gettype()+to_string(player2_card.getnumber())+"on"+player1.getname()+"with"+player1_card.gettype()+to_string(player1_card.getnumber());    
            log+=player2.getname()+"won with"+player2_card.gettype()+to_string(player2_card.getnumber())+"on"+player1.getname()+"with"+player1_card.gettype()+to_string(player1_card.getnumber());     
        }
        else{
            int points_ = 2;
            while(player1_card.getnumber()==player2_card.getnumber()){

                if(player1.stacksize()<2){
                    points_ += player1.stacksize()*2;
                    player1.addwin(points_/2);
                    player2.addwin(points_/2);
                    while(player1.stacksize())
                    {
                        player1.removeCard();
                        player2.removeCard();
                    }
                    break;
                }

            

                player1.adddraw();
                player2.adddraw();
                player1.removeCard();
                player2.removeCard();
                player1_card=player1.removeCard();
                player2_card=player2.removeCard();
                points_ += 4;
                last="draw"+player1.getname()+player1_card.gettype()+to_string(player1_card.getnumber())+"with"+player2.getname()+player2_card.gettype()+to_string(player2_card.getnumber());
                log+="draw"+player1.getname()+player1_card.gettype()+to_string(player1_card.getnumber())+"with"+player2.getname()+player2_card.gettype()+to_string(player2_card.getnumber());
                if(player1_card.getnumber()>player2_card.getnumber()){
                    player1.addwin(points_);
                    player2.addloss();
                }
                else if(player1_card.getnumber()<player2_card.getnumber()){
                    player2.addwin(points_);
                    player1.addloss();
                }
                else {
                    cout<< "draw again"<<endl;
                    
                }   
            }
        }
    }


void Game::printLastTurn(){
    cout<<this->last<<endl;
}

void Game::playAll(){
    while(player1.stacksize()){
        std::cout << player1.stacksize() << endl;
        playTurn();
    }

}

void Game::printWiner(){
    if(player1.getwin()>player2.getwin()){
        cout<<player1.getname()+"won"<<endl;
    }
    if(player1.getwin()<player2.getwin()){
        cout<<player2.getname()+"won"<<endl;
    }
    else{
        cout<<"draw"<<endl;
    }

}

void Game::printLog(){
    cout<<this->log<<endl;
}


void Game::printStats(){
    cout<<player1.getname()+"state is:"<<endl;
    cout<<"wins:"+to_string(player1.getwin())<<endl;
    cout<<"losses:"+to_string(player1.getloss())<<endl;
    cout<<"draws:"+to_string(player1.getdraw())<<endl;
    cout<<player2.getname()+"state is:"<<endl;
    cout<<"wins:"+to_string(player2.getwin())<<endl;
    cout<<"losses:"+to_string(player2.getloss())<<endl;
    cout<<"draws:"+to_string(player2.getdraw())<<endl;

}
