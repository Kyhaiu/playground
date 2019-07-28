#ifndef FIRE_H_INCLUDED
#define FIRE_H_INCLUDED
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <time.h>
#include <iostream>

class Fire{
    private:
        std::vector<std::tuple<int, char>> fireArray;
        int fireWidth;
        int fireHeight;
        int fireArea;
    public:
        Fire();
        Fire(int width, int height);
        ///getters da classe
        int getFireWidth();
        int getFireHeight();
        int getFireArea();
        ///setters da classe
        void setFireWidth(int width);
        void setFireHeight(int height);
        void setFireArea(int width, int height);
        ///metodos da classe
        void createFireDataStructure();
        void createFireSource();
        void calculateFirePropagation();
        void updateFireIntensifyPerPixel(int curretnPixelIndex);
        void showFire();
};

#endif // FIRE_H_INCLUDED
