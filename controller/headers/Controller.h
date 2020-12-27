
#ifndef MAIN_CPP_CONTROLLER_H
#define MAIN_CPP_CONTROLLER_H


#include "List.h"
#include "Vector.h"
#include "Map.h"
#include "Set.h"

class Controller {
List* lista;
Vector* vector;
Map* map;
Set* set;
public:
    Controller(List* lista, Vector* vector, Map* map, Set* set);
    List* getLista() const { return lista; }
    Vector* getVector() const { return vector; }
    Map* getMap() const {return map; }
    Set* getSet() const {return set; }

    ~Controller();

};


#endif //MAIN_CPP_CONTROLLER_H
