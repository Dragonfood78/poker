#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED
#include "graphics.hpp"


class Widget{
protected:
    int xhely,yhely;
    int XX,YY;
public:
    Widget(int ,int ,int ,int);
    virtual void draw()const;
    virtual void handle(genv::event ev);
    virtual bool flag(int, int)const;

};


#endif // WIDGET_HPP_INCLUDED
