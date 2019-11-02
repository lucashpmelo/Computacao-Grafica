//---------------------------------------------------------------------------

#ifndef uPrincipalH
#define uPrincipalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TTFormPrincipal : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TImage *Image1;
    TLabel *Label1;
    TLabel *Label2;
    TListBox *lbPontos;
        TButton *btNovo;
    TListBox *lbPoligonos;
    TEdit *edX;
    TEdit *edY;
    TLabel *Label3;
    TLabel *Label4;
        TButton *btTranslacao;
        TButton *btRotaciona;
        TEdit *etGraus;
        TLabel *Label5;
        TButton *btFlexionaX;
        TButton *btEscalona;
        TRadioGroup *rgTipoDesenho;
        TButton *btCima;
        TButton *btBaixo;
        TButton *btDireita;
        TButton *btEsquerda;
        TButton *btZoomIn;
        TButton *btZoomOut;
        TRadioGroup *rgTipoTransformacao;
        TEdit *etRaio;
        TButton *btCircunferencia;
        TLabel *Label6;
        TButton *btCurva;
        TRadioGroup *rgTipoCurva;
        TButton *btFlexionaY;
        TButton *btClipping;
    void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
        int X, int Y);
    void __fastcall Image1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall btNovoClick(TObject *Sender);
    void __fastcall lbPoligonosClick(TObject *Sender);
    void __fastcall btTranslacaoClick(TObject *Sender);
        void __fastcall btRotacionaClick(TObject *Sender);
        void __fastcall btFlexionaXClick(TObject *Sender);
        void __fastcall btEscalonaClick(TObject *Sender);
        void __fastcall rgTipoDesenhoClick(TObject *Sender);
        void __fastcall btCimaClick(TObject *Sender);
        void __fastcall btBaixoClick(TObject *Sender);
        void __fastcall btDireitaClick(TObject *Sender);
        void __fastcall btEsquerdaClick(TObject *Sender);
        void __fastcall btZoomInClick(TObject *Sender);
        void __fastcall btZoomOutClick(TObject *Sender);
        void __fastcall rgTipoTransformacaoClick(TObject *Sender);
        void __fastcall btCircunferenciaClick(TObject *Sender);
        void __fastcall btCurvaClick(TObject *Sender);
        void __fastcall rgTipoCurvaClick(TObject *Sender);
        void __fastcall btFlexionaYClick(TObject *Sender);
        void __fastcall btClippingClick(TObject *Sender);
private:	// User declarations
public:		// User declarations

    __fastcall TTFormPrincipal(TComponent* Owner);

    double xvp2mundo(int x, Janela mundo, Janela vp);
    double yvp2mundo (int y, Janela mundo, Janela vp);


};
//---------------------------------------------------------------------------
extern PACKAGE TTFormPrincipal *TFormPrincipal;
//---------------------------------------------------------------------------
#endif
 