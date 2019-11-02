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
        char nome;

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
        void Poligono::reflexoX();
        void Poligono::reflexoY();
        void Poligono::circunferencia(Ponto aux, int r);

        void Poligono::casteljau(Ponto p1, Ponto p2, Ponto p3, double limite);
        void Poligono::hermite(Ponto p1, Ponto p2, Ponto p3, Ponto p4);
        void Poligono::bezier(Ponto p1, Ponto p2, Ponto p3, Ponto p4);
        void Poligono::bSpline(Ponto p1, Ponto p2, Ponto p3, Ponto p4);
        void Poligono::fwdDifferences(Ponto p1, Ponto p2, Ponto p3, Ponto p4);

        Poligono Poligono::clipping(Janela clip, int nPol);
        Ponto Poligono::setPonto(Ponto aux, double x, double y);

};



#endif
 