#include "operacaointensivaworker.h"

#include <QElapsedTimer>

OperacaoIntensivaWorker::OperacaoIntensivaWorker(QObject *parent)
    : QObject{parent}
{
    m_numeroIteracoes = 1000;
}

void OperacaoIntensivaWorker::executarTarefaPesada()
{
    QElapsedTimer timer;
    timer.start();
    operacaoIntensiva();
    QString resultado = QString("Operação Finalizada, tempo gasto: %1 millisegundos").arg(timer.elapsed());
    emit resultadoThread(resultado);
}

void OperacaoIntensivaWorker::definirNumeroIteracoes(int numeroIteracoes)
{
    m_numeroIteracoes = numeroIteracoes;
}

void OperacaoIntensivaWorker::operacaoIntensiva()
{
    int numeroIteracoes = m_numeroIteracoes;
    int result=0;
    for (int i=0; i<= numeroIteracoes; i++){
        for (int j=0; j <= numeroIteracoes; j++){
            for (int k=0; k<=numeroIteracoes; k++){
                result += i + j + k;
            }
        }
    }
}
