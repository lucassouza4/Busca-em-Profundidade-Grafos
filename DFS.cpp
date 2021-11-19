#include <iostream>
#include <algorithm>
#include "DFS.hpp"
using namespace std;

Vertice::Vertice(int i)
{
    indice = i;
    visitado = false;
}
void Vertice::addAresta(Vertice *destino)
{
    arestas.push_back(destino);
}

Grafo::Grafo(int n)
{
    qnt = n;
}

void Grafo::add(int origem, int destino, int direcionado)
{
    Vertice *auxOri = criarVertices(origem);
    Vertice *auxDest = criarVertices(destino);
    if (direcionado == 0)
    {
        auxOri->addAresta(auxDest);
        auxDest->addAresta(auxOri);
    }
    else
        auxOri->addAresta(auxDest);
}

Vertice *Grafo::criarVertices(int indice)
{
    for (auto it = vertices.begin(); it != vertices.end(); it++)
    {
        if ((*it)->indice == indice)
        {
            return (*it);
        }
    }

    Vertice* v = new Vertice(indice);
    vertices.push_back(v);
    return ((*(vertices.end()-1)));
}

void Grafo::DFS(int inicio, vector<Vertice*> *verticesVisitados)
{
    (*verticesVisitados).push_back((criarVertices(inicio)));
    (*verticesVisitados).back()->visitado=true;

    Vertice* aux = (*verticesVisitados).back();

    for(auto it = aux->arestas.begin(); it != aux->arestas.end(); it++){ 
        if((*it)->visitado == false){
            DFS((*it)->indice,verticesVisitados);
        }        
    }
}

void Grafo::printVisit(vector<Vertice*> *verticesVisitados)
{
    for (Vertice *v : (*verticesVisitados))
    {
        cout << v->indice << endl;
    }
}

