#include "kivalaszto.hpp"
#include "graphics.hpp"
#include <iostream>
#include <vector>
using namespace std;
using namespace genv;
Kiv::Kiv(int x,int y,int sx,int sy,vector<string> a,int b):Widget(x,y,sx,sy),names(a),row_number(b)
{
    actual_line_id=0;
    selected_name_id=0;
    refresh_list();

}
void Kiv::draw()const{
    gout << move_to(xhely, yhely) << color(255,255,255) << box(XX, YY);
    gout << move_to(xhely+1, yhely+1) << color(0,0,0) << box(XX-2, YY-2);
     for(int i=0;i<actual_names.size();i++) {
        if(actual_line_id + i == selected_name_id) {
            gout << move_to(xhely, yhely +1 + i*25) << color(255,255,255) << box(XX, 25);
            gout << move_to(xhely+1, yhely +1 + i*25) << color(250,0,0) << box(XX-2,23);
            gout << move_to(xhely+2, yhely+20 + i*25) << color (255,255,255) << text(actual_names[i]);
        } else {
            gout << move_to(xhely, yhely +1 + i*25) << color(255,255,255) << box(XX, 25);
            gout << move_to(xhely+1, yhely+1 + i*25) << color(0,0,0) << box(XX-2, 23);
            gout << move_to(xhely+2, yhely+20 + i*25) << color (255,255,255) << text(actual_names[i]);
        }
    }

}
void Kiv::handle(event ev){
    if(ev.type == ev_mouse && ev.button == btn_wheeldown) {
        actual_line_id++;
        refresh_list();
    } else if(ev.type == ev_mouse && ev.button == btn_wheelup) {
            actual_line_id--;
            refresh_list();
        }
        else if(ev.type==ev_key && ev.keycode ==key_up){
            actual_line_id++;
            selected_name_id++;
            refresh_list();
        }else if(ev.type==ev_key && ev.keycode==key_down){
            actual_line_id--;
            selected_name_id--;
            refresh_list();
        }
        for(int i=0;i<row_number;i++) {
        if(ev.type == ev_mouse && ev.pos_x < xhely+XX && ev.pos_x > xhely && ev.pos_y > yhely + i*30 && ev.pos_y < yhely +(i+1)*30 && ev.button == btn_left) {
            selected_name_id = actual_line_id + i;
        }
    }

}

vector<string>Kiv::refresh_vector(int first,int last){
    vector<string>new_list(names.begin()+first,names.begin()+last);
    return new_list;
}

void Kiv::refresh_list(){
    if(row_number<names.size()){
        actual_names=refresh_vector(actual_line_id,actual_line_id+row_number);

    }
}


