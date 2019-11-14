#include "GerenciadorDeColisoes.h"

GerenciadorDeColisoes::GerenciadorDeColisoes(Player* p1, ListaPlataformas* lp, ListaObstaculos* lo, ListaInimigos* li, ListaEntidades* le, ListaProjeteis* lproj)
{
    player1         = p1;
    Lplataformas    = lp;
    Lobstaculos     = lo;
    Linimigos       = li;
    Lentidades      = le;
    Lprojeteis      = lproj;
    direction       = sf::Vector2f(0.0f, 0.0f);
}

GerenciadorDeColisoes::~GerenciadorDeColisoes()
{
    player1         = NULL;
    Lobstaculos     = NULL;
    Lplataformas    = NULL;
    Linimigos       = NULL;
    Lentidades      = NULL;
    Lprojeteis      = NULL;
}

void GerenciadorDeColisoes::executar()
{
    int i, j;/*
    ///GERECIAR COLISÕES DOS OBSTACULOS/INIMIGOS COM AS PAREDES

    //COLISÃO COM AS PAREDES
    if(player1->getBody()->getPosition().x < player1->getBody()->getSize().x/2)
        player1->getBody()->setPosition(player1->getBody()->getSize().x/2, player1->getBody()->getPosition().y);
    if(player1->getBody()->getPosition().x > 6100 - player1->getBody()->getSize().x/2)
        player1->getBody()->setPosition(6100 - player1->getBody()->getSize().x/2, player1->getBody()->getPosition().y);
    //COLISÃO COM O TETO
    if(player1->getBody()->getPosition().y < -250)
        player1->getBody()->setPosition(player1->getBody()->getPosition().x, -250);
*/



    ///COLISÕES COM AS PLATAFORMAS
    //PLAYER
    for(aux = Lplataformas->reiniciar(); aux != NULL; aux = Lplataformas->percorrer())
        if(aux->getCollider().CheckCollision(player1->getCollider(), direction, 1.0f))
            player1->onCollision(direction);
    //OBSTÁCULOS
    for(aux = Lplataformas->reiniciar(); aux != NULL; aux = Lplataformas->percorrer())
        for(i=0; i < Lobstaculos->getLTObstaculos().size(); i++)
            if(aux->getCollider().CheckCollision(Lobstaculos->getLTObstaculos()[i]->getCollider(), direction, 1.0f))
                Lobstaculos->getLTObstaculos()[i]->onCollision(direction);
    //INIMIGOS
    for(aux = Lplataformas->reiniciar(); aux != NULL; aux = Lplataformas->percorrer())
        for(i=0; i < Linimigos->getLTInimigos().size(); i++)
            if(aux->getCollider().CheckCollision(Linimigos->getLTInimigos()[i]->getCollider(), direction, 1.0f))
                Linimigos->getLTInimigos()[i]->onCollision(direction);



    ///COLISÕES COM OBSTÁCULOS
    for(i=0; i < Lobstaculos->getLTObstaculos().size(); i++)
        if(Lobstaculos->getLTObstaculos()[i]->getCollider().CheckCollision(player1->getCollider(), direction, 0.5f))      ///PESO??
            player1->onCollision(direction);



    ///COLISÕES ENTRE OBSTÁCULOS
    for(i=0; i < Lobstaculos->getLTObstaculos().size(); i++)
        for(j=0; j < Lobstaculos->getLTObstaculos().size(); j++)
            if(i != j)
                if(Lobstaculos->getLTObstaculos()[i]->getCollider().CheckCollision(Lobstaculos->getLTObstaculos()[j]->getCollider(), direction, 0.5f))  ///PESO??
                    Lobstaculos->getLTObstaculos()[j]->onCollision(direction);



    ///COLISÕES COM INIMIGOS
    for(i=0; i < Linimigos->getLTInimigos().size(); i++)
        if(Linimigos->getLTInimigos()[i]->getCollider().CheckCollision(player1->getCollider(), direction, 0.97f))
        {
            if(player1->isAtacking())
            {
                Linimigos->getLTInimigos()[i]->setVida(0);
                Linimigos->retirar(i);
                Lentidades->retirar();
                player1->ranking = player1->ranking+10;
                printf("Ranking: %d \n", player1->ranking);
            }
            else
            {
                player1->knockback(direction);
                player1->setVida(player1->getVida()-1);
                printf("VIDA: %d\n", player1->getVida());

            }
        }

    ///COLISÕES COM PROJETEIS
    for(i=0; i < Lprojeteis->getLTProjeteis().size(); i++)
        if(Lprojeteis->getLTProjeteis()[i]->getCollider().CheckCollision(player1->getCollider(), direction, 0.97f))
        {
            Lprojeteis->getLTProjeteis()[i]->setVida(0);
            player1->knockback(direction);
            player1->setVida(player1->getVida()-1);
            printf("VIDA: %d\n", player1->getVida());
            Lprojeteis->retirar(i);

            Lentidades->retirar();
        }


    ///COLISÕES ENTRE INIMIGOS
    for(i=0; i < Linimigos->getLTInimigos().size(); i++)
        for(j=0; j < Linimigos->getLTInimigos().size(); j++)
            if(i != j)
                if(Linimigos->getLTInimigos()[i]->getCollider().CheckCollision(Linimigos->getLTInimigos()[j]->getCollider(), direction, 1.0f))  ///PESO??
                    Linimigos->getLTInimigos()[j]->onCollision(direction);


    ///COLISÕES ENTRE OBSTÁCULOS E INIMIGOS
    for(i=0; i < Linimigos->getLTInimigos().size(); i++)
        for(j=0; j < Lobstaculos->getLTObstaculos().size(); j++)
            if(Linimigos->getLTInimigos()[i]->getCollider().CheckCollision(Lobstaculos->getLTObstaculos()[j]->getCollider(), direction, 0.3f))  ///PESO??
                    Lobstaculos->getLTObstaculos()[j]->onCollision(direction);
}
