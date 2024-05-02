#include "indicatorproperty.h"


IndicatorProperty::IndicatorProperty()
{

}

IndicatorProperty::IndicatorProperty(Enum::FileType fileType, Enum::Filter filter, Enum::Spec spec, Enum::Operation operation){
    setFileInfo(fileType);
    setFilterInfo(filter);
    setSpecInfo(spec);
    computeIndicator(operation);
}

void IndicatorProperty::setFileInfo(Enum::FileType file)
{
    if (file == Enum::Trips){m_file.setFileName(m_fileTrips); m_listRoad = m_listRoadNameTrips; m_roadColumn = "BlkRoute"; m_filterColumn = "TrpType";}
    if (file == Enum::Blocks){m_file.setFileName(m_fileBlocks); m_listRoad = m_listRoadNameBlocks; m_roadColumn = "BlkRoute"; m_filterColumn = "TrpType";}
    if (file == Enum::Breaks){m_file.setFileName(m_fileBreaks); m_listRoad = m_listRoadNameBreaks; m_roadColumn = "DtyRoute"; m_filterColumn = "BrkType";}
    if (file == Enum::Duties){m_file.setFileName(m_fileDuties); m_listRoad = m_listRoadNameDuties; m_roadColumn = "DtyRoute"; m_filterColumn = "DtyIsValid";}
}

void IndicatorProperty::setFilterInfo(Enum::Filter filter)
{
    if (filter == Enum::TRP_DH) m_filter.append("DH");
    if (filter == Enum::BRK_DROPBACK) m_filter.append("DROPBACK");
    if (filter == Enum::DTY_VALID) m_filter.append("1");
    if (filter == Enum::DTY_INVALID) m_filter.append("0");

    if (filter == Enum::TRP_REG_OPP){m_filter.append("REG");m_filter.append("OPP");}
//    if (filter == Enum::BRK_BREAK_COFFEE_CREWB01_MEALBREAK){m_filter.append("BREAK","COFEE","CREWB01","MEALBREAK");m_filter.append("OUT");}
    if (filter == Enum::TRP_REG_OPP){m_filter.append("IN");m_filter.append("OUT");}
}

void IndicatorProperty::setSpecInfo(Enum::Spec spec)
{

}

void IndicatorProperty::computeIndicator(Enum::Operation operation){

}

QFile IndicatorProperty::file() const
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






