#include "operator.h"

Operator::Operator(){

}

Operator::Operator(IndicatorProperty *indicator, Enum::Operation operation): m_indicator(indicator), m_operator(operation){
    if (m_indicator){
        switch (operation){
        case Enum::Count: count();                      break;
        case Enum::CountFilter: countFilter();          break;
        case Enum::CountSpec: countSpec();              break;
        case Enum::CountFilterSpec: countFilterSpec();  break;
        case Enum::CountSpecUnique: countSpecUnique();  break;
        case Enum::CountPeakAM:countPeakAM();           break;
        case Enum::CountOffPeak: countOffPeak();        break;
        case Enum::CountPeakPM:countPeakPM();           break;
        case Enum::Sum: sum();                          break;
        case Enum::SumFilterSpec: sumFilterSpec();      break;
        case Enum::SumSpec: sumSpec();                  break;
        default:                                        break;
        }
}
else
    qWarning() << "ERROR : Indicator Operation Failed";
}

void Operator::count()
{
    QFile *file = new QFile(m_indicator->file());
if (file->open(QIODevice::ReadOnly)){
        QTextStream stream(file);
    for (int i = 0; i < m_indicator->listRoad().size(); i++){
            bool firstLine = false;
            int sum = 0;
            while (!stream.atEnd()){
                if (!firstLine){
                    firstLine = true;
                    stream.readLine();
                }
                else {
                    QStringList list = stream.readLine().split(';');
                    if (list.at(getFilterIndex(m_indicator->roadColumn())) == m_indicator->listRoad().at(i))   {
                        if (list.at(getFilterIndex(columnTypeName)) == filter){
                            // qDebug() << "categorie " << listRoadNameFile.at(i) << " sum " << sum;
                            sum += 1;
                        }
                    }
                }
            }
            listSum.append(QPair<QString, int>(listRoadNameFile.at(i), sum));
            sum = 0;
        }
    }

}

void Operator::countFilter()
{

}

void Operator::countSpec()
{

}
void Operator::countSpecUnique()
{

}
void Operator::countPeakAM()
{

}
void Operator::countOffPeak()
{

}
void Operator::countPeakPM()
{

}
void Operator::sum()
{

}
void Operator::sumFilterSpec()
{

}
void Operator::sumSpec()
{

}
