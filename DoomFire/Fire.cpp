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
    int w = getFireWidth();
    int h = getFireHeight();
    std::tuple<int, char> valuesInitialFire;
    std::get<0>(valuesInitialFire) = 0;
    std::get<1>(valuesInitialFire) = '*';
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            fireArray.push_back(valuesInitialFire);
        }
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
    for(int column = w; column >= 0; column--){
        for(int row = h; row >= 0; row--){
            const int pixelIndex = column + (w * row);
            updateFireIntensifyPerPixel(pixelIndex);
        }
    }
}

void Fire::updateFireIntensifyPerPixel(int curretPixelIndex){
    int belowPixelIndex = curretPixelIndex + getFireWidth();

    if(belowPixelIndex >= getFireArea()){
        return;
    }

    int cooling = rand()%6;
    const int belowPixelFireIndex = std::get<0>(fireArray[belowPixelIndex]);
    int newFireIntesity = belowPixelFireIndex - cooling;
    if(newFireIntesity > 0 ){
        std::get<0>(fireArray[curretPixelIndex - cooling]) = newFireIntesity;
    } else{
        std::get<0>(fireArray[curretPixelIndex- cooling]) = 0;
    }
}

void Fire::showFire(){
    int aux = 0;
    for(int i = 0; i < getFireWidth(); i++){
        for(int j = 0; j < getFireHeight(); j++){
            if(std::get<0>(fireArray[aux]) != 0){
                std::cout << std::get<1>(fireArray[aux]);
            }
            aux++;
        }
        std::cout << std::endl;
    }
}
