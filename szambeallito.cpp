#include "szambeallito.hpp"
#include "graphics.hpp"
#include <sstream>

using namespace genv;
using namespace std;
Szambeallito::Szambeallito(int x,int y,int sx,int sy,int mini,int maxi)
:Widget(x,y,sx,sy),min_val(mini),max_val(maxi)
{
    num_val=(min_val+max_val)/2;

    ss_convert();
}
void Szambeallito::draw()const{
     gout << move_to(xhely, yhely) << color(255,255,255) << box(XX,YY);
     gout << move_to(xhely+1, yhely+1) << color(0,0,0) << box(XX-2,YY-2);
     gout << move_to(xhely+2, yhely+20) << color(70,255,255) << text(val_on_screen);
     gout << move_to(xhely+XX-YY/2, yhely) << color(255,255,255) << box(YY/2,YY/2);

    gout << move_to(xhely+XX-YY/2+1, yhely+1) << color(0,0,0) << box(YY/2-2,YY/2-2);
    gout << move_to(xhely+XX-YY/2, yhely + YY/2) << color(250,250,250) << line_to(xhely + XX - YY/4, yhely);
    gout << line_to(xhely + XX, yhely + YY/2);

    gout << move_to(xhely+XX-YY/2, yhely + YY/2) << color(255,255,255) << box(YY/2,YY/2);
    gout << move_to(xhely+XX-YY/2+1, yhely + YY/2+1) << color(0,0,0) << box(YY/2-2,YY/2-2);
    gout << move_to(xhely+XX-YY/2, yhely + YY/2) << color(250,250,250) << line_to(xhely + XX - YY/4, yhely + YY);
    gout << line_to(xhely + XX, yhely + YY/2);
}
void Szambeallito::handle(event ev){
    if(ev.type==ev_mouse && Up(ev.pos_x,ev.pos_y) && ev.button==btn_left && num_val<max_val){
        inc(1);
    }else if(ev.type==ev_mouse && Down(ev.pos_x,ev.pos_y) && ev.button==btn_left && num_val>min_val){
        dec(1);
    }
    if (ev.type == ev_key && ev.keycode == key_up && num_val < max_val) {
            inc(1);
        } else if (ev.type == ev_key && ev.keycode == key_down && min_val < num_val) {
            dec(1);
        }
       else if (ev.type == ev_key && ev.keycode == key_pgup && num_val +10 <= max_val) {
            inc(10);
        } else if (ev.type == ev_key && ev.keycode == key_pgdn && min_val <= num_val -10) {
            dec(10);
        }
        ss_convert();

}

bool Szambeallito::Up(int pos_x,int pos_y){
    return pos_x>xhely+XX-YY/2 && pos_x < xhely+XX && pos_y>yhely && pos_y< yhely+YY/2;
}
bool Szambeallito::Down(int pos_x,int pos_y){
    return pos_x>xhely+XX-YY/2 && pos_x < xhely+XX && pos_y>yhely+YY/2 && pos_y< yhely+YY;
}
void Szambeallito::inc(int i){
    num_val+=i;
}
void Szambeallito::dec(int i){
    num_val-=i;
}
void Szambeallito::ss_convert(){
    stringstream ss;
    ss<<num_val;ss>>val_on_screen;
}
