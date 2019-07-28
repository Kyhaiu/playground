#include "Fire.h"
#include <unistd.h>
#include <windows.h>

using namespace std;

int main()
{

    Fire* f = new Fire(30, 30);

    f->createFireDataStructure();
    f->createFireSource();
    while(1){
        f->calculateFirePropagation();
        f->showFire();
        usleep(50000);
        system("cls");
    }
    return 0;
}
