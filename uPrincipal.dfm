object TFormPrincipal: TTFormPrincipal
  Left = 391
  Top = 23
  Width = 948
  Height = 739
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
    Top = 168
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
    Top = 168
    Width = 137
    Height = 193
    ItemHeight = 13
    TabOrder = 4
    OnClick = lbPoligonosClick
  end
  object rgTipoDesenho: TRadioGroup
    Left = 544
    Top = 64
    Width = 137
    Height = 89
    Caption = 'M'#233'todo de Desenho'
    ItemIndex = 0
    Items.Strings = (
      'DrawLine'
      'DDA'
      'Bresenham')
    TabOrder = 5
    OnClick = rgTipoDesenhoClick
  end
  object Button2: TButton
    Left = 608
    Top = 392
    Width = 75
    Height = 25
    Caption = 'Cima'
    TabOrder = 6
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 608
    Top = 456
    Width = 75
    Height = 25
    Caption = 'Baixo'
    TabOrder = 7
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 536
    Top = 424
    Width = 75
    Height = 25
    Caption = 'Esquerda'
    TabOrder = 8
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 680
    Top = 424
    Width = 75
    Height = 25
    Caption = 'Direita'
    TabOrder = 9
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 816
    Top = 400
    Width = 75
    Height = 25
    Caption = 'Zoom +'
    TabOrder = 10
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 816
    Top = 448
    Width = 75
    Height = 25
    Caption = 'Zoom -'
    TabOrder = 11
    OnClick = Button7Click
  end
end
