#include "Neuronas.h"
#include "qdebug.h"
#include <fstream>
#include <string>
#include <QString>

Neuronas *Neu=new Neuronas();
Neuronas::Neuronas()
{
    h=nullptr;
}

void Neuronas::insertarinicio(int id,double voltaje,int px,int py, int red,int green, int blue)
{
    Neurona *aux=new Neurona(id,voltaje,px,py,red,green,blue,nullptr);

    if(!h)
    {
        h=aux;
    }
    else
    {
        aux->sig=h;
        h=aux;
    }
}

void Neuronas::insertarfinal(int id,double voltaje,int px,int py,int red,int green,int blue)
{
    Neurona *aux=new Neurona(id,voltaje,px,py,red,green,blue,nullptr);
    Neurona *tmp;

    if(h==nullptr)
    {
        h=aux;
    }
    else
    {
        tmp=h;
        while(tmp->sig!=nullptr)
        {
            tmp=tmp->sig;
        }
        tmp->sig=aux;
        tmp=tmp->sig;
        tmp->sig=nullptr;
    }
}


void Neuronas::mostrar(int& i,double& v,int& px,int& py,int& r,int& g,int& b,int n)
{
    int x=0;
    Neurona *tmp=h;
    while(n>x)
    {
        i=tmp->id;
        v=tmp->voltaje;
        px=tmp->px;
        py=tmp->py;
        r=tmp->red;
        g=tmp->green;
        b=tmp->blue;
        tmp=tmp->sig;
        x=x+1;
    }
}

void Neuronas::buscar(int idbuscar,int& i,double& v,int& px,int& py,int& r,int& g,int& b)
{
    Neurona *tmp=h;
    i=-1;
    while(tmp!=nullptr)
    {
        if(idbuscar==tmp->id)
        {
            i=tmp->id;
            v=tmp->voltaje;
            px=tmp->px;
            py=tmp->py;
            r=tmp->red;
            g=tmp->green;
            b=tmp->blue;
        }
            tmp=tmp->sig;
    }
}

void Neuronas::ordenarID(int n)
{
    Neurona *tmp,*aux;
    int x=1,i,o,p,r,g,b;
    double v;

    while(n-1>x)
    {
        tmp=h;
            aux=tmp->sig;
        while(n-1>x)
        {
            if(tmp->id>aux->id)
            {
                i=aux->id;
                v=aux->voltaje;
                o=aux->px;
                p=aux->py;
                r=aux->red;
                g=aux->green;
                b=aux->blue;

                qInfo() << i << v << o << p << r << g << b;

                aux->id=tmp->id;
                aux->voltaje=tmp->voltaje;
                aux->px=tmp->px;
                aux->py=tmp->py;
                aux->red=tmp->red;
                aux->green=tmp->green;
                aux->blue=tmp->blue;

                qInfo() << aux->id << aux->voltaje << aux->px << aux->py << aux->red << aux->green << aux->blue;

                tmp->id=i;
                tmp->voltaje=v;
                tmp->px=o;
                tmp->py=p;
                tmp->red=r;
                tmp->green=g;
                tmp->blue=b;

                qInfo() << tmp->id << tmp->voltaje << tmp->px << tmp->py << tmp->red << tmp->green << tmp->blue;

            }
            tmp=aux;
            aux=aux->sig;
            x=x+1;
        }
        x=1;
        n=n-1;
    }
}

void Neuronas::ordenarV(int n)
{
    Neurona *tmp,*aux;
    int x=1,i,o,p,r,g,b;
    double v;

    while(n-1>x)
    {
        tmp=h;
        aux=tmp->sig;
        while(n-1>x)
        {
            if(tmp->voltaje>aux->voltaje)
            {
                i=aux->id;
                v=aux->voltaje;
                o=aux->px;
                p=aux->py;
                r=aux->red;
                g=aux->green;
                b=aux->blue;

                qInfo() << i << v << o << p << r << g << b;

                aux->id=tmp->id;
                aux->voltaje=tmp->voltaje;
                aux->px=tmp->px;
                aux->py=tmp->py;
                aux->red=tmp->red;
                aux->green=tmp->green;
                aux->blue=tmp->blue;

                qInfo() << aux->id << aux->voltaje << aux->px << aux->py << aux->red << aux->green << aux->blue;

                tmp->id=i;
                tmp->voltaje=v;
                tmp->px=o;
                tmp->py=p;
                tmp->red=r;
                tmp->green=g;
                tmp->blue=b;

                qInfo() << tmp->id << tmp->voltaje << tmp->px << tmp->py << tmp->red << tmp->green << tmp->blue;

            }
            tmp=aux;
            aux=aux->sig;
            x=x+1;
        }
        x=1;
        n=n-1;
    }
}
