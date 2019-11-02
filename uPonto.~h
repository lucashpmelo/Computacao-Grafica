//---------------------------------------------------------------------------

#ifndef uPontoH
#define uPontoH

#include "uJanela.h"
#include<system.hpp>
#include<SysUtils.hpp>
//---------------------------------------------------------------------------
class Ponto{
    public:
        double x;
        double y;

        Ponto();
        Ponto(double xN, double yN);
        int xw2vp(Janela mundo, Janela vp);
        int yw2vp(Janela mundo, Janela vp);
        AnsiString mostra();

        void translada (double dx, double dy);
        void escalona (double dx, double dy);
        void rotaciona (double graus);
        void reflexo (int op);
        void reflexoX();
        void reflexoY();
        void reflexoXY();
};

#endif
