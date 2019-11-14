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
            pElAnt->setProximo(pElAux->getProximo());
            pElPost = pElAux->getProximo();
            pElPost->setAnterior((pElAux->getAnterior()));

            pEntAux->destruir();

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

///TALVEZ ESSES M�TODOS PODEM SER BOTADOS DENTRO DE LISTA.H

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

void ListaEntidades::gravarJogo()
{
    ofstream Gravador("data/Fase1Gravando.txt", ios::out);

    if ( !Gravador )
    {
        cerr << "Arquivo n�o pode ser aberto" << endl;
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
