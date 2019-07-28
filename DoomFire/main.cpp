#include "Fire.h"
#include <unistd.h>
#include <windows.h>

using namespace std;

int main()
{

    Fire* f = new Fire(20, 50);

    f->createFireDataStructure();
    f->createFireSource();
    while(1){
        f->calculateFirePropagation();
        f->showFire();
        system("pause");
        system("cls");
    }
    return 0;
}
