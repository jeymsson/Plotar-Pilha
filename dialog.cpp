#include "dialog.h"
#include "ui_dialog.h"






Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->pilha = new Pilha(); //Cria pilha.

        //Cria cenario e adiciona ao "grafico".
        Cenario = new QGraphicsScene(this);
        ui->graphicsView->setScene(Cenario);
        //Adiciona a figura "Item" ao cenário.
        Item = new Meu_Item();
        Cenario->addItem(Item);
    //Aplica Máscara aos compos de edição.
    //ui->editaIdade->setInputMask("999"); //Permite digitar de 0-100.


}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_botaoOk_clicked()
{//Liga desliga
    this->Item->Ligado = (Item->Ligado ? false : true);

    ui->label->setText((this->Item->Ligado ? "Ligado" : "Desligado") );

    int i;
    QString s = ui->editaIdade->text();
    i = s.toInt();

    //ui->label->setText(s);
}

void Dialog::on_botaoInserir_clicked()
{
    QString QIdade = ui->editaIdade->text();
    QString QNome = ui->editaNome->text();
    int        iIdade = converter_QstringToInt(QIdade);
    std::string sNome = converter_QstringToString(QNome);

    if(QIdade.isEmpty()){
        QMessageBox::information(this, tr("Atenção."), tr("Nao tem idade digitada."));
    } else if(QNome.isEmpty()){
        QMessageBox::information(this, tr("Atenção."), tr("Nao tem nome digitado."));
    } else {
        this->pilha->Push_back_Org(iIdade, std::string(sNome) );
        qDebug() << converter_StringToQstring(this->pilha->Print());
        this->Item->setPilha(this->pilha);
    }
}

#include <QDebug>
void Dialog::on_botaoRemover_clicked(bool checked){
    qDebug() << ("Clicou");
}
