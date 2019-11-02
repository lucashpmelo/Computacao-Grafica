//---------------------------------------------------------------------------
#pragma hdrstop
#include "uDisplay.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
void Display::mostra(TListBox *retorno){
    retorno->Items->Clear();
    for(unsigned int i = 0; i < poligonos.size(); i++){
        retorno->Items->Add(IntToStr(poligonos[i].id));
    }
}

void Display::desenha(TCanvas *canvas, Janela mundo, Janela vp, int tipoReta){
    canvas->Pen->Color = clBlack;
    canvas->Pen->Width = 3; //grossura da caneta(ocupa 3 pixels)
    canvas->Brush->Color = clWhite;
    canvas->FillRect(Rect(0,0,500,500));

    for(unsigned int i = 0; i < poligonos.size(); i++){
        if (i > 1){
            canvas->Pen->Color = clRed;
        }
        poligonos[i].desenha(canvas, mundo, vp, tipoReta);
    }
}

void Display::desenhaEixo(TCanvas *canvas,Janela mundo, Janela vp){

  canvas->FillRect(Rect(1,1,500,500));
  poligonos[0].pontos[0].x = 0;
  poligonos[0].pontos[0].y = mundo.yMax;	//eixo y de cima para baixo
  poligonos[0].pontos[1].x=0;
  poligonos[0].pontos[1].y = mundo.yMin;
  poligonos[1].pontos[0].x = mundo.xMin;
  poligonos[1].pontos[0].y = 0;	//eixo x da esquerda pra direita
  poligonos[1].pontos[1].x = mundo.xMax;
  poligonos[1].pontos[1].y = 0;

  desenha(canvas,mundo,vp,0);

}

