#include "headers/Controller.h"

Controller::Controller(List *lista, Vector *vector, Map *map, Set *set) : lista {lista}, vector {vector}, map {map}, set {set} {
    lista->citireFilmeDinFisier();
    vector->citireSerialeDinFisier();
    map->citireImaginiDinFisier();
    set->citireScurtmetrajeDinFisier();
}

Controller::~Controller() {}


