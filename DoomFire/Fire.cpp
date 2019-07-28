#include "Fire.h"

Fire::Fire(){
    setFireWidth(10);
    setFireHeight(10);
    setFireArea(10, 10);
}

Fire::Fire(int width, int height){
    setFireWidth(width);
    setFireHeight(height);
    setFireArea(width, height);
}

int Fire::getFireWidth(){
    return fireWidth;
}

int Fire::getFireHeight(){
    return fireHeight;
}

int Fire::getFireArea(){
    return fireArea;
}

void Fire::setFireWidth(int width){
    fireWidth = width;
}

void Fire::setFireHeight(int height){
    fireHeight = height;
}

void Fire::setFireArea(int width, int height){
    fireArea = width * height;
}

void Fire::createFireDataStructure(){
    int numberOfPixels = getFireArea();
    std::tuple<int, char> valuesInitialFire;
    std::get<0>(valuesInitialFire) = 0;
    std::get<1>(valuesInitialFire) = '*';
    for(int i = 0; i < numberOfPixels; i++){
            fireArray.push_back(valuesInitialFire);
    }
}

void Fire::createFireSource(){
    const int overFlowPixelIndex = getFireWidth() * getFireHeight();
    for(int column = 0; column < getFireWidth(); column++){
        const int pixelIndex = (overFlowPixelIndex - getFireWidth()) + column;
        std::get<0>(fireArray[pixelIndex]) = 36;
    }
}

void Fire::calculateFirePropagation(){
    int w = getFireWidth();
    int h = getFireHeight();
    int pixelIndex = 0;
    for(int column = 0; column < w; column++){
        for(int row = 0; row < h; row++){
            pixelIndex = column + (w * row);
            updateFireIntensifyPerPixel(pixelIndex);
        }
    }
}

void Fire::updateFireIntensifyPerPixel(int curretPixelIndex){
    int belowPixelIndex = curretPixelIndex + getFireWidth();

    if(belowPixelIndex >= getFireArea()){
        return;
    }

    int cooling = rand()%5;

    int belowPixelFireIndex = std::get<0>(fireArray[belowPixelIndex]);
    int newFireIntesity = belowPixelFireIndex - cooling;

    if(newFireIntesity >= 0 ){
        std::get<0>(fireArray[curretPixelIndex - cooling]) = newFireIntesity;
    } else{
        std::get<0>(fireArray[curretPixelIndex - cooling]) = 0;
    }
}

void Fire::showFire(){
    int aux = 0;
    int w = getFireWidth();
    int h = getFireHeight();
    for(int row = 0; row < w; row++){
        for(int column = 0; column < h; column++){
            aux = column + (w * row);
            if(std::get<0>(fireArray[aux]) != 0){
                if(std::get<0>(fireArray[aux]) <= 36 && std::get<0>(fireArray[aux]) >= 34){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15+15*16);
                }else if(std::get<0>(fireArray[aux]) < 34 && std::get<0>(fireArray[aux]) >= 29){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14+14*16);
                }else if(std::get<0>(fireArray[aux]) < 29 && std::get<0>(fireArray[aux]) >= 20){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6+6*16);
                }else if(std::get<0>(fireArray[aux]) < 20 && std::get<0>(fireArray[aux]) >= 10){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12+12*16);
                }else if(std::get<0>(fireArray[aux]) < 10 && std::get<0>(fireArray[aux]) >= 1){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4+4*16);
                }
                std::cout << std::get<1>(fireArray[aux]) << " ";
            } else{
                std::cout << "  ";
            }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7+0*16);
        }
        std::cout << std::endl;
    }
}
