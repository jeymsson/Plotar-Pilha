#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGraphicsScene>

#include <QString>
#include <QMessageBox>
#include <QPainter>
#include <QDebug>

#include "meu_item.h"
#include "pilha.h"
#include "funcoes.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_botaoOk_clicked();

    void on_botaoInserir_clicked();


    void on_botaoRemover_clicked(bool checked);

private:
    Pilha * pilha;

    Ui::Dialog *ui;
    QGraphicsScene *Cenario;
    Meu_Item *Item;


};

#endif // DIALOG_H
