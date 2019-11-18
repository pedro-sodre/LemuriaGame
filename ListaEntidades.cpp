#include "ListaEntidades.h"

ListaEntidades::ListaEntidades()
{
}

ListaEntidades::~ListaEntidades()
{
    limpaLista();
}

void ListaEntidades::limpaLista()
{
    LTEntidades.limpar();
}

void ListaEntidades::incluir(Entidade* pe)
{
    if(pe!=NULL)
        LTEntidades.incluaInfo(pe);
}

void ListaEntidades::Draw(sf::RenderWindow& window)
{
    Elemento<Entidade>* pElAux = NULL;
    Entidade* pEntAux = NULL;
    pElAux = LTEntidades.getpPrimeiro();

    while (NULL != pElAux)
    {
        pEntAux = pElAux->getInfo();
        pEntAux->Draw(window);
        pElAux = pElAux->getProximo();
    }
}

void ListaEntidades::retirar()
{
    Elemento<Entidade>* pElAux = NULL;
    Entidade* pEntAux = NULL;
    pElAux = LTEntidades.getpPrimeiro();

    Elemento<Entidade>* pElAnt = NULL;
    Elemento<Entidade>* pElPost = NULL;
    while (pElAux != NULL)
    {
        pEntAux = pElAux->getInfo();

        if(!pEntAux->getVida())
        {

            pElAnt = pElAux->getAnterior();
            printf("1\n");
            pElPost = pElAux->getProximo();
            printf("2\n");
            pElAnt->setProximo(pElPost);
            printf("3 %p\n", pElAnt);
            pElPost->setAnterior(pElAnt); //NÃO FUNCIONA NEM SETANDO COMO NULL
            printf("4\n");

            pEntAux->destruir();
            printf("5\n");

            break;
        }

        pElAux = pElAux->getProximo();
    }

}

void ListaEntidades::executar(float deltaTime)
{
    Elemento<Entidade>* pElAux = NULL;
    Entidade* pEntAux = NULL;
    pElAux = LTEntidades.getpPrimeiro();

    while (NULL != pElAux)
    {
        pEntAux = pElAux->getInfo();
        pEntAux->executar(deltaTime);
        pElAux = pElAux->getProximo();
    }
}

///TALVEZ ESSES MÉTODOS PODEM SER BOTADOS DENTRO DE LISTA.H

Entidade* ListaEntidades::percorrer()
{
    if(LTEntidades.getpPercorrimento() != NULL)
    {
        Elemento<Entidade>* pElAux = NULL;
        Entidade* pEntAux = NULL;
        pElAux = LTEntidades.getpPrimeiro();

        pEntAux = pElAux->getInfo();

        LTEntidades.setpPercorrimento(LTEntidades.getpPercorrimento()->getProximo());

        return pEntAux;
    }

    else
        return NULL;
}

Entidade* ListaEntidades::reiniciar()
{
    LTEntidades.setpPercorrimento(LTEntidades.getpPrimeiro());
    return LTEntidades.getpPrimeiro()->getInfo();
}

void ListaEntidades::gravarJogo1()
{
    ofstream Gravador("data/Fase1Gravando.txt", ios::out);

    if ( !Gravador )
    {
        cerr << "Arquivo não pode ser aberto" << endl;
        fflush ( stdin );
        getchar ( );
        return;
    }

    Elemento<Entidade>* pElAux = NULL;
    Entidade* pEntAux = NULL;
    pElAux = LTEntidades.getpPrimeiro();

    while (NULL != pElAux)
    {
        pEntAux = pElAux->getInfo();

        Gravador    << pEntAux->getID() << " "
                    << pEntAux->getX() << " "
                    << pEntAux->getY() << endl;

        pElAux = pElAux->getProximo();
    }

    Gravador.close();
}

void ListaEntidades::gravarJogo2()
{
    ofstream Gravador("data/Fase2Gravando.txt", ios::out);

    if ( !Gravador )
    {
        cerr << "Arquivo não pode ser aberto" << endl;
        fflush ( stdin );
        getchar ( );
        return;
    }

    Elemento<Entidade>* pElAux = NULL;
    Entidade* pEntAux = NULL;
    pElAux = LTEntidades.getpPrimeiro();

    while (NULL != pElAux)
    {
        pEntAux = pElAux->getInfo();

        Gravador    << pEntAux->getID() << " "
                    << pEntAux->getX() << " "
                    << pEntAux->getY() << endl;

        pElAux = pElAux->getProximo();
    }

    Gravador.close();
}

void ListaEntidades::gravarJogo3()
{
    ofstream Gravador("data/Fase3Gravando.txt", ios::out);

    if ( !Gravador )
    {
        cerr << "Arquivo não pode ser aberto" << endl;
        fflush ( stdin );
        getchar ( );
        return;
    }

    Elemento<Entidade>* pElAux = NULL;
    Entidade* pEntAux = NULL;
    pElAux = LTEntidades.getpPrimeiro();

    while (NULL != pElAux)
    {
        pEntAux = pElAux->getInfo();

        Gravador    << pEntAux->getID() << " "
                    << pEntAux->getX() << " "
                    << pEntAux->getY() << endl;

        pElAux = pElAux->getProximo();
    }

    Gravador.close();
}
