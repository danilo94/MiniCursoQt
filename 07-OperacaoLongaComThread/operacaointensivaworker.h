#ifndef OPERACAOINTENSIVAWORKER_H
#define OPERACAOINTENSIVAWORKER_H

#include <QObject>

class OperacaoIntensivaWorker : public QObject
{
    Q_OBJECT
public:
    explicit OperacaoIntensivaWorker(QObject *parent = nullptr);

public slots:
    void executarTarefaPesada();

    void definirNumeroIteracoes(int numeroIteracoes);



private:
    void operacaoIntensiva();




signals:
    void resultadoThread(QString resultado);

private:

    int m_numeroIteracoes;
};

#endif // OPERACAOINTENSIVAWORKER_H
