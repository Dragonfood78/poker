#include "widget.hpp"
#include "graphics.hpp"
Widget::Widget(int x,int y,int sx,int sy)
{
    xhely=x;
    yhely=y;
    XX=sx;
    YY=sy;
}
bool Widget::flag(int pos_x,int pos_y)const{
    return pos_x>xhely && pos_y>>yhely && pos_x<xhely+XX && pos_y<yhely+YY;

}

void Widget::draw()const{}
void Widget::handle(event ev){};
