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
    TLabel *Label1;
    TLabel *Label2;
    TListBox *lbPontos;
    TButton *Button1;
        TButton *btNovo;
    TListBox *lbPoligonos;
        TRadioGroup *rgTipoDesenho;
        TImage *Image1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        TButton *Button7;
    void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
        int X, int Y);
    void __fastcall Image1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall btNovoClick(TObject *Sender);
    void __fastcall lbPoligonosClick(TObject *Sender);
    void __fastcall btTranslacaoClick(TObject *Sender);
        void __fastcall btRotacionaClick(TObject *Sender);
        void __fastcall btFlexionaClick(TObject *Sender);
        void __fastcall btEscalonaClick(TObject *Sender);
        void __fastcall rgTipoDesenhoClick(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
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
 