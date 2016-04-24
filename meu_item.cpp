
#include "meu_item.h"


Meu_Item::Meu_Item()
{
    this->cont = 0;
    this->pilha = new Pilha();

    this->Pressionado = false;
    this->Ligado = true;
    setFlag(ItemIsMovable);
}

QRectF Meu_Item::limitadorPagina() const
{
    // outer most edges
    return QRectF(this->x1, this->y1, this->x2, this->y2);
}

void Meu_Item::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressionado =true;
    QGraphicsItem::mousePressEvent(event);
    update();
}

void Meu_Item::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressionado =false;
    QGraphicsItem::mouseReleaseEvent(event);
    update();
}

void Meu_Item::paint(QPainter *Desenho
                     , const QStyleOptionGraphicsItem *Opcao
                     , QWidget *widget)
{
//    Pilha * p = new Pilha();
//    p->Push_back_Org(10, string("Zen"));
//    p->Push_back_Org(20, string("Zen"));
//    p->Push_back_Org(30, string("Zen"));
//    No_Print(Desenho, p);

    No_Print(Desenho, this->pilha);
    update();
}

void Meu_Item::desenha_flecha(QPainter *Desenho, const int coord_X, const int coord_Y, int pont, int cabo)
{
    int tam = pont;
    //Organiza poligono
    QPolygon seta;
    seta << QPoint(coord_X -tam, coord_Y);
    seta << QPoint(coord_X -tam, coord_Y + tam);
    seta << QPoint(coord_X, coord_Y + tam/2);
    //Caneta
    Desenho->setPen(QPen(Qt::black, 4));
    //estampas
    QBrush esta(Qt::red, Qt::SolidPattern);
    //agulha..
    QPainterPath agulha;
    agulha.addPolygon(seta);
    //Cabo da flecha
    Desenho->drawLine( cabo, (coord_Y + tam/2), (coord_X - tam), (coord_Y + tam/2) );
    //Desenha e costuro estampa..
    Desenho->drawPolygon(seta);
    Desenho->fillPath(agulha, esta);
}

void Meu_Item::setPilha(Pilha *pilha)
{
    this->pilha = pilha;
}

void Meu_Item::No_Print(QPainter *Desenho, Pilha *pilha)
{
    QRectF rect = limitadorPagina();
    int X_Final = this->x2 ;
    int Novo_x1 = this->x1;
    int     largura_no = (this->x2 - this->x1);
    int distancia = 30;
    int quantidade_Nos;

    if(!Ligado)
    {
        Desenho-> eraseRect(this->x1, this->y1, X_Final, this->y2); //aqui só apaga nessas margens..
        update();
    }
    else
    {
        if(pilha->getHeader()->getNext() != pilha->getTrailer() ){

            Nol * ponteiro = pilha->getHeader()->getNext();

            int temp_x;

            QString Idade;
            QString Nomes;

            Nol * trailer = pilha->getTrailer();
            int ajuste_flecha = 2;
            while(ponteiro != trailer ){
                Idade = converter_Int_ToQstring(ponteiro->getIdade());
                Nomes = converter_StringToQstring(ponteiro->getNomes());

                //Estilo caneta
                QPen pen(Qt::black, 3);
                Desenho->setPen(pen);
                //Desenha quadrado
                Desenho->drawRect(Novo_x1,0,X_Final,60);
                //Escreve
                Desenho->setFont(QFont("Arial", 18));
                Desenho->drawText(Novo_x1,0,X_Final,60, Qt::AlignHCenter, Idade);
                Desenho->setFont(QFont("Arial", 13));
                Desenho->drawText(Novo_x1,0,X_Final,60, Qt::AlignCenter, "\n" + Nomes);

                //Define as cordenadas do proximo no e da Seta.
                ponteiro = ponteiro->getNext();
                    Novo_x1 = Novo_x1 + largura_no + distancia;
                    quantidade_Nos++;
                    temp_x = Novo_x1 - distancia;   
                if(ponteiro != trailer) {
                    //Ajuste é para a seta não invadir uma caixa
                    desenha_flecha(Desenho, Novo_x1, (this->y2)/2, 8, Novo_x1 - distancia +ajuste_flecha);
                }
                update();
            }
            X_Final = (Novo_x1 + largura_no + distancia) *quantidade_Nos;

        }

    }
}

