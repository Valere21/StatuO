#include "Operator.h"
#include "indicatorproperty.h"

IndicatorProperty::IndicatorProperty()
{

}

IndicatorProperty::IndicatorProperty(Enum::FileType fileType, Enum::Filter filter, Enum::Spec spec, Enum::Operation operation){
    qDebug() << Q_FUNC_INFO;

    setFileInfo(fileType);
    setFilterInfo(filter);
    setSpecInfo(spec);
    computeIndicator(operation);
}

void IndicatorProperty::setFileInfo(Enum::FileType file)
{
    if (file == Enum::Trips){m_file = m_fileTrips; m_listRoad = m_listRoadNameTrips; m_roadColumn = "BlkRoute"; m_filterColumn = "TrpType";}
    if (file == Enum::Blocks){m_file = m_fileBlocks; m_listRoad = m_listRoadNameBlocks; m_roadColumn = "BlkRoute"; m_filterColumn = "TrpType";}
    if (file == Enum::Breaks){m_file = m_fileBreaks; m_listRoad = m_listRoadNameBreaks; m_roadColumn = "DtyRoute"; m_filterColumn = "BrkType";}
    if (file == Enum::Duties){m_file = m_fileDuties; m_listRoad = m_listRoadNameDuties; m_roadColumn = "DtyRoute"; m_filterColumn = "DtyIsValid";}
}

void IndicatorProperty::setFilterInfo(Enum::Filter filter)
{
    if (filter == Enum::TRP_DH) m_filter.append("DH");
    if (filter == Enum::BRK_DROPBACK) m_filter.append("DROPBACK");
    if (filter == Enum::DTY_VALID) m_filter.append("1");
    if (filter == Enum::DTY_INVALID) m_filter.append("0");

    if (filter == Enum::TRP_REG_OPP){m_filter += QStringList{"REG", "OPP"};}
    if (filter == Enum::TRP_IN_OUT){m_filter.append("IN");m_filter.append("OUT");}
    if (filter == Enum::BRK_BREAK_COFFEE_CREWB01_MEALBREAK){m_filter += QStringList{"BREAK", "COFFEE", "CREWB01", "MEALBREAK"};}
}

void IndicatorProperty::setSpecInfo(Enum::Spec spec)
{

}

void IndicatorProperty::computeIndicator(Enum::Operation operation){

    m_operator = new Operator(this, operation);
    qDebug() << Q_FUNC_INFO << m_listResult;
    if (m_operator)
        delete m_operator;
    m_operator = nullptr;

}

QString IndicatorProperty::file() const
{
    return m_file;
}

QString IndicatorProperty::roadColumn() const
{
    return m_roadColumn;
}

QString IndicatorProperty::filterColumn() const
{
    return m_filterColumn;
}

QStringList IndicatorProperty::filter() const
{
    return m_filter;
}

QString IndicatorProperty::road() const
{
    return m_road;
}

QStringList IndicatorProperty::listRoad() const
{
    return m_listRoad;
}

QList<QPair<QString, int> > IndicatorProperty::listResult() const
{
    return m_listResult;
}

void IndicatorProperty::setListResult(const QList<QPair<QString, int> > &newListResult)
{
    m_listResult = newListResult;
}






