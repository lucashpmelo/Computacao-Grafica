//---------------------------------------------------------------------------

#ifndef uPoligonoH
#define uPoligonoH
#include<vector>
#include <StdCtrls.hpp>   
#include "uPonto.h"
#include "uJanela.h"

using namespace std;
//---------------------------------------------------------------------------
class Poligono{
    public:
        vector <Ponto> pontos;
        int id, TipoDesenho;

        void mostra(TListBox *retorno);
        void desenha(TCanvas *canvas, Janela mundo, Janela vp, int tipoReta);
        void drawBresenham(TCanvas *canvas, int x1, int y1, int x2, int y2);
        void drawDDA(TCanvas *canvas, int x1, int y1, int x2, int y2);

        void translada (double dx, double dy);

        void escalona (double dx, double dy);
        void rotaciona (double graus);
        void reflexo (int op);
        void reflexo ();
};



#endif
 