//---------------------------------------------------------------------------


#pragma hdrstop


#include "uPonto.h"
#include <math.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)
Ponto::Ponto(){
    x = y = 0;
}

Ponto::Ponto(double xN, double yN){
    x = xN;
    y = yN;
}
    int Ponto::xw2vp(Janela mundo, Janela vp){
        return((x - mundo.xMin) / (mundo.xMax - mundo.xMin)) *
            (vp.xMax-vp.xMin);
    }
    int Ponto::yw2vp(Janela mundo,Janela vp){
        return (1 - (y - mundo.yMin) / (mundo.yMax-mundo.yMin)) *
            (vp.xMax-vp.xMin);
    }

AnsiString Ponto::mostra(){
    return "(" + FloatToStr(x) + ", " + FloatToStr(y) + ")";
}

void Ponto::translada (double dx, double dy){
    x += dx;
    y += dy;
}

void Ponto::escalona (double dx, double dy){
    x *= dx;
    y *= dy;
}

void Ponto::rotaciona (double graus){
    graus = (graus/180)*M_PI;
    double aux = x;
    x = x*cos(graus) - y*sin(graus);
    y = aux*sin(graus) + y*cos(graus);
}

void Ponto::reflexoX (){
        x *= -1;
}

void Ponto::reflexoY (){
        y *= -1;
}

void Ponto::reflexoXY (){
        reflexoX();
        reflexoY();
}

//REGIONCODE CLIPPING
int Ponto::regionCode(Janela clip)
{
int cohen = 0;

        cohen += (x < clip.xMin) ? 1 : 0;
        cohen += (x > clip.xMax) ? 2 : 0;
        cohen += (y < clip.yMin) ? 4 : 0;
        cohen += (y > clip.yMax) ? 8 : 0;

return cohen;
}
