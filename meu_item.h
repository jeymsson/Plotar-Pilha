#ifndef MEU_ITEM_H
#define MEU_ITEM_H

#include <QPainter>
#include <QGraphicsItem>
#include <QString>

#include "pilha.h"
#include "funcoes.h" //Para exibir os dados do no nas figuras


class Meu_Item :public QGraphicsItem  // class for customization
{
public:
    Meu_Item();

    QRectF limitadorPagina() const;

    // overriding paint()
    void paint(QPainter * Desenho
               , const QStyleOptionGraphicsItem * Opcao
               , QWidget * widget);

    // item state
    int cont;
    bool Ligado;
    bool Pressionado;
    void setPilha(Pilha * pilha);

private:
    Pilha * pilha;

    int x1 = 0;
    int y1 = 0;
    int x2 = 100;
    int y2 = 60;

    void atualizaTudo();

protected:
    // overriding mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
void No_Print(QPainter *Desenho, Pilha *pilha);
void desenha_flecha(QPainter *Desenho, const int coord_X, const int coord_Y, int seta, int cabo);

};

#endif // MEU_ITEM_H
