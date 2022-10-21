#include "objeto.h"

#include <qDebug>

Objeto::Objeto(int numeroObjeto)
{
 m_valor = numeroObjeto;
}

Objeto::~Objeto()
{
    qDebug() << "Objeto Destruido" << m_valor;
}
