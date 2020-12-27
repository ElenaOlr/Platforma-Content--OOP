
#ifndef MAIN_CPP_PNG_H
#define MAIN_CPP_PNG_H


#include "Imagine.h"

class Png : public Imagine {
public:
    float getSize()
    {
        return(rezolutie_x*rezolutie_y*1024*2.71);
    }
    Png(string& tipImagine, int x, int y);
};

#endif //MAIN_CPP_PNG_H
