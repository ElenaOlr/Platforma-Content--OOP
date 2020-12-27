#include <iostream>
#include "controller/headers/Vector.h"
#include "controller/headers/Controller.h"
#include "view/headers/UI.h"

using namespace std;
int main()
{
    string fisierSeriale = "../fisiere/fisierSeriale.txt";
    string fisierFilme = "../fisiere/fisierFilme.txt";
    string fisierImagini = "../fisiere/fisierImagini.txt";
    string fisierScurtmetraje = "../fisiere/fisierScurtmetraje.txt";

    //noile obiecte create returneaza un pointer catre acele obiecte
    Vector *vector = new Vector(fisierSeriale);
    List *list = new List(fisierFilme);
    Map *map = new Map(fisierImagini);
    Set *set = new Set(fisierScurtmetraje);
    //passing by pointers https://www.geeksforgeeks.org/passing-by-pointer-vs-passing-by-reference-in-c/
    Controller controller{list, vector, map, set};
    UI ui{controller};
    ui.meniuPrincipal();

    return 0;
}