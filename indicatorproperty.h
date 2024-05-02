#ifndef INDICATORPROPERTY_H
#define INDICATORPROPERTY_H

#include <QObject>

#include "processcsv.h"
#include "enum.h"

// class ProcessCsv : public QObject{};

class IndicatorProperty : public ProcessCsv
{
    Q_OBJECT

public:
    IndicatorProperty();
    IndicatorProperty(Enum::FileType file, Enum::Filter filter, Enum::Spec spec);

private :
    QString m_file;
    QStringList m_listRoad;
};

#endif // INDICATORPROPERTY_H
