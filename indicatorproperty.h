#ifndef INDICATORPROPERTY_H
#define INDICATORPROPERTY_H

#include <QObject>

#include "processcsv.h"
#include "enum.h"
#include "processcsv.h"

class Operator;
class IndicatorProperty : public QObject
{
    Q_OBJECT

public:

    IndicatorProperty();
    IndicatorProperty(ProcessCsv *process, Enum::FileType fileType, Enum::Filter filter, Enum::Spec spec, Enum::Operation operation);
//    ~IndicatorProperty();

    IndicatorProperty* getProperty();
    void setFileInfo(Enum::FileType file);
    void setFilterInfo(Enum::Filter filter);
    void setSpecInfo(Enum::Spec spec);
    void computeIndicator(Enum::Operation operation);

    QString file() const;

    QString roadColumn() const;

    QString filterColumn() const;

    QStringList filter() const;

    QString road() const;

    QStringList listRoad() const;

    QList<QPair<QString, int> > listResult() const;
    void setListResult(const QList<QPair<QString, int> > &newListResult);

protected:

    ProcessCsv *process;

    Operator *m_operator = nullptr;
    QList<QPair<QString, int>> m_listResult;

    QStringList m_listRoad;

    QString m_file;
    QString m_roadColumn;
    QString m_filterColumn;

    QStringList m_filter;
    QStringList m_spec;


    QString m_road;
};

#endif // INDICATORPROPERTY_H
