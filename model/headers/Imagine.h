#ifndef MAIN_CPP_IMAGINE_H
#define MAIN_CPP_IMAGINE_H
#include <string>
using namespace std;
class Imagine {
public:
    string tipImagine;
    int rezolutie_x, rezolutie_y;
public:
    virtual float getSize() = 0;

    void setRez_x(int x) {
        rezolutie_x = x;
    }

    void setRez_y(int y) {
        rezolutie_y = y;
    }

    string getTipImagine() {return tipImagine;}


    Imagine(string& tipImagineNou, int rezolutie_x, int rezolutie_y);
};


#endif //MAIN_CPP_IMAGINE_H
