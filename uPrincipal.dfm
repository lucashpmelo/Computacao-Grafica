object TFormPrincipal: TTFormPrincipal
  Left = 272
  Top = 10
  Width = 951
  Height = 743
  Caption = '1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 560
    Top = 16
    Width = 32
    Height = 13
    Caption = 'Label1'
  end
  object Label2: TLabel
    Left = 560
    Top = 40
    Width = 32
    Height = 13
    Caption = 'Label2'
  end
  object Label3: TLabel
    Left = 24
    Top = 528
    Width = 7
    Height = 13
    Caption = 'X'
  end
  object Label4: TLabel
    Left = 24
    Top = 560
    Width = 7
    Height = 13
    Caption = 'Y'
  end
  object Label5: TLabel
    Left = 128
    Top = 532
    Width = 28
    Height = 13
    Caption = 'Graus'
  end
  object Label6: TLabel
    Left = 128
    Top = 560
    Width = 22
    Height = 13
    Caption = 'Raio'
  end
  object Panel1: TPanel
    Left = 24
    Top = 16
    Width = 502
    Height = 502
    TabOrder = 0
    object Image1: TImage
      Left = 1
      Top = 1
      Width = 500
      Height = 500
      Align = alClient
      OnMouseDown = Image1MouseDown
      OnMouseMove = Image1MouseMove
    end
  end
  object lbPontos: TListBox
    Left = 704
    Top = 184
    Width = 137
    Height = 193
    ItemHeight = 13
    TabOrder = 1
  end
  object Button1: TButton
    Left = 704
    Top = 64
    Width = 137
    Height = 33
    Caption = 'Tra'#231'ar pts'
    TabOrder = 2
    OnClick = Button1Click
  end
  object btNovo: TButton
    Left = 704
    Top = 112
    Width = 137
    Height = 33
    Caption = 'novo'
    TabOrder = 3
    OnClick = btNovoClick
  end
  object lbPoligonos: TListBox
    Left = 544
    Top = 184
    Width = 137
    Height = 193
    ItemHeight = 13
    TabOrder = 4
    OnClick = lbPoligonosClick
  end
  object edX: TEdit
    Left = 40
    Top = 528
    Width = 65
    Height = 21
    TabOrder = 5
    Text = '0'
  end
  object edY: TEdit
    Left = 40
    Top = 560
    Width = 65
    Height = 21
    TabOrder = 6
    Text = '0'
  end
  object btTranslacao: TButton
    Left = 16
    Top = 608
    Width = 99
    Height = 25
    Caption = 'Transla'#231#227'o'
    TabOrder = 7
    OnClick = btTranslacaoClick
  end
  object btRotaciona: TButton
    Left = 128
    Top = 608
    Width = 99
    Height = 25
    Caption = 'Rotaciona'
    TabOrder = 8
    OnClick = btRotacionaClick
  end
  object etGraus: TEdit
    Left = 160
    Top = 528
    Width = 65
    Height = 21
    TabOrder = 9
    Text = '0'
  end
  object btFlexiona: TButton
    Left = 128
    Top = 648
    Width = 97
    Height = 25
    Caption = 'Flexiona'
    TabOrder = 10
    OnClick = btFlexionaClick
  end
  object btEscalona: TButton
    Left = 16
    Top = 648
    Width = 97
    Height = 25
    Caption = 'Escalona'
    TabOrder = 11
    OnClick = btEscalonaClick
  end
  object rgTipoDesenho: TRadioGroup
    Left = 544
    Top = 64
    Width = 137
    Height = 105
    Caption = 'M'#233'todo de Desenho'
    ItemIndex = 0
    Items.Strings = (
      'DrawLine'
      'DDA'
      'Bresenham')
    TabOrder = 12
    OnClick = rgTipoDesenhoClick
  end
  object btCima: TButton
    Left = 608
    Top = 392
    Width = 75
    Height = 25
    Caption = 'Cima'
    TabOrder = 13
    OnClick = btCimaClick
  end
  object btBaixo: TButton
    Left = 608
    Top = 456
    Width = 75
    Height = 25
    Caption = 'Baixo'
    TabOrder = 14
    OnClick = btBaixoClick
  end
  object btDireita: TButton
    Left = 688
    Top = 424
    Width = 75
    Height = 25
    Caption = 'Direita'
    TabOrder = 15
    OnClick = btDireitaClick
  end
  object btEsquerda: TButton
    Left = 528
    Top = 424
    Width = 75
    Height = 25
    Caption = 'Esquerda'
    TabOrder = 16
    OnClick = btEsquerdaClick
  end
  object btZoomIn: TButton
    Left = 784
    Top = 400
    Width = 75
    Height = 25
    Caption = 'Zoom +'
    TabOrder = 17
    OnClick = btZoomInClick
  end
  object btZoomOut: TButton
    Left = 784
    Top = 448
    Width = 75
    Height = 25
    Caption = 'Zoom -'
    TabOrder = 18
    OnClick = btZoomOutClick
  end
  object rgTipoTransformacao: TRadioGroup
    Left = 240
    Top = 520
    Width = 185
    Height = 73
    Caption = 'Transforma'#231#227'o'
    ItemIndex = 0
    Items.Strings = (
      'Normal'
      'Homogenea')
    TabOrder = 19
    OnClick = rgTipoTransformacaoClick
  end
  object etRaio: TEdit
    Left = 160
    Top = 560
    Width = 65
    Height = 21
    TabOrder = 20
    Text = '0'
  end
  object btCircunferencia: TButton
    Left = 240
    Top = 608
    Width = 97
    Height = 25
    Caption = 'Circunferencia'
    TabOrder = 21
    OnClick = btCircunferenciaClick
  end
end
