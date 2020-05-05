#ifndef SZAMBEALLITO_HPP_INCLUDED
#define SZAMBEALLITO_HPP_INCLUDED
#include "widget.hpp"
#include <string>
class Szambeallito:public Widget{
    int num_val;
    std::string val_on_screen;
    int min_val,max_val;
 public:
     Szambeallito(int,int ,int , int ,int, int);
     virtual void draw()const;
     virtual void handle(genv::event);
     virtual bool Up(int,int);
     virtual bool Down(int,int);
     virtual void inc(int);
     virtual void dec(int);
     virtual void ss_convert();

};


#endif // SZAMBEALLITO_HPP_INCLUDED
