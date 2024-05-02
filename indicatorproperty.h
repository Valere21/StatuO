#ifndef INDICATORPROPERTY_H
#define INDICATORPROPERTY_H

#include <QObject>

#include "processcsv.h"
#include "enum.h"

class Operator;
class IndicatorProperty : public ProcessCsv
{
    Q_OBJECT

public:

    IndicatorProperty();
    IndicatorProperty(Enum::FileType fileType, Enum::Filter filter, Enum::Spec spec, Enum::Operation operation);
//    ~IndicatorProperty();

    IndicatorProperty* getProperty();
    void setFileInfo(Enum::FileType file);
    void setFilterInfo(Enum::Filter filter);
    void setSpecInfo(Enum::Spec spec);
    void computeIndicator(Enum::Operation operation);

    QFile file() const;

    QString roadColumn() const;

    QString filterColumn() const;

    QStringList filter() const;

    QString road() const;

    QStringList listRoad() const;

protected:

    Operator *m_operation = nullptr;

    QStringList m_listRoad;

    QFile m_file;
    QString m_roadColumn;
    QString m_filterColumn;

    QStringList m_filter;
    QStringList m_spec;


    QString m_road;
};

#endif // INDICATORPROPERTY_H
