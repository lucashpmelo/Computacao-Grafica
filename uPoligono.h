//---------------------------------------------------------------------------

#ifndef uPoligonoH
#define uPoligonoH
#include<vector>
#include <StdCtrls.hpp>   
#include "uPonto.h"
#include "uJanela.h"
#define PI 3.14159265

using namespace std;
//---------------------------------------------------------------------------
class Poligono{
    public:
        vector <Ponto> pontos;
        int id, TipoDesenho;

        double PontoCentralX();
        double PontoCentralY();

        void mostra(TListBox *retorno);
        void desenha(TCanvas *canvas, Janela mundo, Janela vp, int tipoReta);
        
        void drawBresenham(TCanvas *canvas, int x1, int y1, int x2, int y2);
        void drawDDA(TCanvas *canvas, int x1, int y1, int x2, int y2);

        void translada(double x, double y, double *px, double *py, boolean homogenea);
        void escalona(Janela mundo,Janela vp,double x, double y, double *px, double *py, double Xc, double Yc,boolean homogenea);
        void rotacao(double teta, double *px, double *py, double Xc, double Yc,boolean homogenea);
        void reflexo (int op);
        void reflexo ();
};



#endif
 