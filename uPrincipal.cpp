//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
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
Poligono polaux;
Display display;
bool novo = false;
bool circulo = false;
int contId = 1;
int cirX;
int cirY;
int cirP;
int i;
int TipoDesenho=0;
int raio;
double eXe;
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
    if (circulo) {
		if (Button == mbLeft) {
			circulo = false;
			aux.x = xvp2mundo(X, mundo, vp);
			aux.y = yvp2mundo(Y, mundo, vp);
                        raio = StrToInt(etRaio->Text);

                        pol.circunferencia(aux, raio);

			pol.mostra(lbPontos);
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
    double dx, dy, graus;
    dx = StrToFloat(edX->Text);
    dy = StrToFloat(edY->Text);
    graus = StrToFloat(etGraus->Text);
    if (lbPoligonos->ItemIndex >= 0) {
        display.translocaDisplay(mundo,vp,dx,dy,lbPoligonos->ItemIndex,rgTipoTransformacao->ItemIndex,rgTipoTransformacao->ItemIndex);
        display.desenha(Image1->Canvas, mundo, vp, rgTipoDesenho->ItemIndex);
    }
    else
        ShowMessage("Escolha um Poligono!");
}
//---------------------------------------------------------------------------


void __fastcall TTFormPrincipal::btRotacionaClick(TObject *Sender)
{

    double graus;
    graus = StrToFloat(etGraus->Text);
    
    if (lbPoligonos->ItemIndex >= 0) {
        display.rotacionaDisplay(mundo,vp,graus,lbPoligonos->ItemIndex,rgTipoTransformacao->ItemIndex,rgTipoTransformacao->ItemIndex);
        display.desenha(Image1->Canvas, mundo, vp, rgTipoDesenho->ItemIndex);
    }
    else
        ShowMessage("Escolha um Poligono!");

}
//---------------------------------------------------------------------------

void __fastcall TTFormPrincipal::btFlexionaClick(TObject *Sender)
{
        if (lbPoligonos->ItemIndex >= 0) {
                display.poligonos[lbPoligonos->ItemIndex].reflexo();
                display.desenha(Image1->Canvas, mundo, vp, rgTipoDesenho->ItemIndex);
        }
        else
        ShowMessage("Escolha um Poligono!");
}
//---------------------------------------------------------------------------


void __fastcall TTFormPrincipal::btEscalonaClick(TObject *Sender)
{
        double dx, dy;
        dx = StrToFloat(edX->Text);
        dy = StrToFloat(edY->Text);

        if (lbPoligonos->ItemIndex >= 0) {
                display.escalonaDisplay(mundo,vp,dx,dy,lbPoligonos->ItemIndex,rgTipoTransformacao->ItemIndex,rgTipoTransformacao->ItemIndex);
                display.desenha(Image1->Canvas, mundo, vp, rgTipoDesenho->ItemIndex);
        }
        else
        ShowMessage("Escolha um Poligono!");
}
//---------------------------------------------------------------------------





void __fastcall TTFormPrincipal::rgTipoDesenhoClick(TObject *Sender)
{
   display.desenha(Image1->Canvas,mundo, vp, rgTipoDesenho->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TTFormPrincipal::btCimaClick(TObject *Sender)
{
        mundo.yMax += 10;
        mundo.yMin += 10;
        display.desenhaEixo(Image1->Canvas,mundo,vp);
}
//---------------------------------------------------------------------------

void __fastcall TTFormPrincipal::btBaixoClick(TObject *Sender)
{
        mundo.yMax -= 10;
        mundo.yMin -= 10;
        display.desenhaEixo(Image1->Canvas,mundo,vp);
}
//---------------------------------------------------------------------------

void __fastcall TTFormPrincipal::btDireitaClick(TObject *Sender)
{
        mundo.xMax += 10;
        mundo.xMin += 10;
        display.desenhaEixo(Image1->Canvas,mundo,vp);
}
//---------------------------------------------------------------------------

void __fastcall TTFormPrincipal::btEsquerdaClick(TObject *Sender)
{
        mundo.xMax -= 10;
        mundo.xMin -= 10;
        display.desenhaEixo(Image1->Canvas,mundo,vp);
}
//---------------------------------------------------------------------------

void __fastcall TTFormPrincipal::btZoomInClick(TObject *Sender)
{
        mundo.yMax -= 10;
        mundo.yMin += 10;
        mundo.xMax -= 10;
        mundo.xMin += 10;
        display.desenhaEixo(Image1->Canvas,mundo,vp);
}
//---------------------------------------------------------------------------

void __fastcall TTFormPrincipal::btZoomOutClick(TObject *Sender)
{
        mundo.yMax += 10;
        mundo.yMin -= 10;
        mundo.xMax += 10;
        mundo.xMin -= 10;
        display.desenhaEixo(Image1->Canvas,mundo,vp);        
}
//---------------------------------------------------------------------------


void __fastcall TTFormPrincipal::rgTipoTransformacaoClick(TObject *Sender)
{
rgTipoTransformacao;
}
//---------------------------------------------------------------------------


void __fastcall TTFormPrincipal::btCircunferenciaClick(TObject *Sender)
{
       circulo = true; 
}
//---------------------------------------------------------------------------

void __fastcall TTFormPrincipal::rgTipoCurvaClick(TObject *Sender)
{
rgTipoCurva;
}
//---------------------------------------------------------------------------

void __fastcall TTFormPrincipal::btCurvaClick(TObject *Sender)
{
Poligono novacurva;

if (lbPoligonos->ItemIndex >= 0){
  if (rgTipoCurva->ItemIndex == 0) {

        polaux = display.poligonos[lbPoligonos->ItemIndex];
        aux.x = polaux.pontos[0].x+1;
        aux.y = polaux.pontos[0].y+1;
        pol.pontos.push_back(aux);
        pol.casteljau(polaux.pontos[0], polaux.pontos[1], polaux.pontos[2], 0.1);

        pol.id = contId++;
        display.poligonos.push_back(pol);
        pol.pontos.clear();

        display.mostra(lbPoligonos);

        display.desenha(Image1->Canvas, mundo, vp, rgTipoDesenho->ItemIndex);

  }
  else
  {
        if (rgTipoCurva->ItemIndex == 1) {

                polaux = display.poligonos[lbPoligonos->ItemIndex];
                pol.hermite(polaux.pontos[0], polaux.pontos[1], polaux.pontos[2], polaux.pontos[3]);

                pol.id = contId++;
                display.poligonos.push_back(pol);
                pol.pontos.clear();

                display.mostra(lbPoligonos);

                display.desenha(Image1->Canvas, mundo, vp, rgTipoDesenho->ItemIndex);


        }
        else
        {
                if (rgTipoCurva->ItemIndex == 2) {
                        polaux = display.poligonos[lbPoligonos->ItemIndex];
                        pol.bezier(polaux.pontos[0], polaux.pontos[1], polaux.pontos[2], polaux.pontos[3]);

                        pol.id = contId++;
                        display.poligonos.push_back(pol);
                        pol.pontos.clear();

                        display.mostra(lbPoligonos);

                        display.desenha(Image1->Canvas, mundo, vp, rgTipoDesenho->ItemIndex);


                }
                else
                {
                        ShowMessage("Escolha um Tipo de Curva!");
                }
        }
  }

}
else
ShowMessage("Escolha um Poligono!");





}
//---------------------------------------------------------------------------


