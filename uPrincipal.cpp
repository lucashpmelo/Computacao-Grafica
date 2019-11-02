//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uJanela.h"
#include "uPrincipal.h"
#include "uPonto.h"
#include "uPoligono.h"
#include "uDisplay.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTFormPrincipal *TFormPrincipal;

Janela mundo(-250,-250,250,250);
Janela vp(0,0,500,500);
Ponto aux;
Poligono pol;
Display display;
bool novo = false;
int contId = 1;
int TipoDesenho=0;
//---------------------------------------------------------------------------
__fastcall TTFormPrincipal::TTFormPrincipal(TComponent* Owner)
        : TForm(Owner)
{
    //eixo vertical
    pol.pontos.push_back(Ponto(0, mundo.yMax));
    pol.pontos.push_back(Ponto(0, mundo.yMin));
    pol.id = contId++;
    display.poligonos.push_back(pol);
    pol.pontos.clear();

    //eixo horizontal
    pol.pontos.push_back(Ponto(mundo.xMax , 0));
    pol.pontos.push_back(Ponto(mundo.xMin, 0));
    pol.id = contId++;
    display.poligonos.push_back(pol);
    pol.pontos.clear();

    display.desenha(Image1->Canvas, mundo, vp, 0);



}
//---------------------------------------------------------------------------

void __fastcall TTFormPrincipal::Image1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    double xW,yW;
    Label1->Caption = "( "+ IntToStr(X) +", " + IntToStr(Y) + ")";
    xW=xvp2mundo(X,mundo,vp);
    yW=yvp2mundo(Y,mundo,vp);
    Label2->Caption = "( "+ FloatToStr(xW) +", " + FloatToStr(yW) + ")";
}
//---------------------------------------------------------------------------
double TTFormPrincipal:: xvp2mundo(int x, Janela mundo, Janela vp){
    return ((x-vp.xMin)/(vp.xMax-vp.xMin))*(mundo.xMax-mundo.xMin)+mundo.xMin;
}
double TTFormPrincipal::yvp2mundo (int y, Janela mundo, Janela vp){
    return(1-(y-vp.yMin)/(vp.yMax-vp.yMin))*(mundo.xMax-mundo.xMin)+mundo.yMin;
}


//------------------------------------------------
void __fastcall TTFormPrincipal::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if (novo) {
        if (Button == mbLeft) {
            aux.x = xvp2mundo(X, mundo, vp);
            aux.y = yvp2mundo(Y, mundo, vp);
            //ShowMessage(aux.mostra());
            pol.pontos.push_back(aux);
            pol.mostra(lbPontos);
        } else {
            pol.id = contId++;
            display.poligonos.push_back(pol);
            pol.pontos.clear();
            novo = false;
            display.mostra(lbPoligonos);
            display.desenha(Image1->Canvas, mundo, vp, rgTipoDesenho->ItemIndex);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TTFormPrincipal::Button1Click(TObject *Sender)
{
/*
        ListBox1->Items->Clear();
                for(int i = 0; i < pol.pontos.size(); i++){
                        ListBox1->Add(pol.pontos[i].mostra());
        }
        pol.mostra(lbPontos);
*/
}
//---------------------------------------------------------------------------


void __fastcall TTFormPrincipal::btNovoClick(TObject *Sender)
{
    novo = true;    
}
//---------------------------------------------------------------------------






void __fastcall TTFormPrincipal::lbPoligonosClick(TObject *Sender)
{
    //ShowMessage( IntToStr(lbPoligonos->ItemIndex));
}
//---------------------------------------------------------------------------

void __fastcall TTFormPrincipal::btTranslacaoClick(TObject *Sender)
{
    /*double dx, dy;
    dx = StrToFloat(edX->Text);
    dy = StrToFloat(edY->Text);
    if (lbPoligonos->ItemIndex >= 0) {
        display.poligonos[lbPoligonos->ItemIndex].translada(dx, dy);
        display.desenha(Image1->Canvas, mundo, vp, rgTipoDesenho->ItemIndex);
    }
    else
        ShowMessage("ERROR!"); */
}
//---------------------------------------------------------------------------


void __fastcall TTFormPrincipal::btRotacionaClick(TObject *Sender)
{

    /*double graus;
    graus = StrToFloat(etGraus->Text);
    
    if (lbPoligonos->ItemIndex >= 0) {
        display.poligonos[lbPoligonos->ItemIndex].rotaciona(graus);
        display.desenha(Image1->Canvas, mundo, vp, rgTipoDesenho->ItemIndex);
    }
    else
        ShowMessage("ERROR!");*/

}
//---------------------------------------------------------------------------

void __fastcall TTFormPrincipal::btFlexionaClick(TObject *Sender)
{
        /*if (lbPoligonos->ItemIndex >= 0) {
                display.poligonos[lbPoligonos->ItemIndex].reflexo();
                display.desenha(Image1->Canvas, mundo, vp, rgTipoDesenho->ItemIndex);
        }
        else
        ShowMessage("ERROR!");*/
}
//---------------------------------------------------------------------------


void __fastcall TTFormPrincipal::btEscalonaClick(TObject *Sender)
{
        /*double dx, dy;
        dx = StrToFloat(edX->Text);
        dy = StrToFloat(edY->Text);

        if (lbPoligonos->ItemIndex >= 0) {
                display.poligonos[lbPoligonos->ItemIndex].escalona(dx, dy);
                display.desenha(Image1->Canvas, mundo, vp, rgTipoDesenho->ItemIndex);
        }
        else
        ShowMessage("ERROR!");   */
}
//---------------------------------------------------------------------------





void __fastcall TTFormPrincipal::rgTipoDesenhoClick(TObject *Sender)
{
   display.desenha(Image1->Canvas,mundo, vp, rgTipoDesenho->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TTFormPrincipal::Button2Click(TObject *Sender)
{
        mundo.yMax += 10;
        mundo.yMin += 10;
        display.desenhaEixo(Image1->Canvas,mundo,vp);        
}
//---------------------------------------------------------------------------

void __fastcall TTFormPrincipal::Button3Click(TObject *Sender)
{
        mundo.yMax -= 10;
        mundo.yMin -= 10;
        display.desenhaEixo(Image1->Canvas,mundo,vp);        
}
//---------------------------------------------------------------------------

void __fastcall TTFormPrincipal::Button5Click(TObject *Sender)
{
        mundo.xMax += 10;
        mundo.xMin += 10;
        display.desenhaEixo(Image1->Canvas,mundo,vp);        
}
//---------------------------------------------------------------------------

void __fastcall TTFormPrincipal::Button4Click(TObject *Sender)
{
        mundo.xMax -= 10;
        mundo.xMin -= 10;
        display.desenhaEixo(Image1->Canvas,mundo,vp);        
}
//---------------------------------------------------------------------------

void __fastcall TTFormPrincipal::Button6Click(TObject *Sender)
{
        mundo.yMax -= 10;
        mundo.yMin += 10;
        mundo.xMax -= 10;
        mundo.xMin += 10;
        display.desenhaEixo(Image1->Canvas,mundo,vp);
}
//---------------------------------------------------------------------------

void __fastcall TTFormPrincipal::Button7Click(TObject *Sender)
{
        mundo.yMax += 10;
        mundo.yMin -= 10;
        mundo.xMax += 10;
        mundo.xMin -= 10;
        display.desenhaEixo(Image1->Canvas,mundo,vp);
}
//---------------------------------------------------------------------------

