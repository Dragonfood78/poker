#ifndef KIVALASZTO_HPP_INCLUDED
#define KIVALASZTO_HPP_INCLUDED
#include "widget.hpp"
#include <vector>
#include <string>
using namespace std;
using namespace genv;
class Kiv:public Widget{
    vector<string> names;
    vector<string> actual_names;
    vector<int> actual_names_id;
    vector<string> refresh_vector(int,int);
     int  selected_name_id;
     int  actual_line_id;
     int  row_number;
public:
    Kiv(int,int,int,int,vector<string>, int);
    virtual void draw()const;
    virtual void handle(event ev);
    virtual void refresh_list();
};

#endif // KIVALASZTO_HPP_INCLUDED
