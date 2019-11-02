//---------------------------------------------------------------------------
#ifndef uDisplayH
#define uDisplayH

#include <vector>
#include "uPoligono.h"
#include <SysUtils.hpp>
#include "uJanela.h"

#include <StdCtrls.hpp>

using namespace std;
//---------------------------------------------------------------------------
class Display{
    public:
        vector<Poligono> poligonos;

        void mostra(TListBox *retorno);
        void desenha(TCanvas *canvas, Janela mundo, Janela vp, int tipoReta);
        void desenhaEixo(TCanvas *canvas, Janela mundo, Janela vp);
        void escalonaDisplay(Janela mundo, Janela vp,double auxX,double auxY,int indice,boolean display,boolean homogenea);
        void rotacionaDisplay(Janela mundo, Janela vp,double teta,int indice,boolean display,boolean homogenea);
        void translocaDisplay(Janela mundo, Janela vp,double auxX,double auxY,int indice,boolean display,boolean homogenea);

};
#endif



