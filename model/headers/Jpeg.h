
#ifndef MAIN_CPP_JPEG_H
#define MAIN_CPP_JPEG_H


#include "Imagine.h"

class Jpeg : public Imagine {
public:
    float getSize()
    {
        return(rezolutie_x*rezolutie_y*1024*1.35);
    }
    Jpeg(string& tipImagine, int x, int y);
};


#endif //MAIN_CPP_JPEG_H
