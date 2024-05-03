#ifndef Operator_H
#define Operator_H

#include <QObject>

#include "enum.h"
#include "indicatorproperty.h"

class Operator : public IndicatorProperty
{
    Q_OBJECT
public:

    Operator();
    Operator(IndicatorProperty* indicator, Enum::Operation operation);

    void count();
    void countFilter();
    void countSpec();
    void countFilterSpec();
    void countSpecUnique();

    void countPeakAM();
    void countOffPeak();
    void countPeakPM();

    void sum();
    void sumFilterSpec();
    void sumSpec();


    QList<QPair<QString, int>>getResult();
private:

    IndicatorProperty *m_indicator = nullptr;
    Enum::Operation m_operator;
    QList<QPair<QString, int>> m_listResult;
};

#endif // Operator_H
