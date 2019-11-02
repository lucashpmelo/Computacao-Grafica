//---------------------------------------------------------------------------


#pragma hdrstop
#include "uPoligono.h"
#include <math.h>


//---------------------------------------------------------------------------

#pragma package(smart_init)

void Poligono::mostra(TListBox *retorno){
    retorno->Items->Clear();
    for(unsigned int i = 0; i < pontos.size(); i++){
        retorno->Items->Add(pontos[i].mostra());
    }
}


void Poligono::desenha(TCanvas *canvas, Janela mundo, Janela vp, int tipoReta){
    int x, y, x1, y1, x2, y2;

        if(tipoReta == 0){
            for(unsigned int i = 0; i < pontos.size(); i++){
                x = pontos[i].xw2vp(mundo, vp);
                y = pontos[i].yw2vp(mundo, vp);

                if (i==0) {
                        canvas->MoveTo(x, y);
                } else {
                        canvas->LineTo(x, y);
                }
            }
        }
        else
        if(tipoReta == 1){
            for(unsigned int i = 1; i < pontos.size(); i++){
                x1 = pontos[i-1].xw2vp(mundo, vp);
                y1 = pontos[i-1].yw2vp(mundo, vp);
                x2 = pontos[i].xw2vp(mundo, vp);
                y2 = pontos[i].yw2vp(mundo, vp);

                drawDDA(canvas, x1, y1, x2, y2);
            }
        }
        if(tipoReta == 2){
                for(unsigned int i = 1; i < pontos.size(); i++){
                        x1 = pontos[i-1].xw2vp(mundo, vp);
                        y1 = pontos[i-1].yw2vp(mundo, vp);
                        x2 = pontos[i].xw2vp(mundo, vp);
                        y2 = pontos[i].yw2vp(mundo, vp);

                        drawBresenham(canvas, x1, y1, x2, y2);

            }
        }
}




















void Poligono::translada (double dx, double dy) {
    for(unsigned int i = 0; i < pontos.size(); i++){
        pontos[i].translada(dx, dy);
    }
}

void Poligono::escalona (double dx, double dy) {
    for(unsigned int i = 0; i < pontos.size(); i++){
        pontos[i].escalona(dx, dy);
    }
}


void Poligono::rotaciona (double graus) {
    
    for(unsigned int i = 0; i < pontos.size(); i++){
        pontos[i].rotaciona(graus);
    }
}

void Poligono::reflexo() {
        int i = pontos.size();

        for (int j = 0; j < i; j++) {
                pontos[j].reflexoX();
        }
}

void Poligono::drawDDA(TCanvas *canvas, int x1, int y1, int x2, int y2) {
#define SIGN(x)  ((x) < 0 ? (-1) : (1))
#define ABS(x)   ((x) < 0 ? (-x) : (x))
#define FLOOR(x) ((x) < 0 ? ( (x) - (int)(x) != 0 ? ((int)(x) - 1) : ((int)(x))) : (int)(x))
int length;
float x, y, deltay, deltax;

if( ABS( (x2 - x1) ) >= ABS( (y2 - y1) ))
        length = ABS( (x2 - x1) );
else
        length = ABS( (y2 - y1) );

deltax = (float) (x2 - x1) / (float) length;
deltay = (float) (y2 - y1) / (float) length;
x = x1 + 0.5 * SIGN (deltax);
y = y1 + 0.5 * SIGN (deltay);

for (int i = 0; i < length; i++) {
        canvas->Pixels[x][y] = clBlue;
        x += deltax;
        y += deltay;
}
}


void Poligono::drawBresenham(TCanvas *canvas, int x1, int y1, int x2, int y2) {
#define SIGN(x) ((x) < 0 ? (-1) : (1))
#define ABS(x) ((x) < 0 ? (-x) : (x))
#define FALSE 0
#define TRUE 1
int x, dx, y, dy, deltax, deltay, interchange, tmp, signalx, signaly;
double erro;

int i = pontos.size();

if (i > 1) {
        erro = 0;
        for (int j = 0; j < i - 1; j++) {


        deltax = ABS ( (x2 - x1) );
        deltay = ABS ( (y2 - y1) );
        signalx = SIGN ( (x2 - x1) );
        signaly = SIGN ( (y2 - y1) );

        x = x1;
        y = y1;

        if (signalx < 0){
                x -=1;
        }
        if (signaly < 0 ){
                y -= 1;
        }

        interchange = FALSE;
        if ( deltay > deltax) {
                tmp = deltax;
                deltax = deltay;
                deltay = tmp;
                interchange = TRUE;
        }
        erro = 2 * deltay - deltax;

        for (i = 0; i < deltax; i++) {
                canvas->Pixels[x][y] = clBlack;

                while (erro >= 0) {
                        if (interchange){
                                x = x + signalx;
                        }else{
                                y = y + signaly;
                        }
                erro = erro-2 * deltax;
                } // encerra while
                if (interchange){
                        y = y + signaly;
                }else{
                        x = x + signalx;
                }
                erro = erro+2 * deltay;
        }//encerra for
    }//encerra for
  }//encerra if
}//encerra funcao
