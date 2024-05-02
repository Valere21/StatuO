#include "processcsv.h"
#include "indicatorproperty.h"
#include "qdebug.h"

ProcessCsv::ProcessCsv() {
    QFile file = m_fileTrips;
    setListFilterName();
    QElapsedTimer timer;
    timer.start();

    if (file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        setListFilterIndex(stream.readLine());

        bool flagFirstLine = false;
        while (!stream.atEnd()){
            flagFirstLine = true;
            stream.readLine() ;
            if (flagFirstLine){
            }
        }
        qDebug() << "nombre de route differente " << m_listRoadNameTrips.size();

    }
    else {
        qDebug() << file.errorString();
        qDebug() << file.fileName();
        qDebug() << QCoreApplication::applicationDirPath();
        qDebug() << QCoreApplication::applicationFilePath();
    }
    setListRoadPerFile();
    // setListRoadTrips();
    // setListRoadBlocks();
    // setListRoadDuties();
    // setListRoadBreaks();


    sumComCourseLine();
    sumHLPCourseLine();
    sumPeakVechicule();
    qDebug() << "milliseconds elapsed " << timer.elapsed() << Qt::endl;

}

void ProcessCsv::setListFilterName(){
    for (int i = 0; i < m_filter.size(); i++){
        QPair<QString,int> *pair = new QPair<QString,int>(m_filter.at(i), NULL);
        m_listFilter.append(pair);
    }
}

int ProcessCsv::getFilterIndex(QString columnName)
{
    int result = -1;
    for (int i = 0; i < m_listFilter.size(); i++)
        if (m_listFilter.at(i)->first == columnName)
            result = m_listFilter.at(i)->second;
    if (result == -1)
        qWarning("ColumnName not found !");
    return result;
}

void ProcessCsv::setListFilterIndex(QString firstLine){

    QStringList listFirstLine = firstLine.split(';');
    for (int i = 0; i < m_listFilter.size(); i++){
        if (listFirstLine.contains(m_listFilter.at(i)->first))
            m_listFilter.value(i)->second = listFirstLine.indexOf(m_listFilter.at(i)->first);
    }
}

void ProcessCsv::setListRoadPerFile(){

    QStringList fileList{m_fileTrips, m_fileBlocks, m_fileDuties,m_fileBreaks};
    QList<QStringList> roadNameList{m_listRoadNameTrips, m_listRoadNameBlocks, m_listRoadNameDuties, m_listRoadNameBreaks};

    QString roadColumnName;
    QFile *file = nullptr;

    for (int i = 0; i < fileList.size(); i++){
        file = new QFile(fileList.at(i));
        roadColumnName = (fileList.at(i) == m_fileTrips || fileList.at(i) == m_fileBlocks) ? "BlkRoute" : "DtyRoute";
        if (file->open(QIODevice::ReadOnly)){
            QTextStream stream(file);
            bool firstLine = false;
            while (!stream.atEnd()){
                if (!firstLine){
                    firstLine = true;
                    stream.readLine();
                }
                else {
                    QStringList list = stream.readLine().split(';');
                    if (getFilterIndex(roadColumnName) == -1)
                        break;
                    else{
                        QString road = list.at(getFilterIndex(roadColumnName));
                        if (!roadNameList.at(i).contains(road)){
                            roadNameList.value(i).append(QString(road));
                        }
                    }
                }
            }
        }
        else
            ;
        //            qDebug() <<fileList.at(i) << " " << file->fileName() <<" " << file->errorString();
    }
}

QList<QPair<QString,int>> ProcessCsv::sumRoadByLine(FileType fileType, QString columnTypeName, QString filter)
{
    QStringList listRoadNameFile;
    QString roadColumnName;
    std::unique_ptr<QFile> file(new QFile());
    QList<QPair<QString, int>> listSum;


    switch (fileType){
    case Blocks | Trips:
        qDebug() << ("called");
        listRoadNameFile = m_listRoadNameTrips;
        file->setFileName(m_fileTrips);
        roadColumnName = "BlkRoute";
        break;

        // case Blocks:
    //     listRoadNameFile = m_listRoadNameBlocks;
    //     file->setFileName(m_fileBlocks);
    //     roadColumnName = "Blk Route";
    //     break;
    case Duties | Breaks:
        listRoadNameFile = m_listRoadNameDuties;
        file->setFileName(m_fileDuties);
        roadColumnName = "DtyRoute";
        break;
    default:
        break;
    }

    qDebug() << "roadColumnName, file->fileName() " << roadColumnName << " & " << file->fileName();

    if (file->open(QIODevice::ReadOnly)){
        QTextStream stream(file.get());
        for (int i = 0; i < listRoadNameFile.size(); i++){
            bool firstLine = false;
            int sum = 0;
            while (!stream.atEnd()){
                if (!firstLine){
                    firstLine = true;
                    stream.readLine();
                }
                else {
                    QStringList list = stream.readLine().split(';');
                    if (list.at(getFilterIndex(roadColumnName)) == listRoadNameFile.at(i))   {
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
    return listSum;
}

QList<QPair<QString, int> > ProcessCsv::computeFilter(FileType fileType, Filter filter, Spec spec, Operation operation)
{
    QStringList listRoadNameFile;
    QString roadColumnName;
    QString filterColumnName;
    std::unique_ptr<QFile> file(new QFile());
    QList<QPair<QString, int>> listSum;
    roadColumnName =  (fileType == Trips || fileType == Blocks) ?  "BlkRoute" : "DtyRoute";
    switch (fileType){
    case Trips:
        listRoadNameFile = m_listRoadNameTrips;
        file->setFileName(m_fileTrips);
        filterColumnName = "trpType";
        break;
    case Blocks:
        listRoadNameFile = m_listRoadNameBlocks;
        file->setFileName(m_fileBlocks);
        filterColumnName = "trpType";
        break;
    case Breaks:
        listRoadNameFile = m_listRoadNameBreaks;
        file->setFileName(m_fileBreaks);
        filterColumnName = "BrkType";
        break;
    case Duties:
        listRoadNameFile = m_listRoadNameDuties;
        file->setFileName(m_fileDuties);
        filterColumnName = "DtyIsValid";
        break;
    default:
        break;
    }

    qDebug() << "roadColumnName, file->fileName() " << roadColumnName << " & " << file->fileName();

    if (file->open(QIODevice::ReadOnly)){
        QTextStream stream(file.get());
        for (int i = 0; i < listRoadNameFile.size(); i++){
            bool firstLine = false;
            int sum = 0;
            while (!stream.atEnd()){
                if (!firstLine){
                    firstLine = true;
                    stream.readLine();
                }
                else {
                    QStringList list = stream.readLine().split(';');
                    if (list.at(getFilterIndex(roadColumnName)) == listRoadNameFile.at(i))   {
                        if (list.at(getFilterIndex(filterColumnName)) == filter){
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
    return listSum;
}

int ProcessCsv::sumComCourseLine()
{
    IndicatorProperty *indicator = new IndicatorProperty(Enum::Trips, Enum::TRP_REG_OPP, Enum::None);
    Operation *operation = new Operation(indicator, Enum::CountFilter);
    QList<QPair<QString, int>> listOperation = operation->getResult();

    qDebug() << Q_FUNC_INFO;
    QList<QPair<QString, int>> list = sumRoadByLine(Enum::Trips, Enum::TRP_REG_OPP, Enum::REG);
    for (int i = 0; i < list.size(); i++){
        qDebug() << "Somme par ligne : " << list.at(i).first << " " << list.at(i).second;
    }
    return 0;
}

int ProcessCsv::sumHLPCourseLine()
{
    qDebug() << Q_FUNC_INFO;
    QList<QPair<QString, int>> list = sumRoadByLine(Trips, "Type", "Haut-le-pied");
    for (int i = 0; i < list.size(); i++){
        qDebug() << "Somme par ligne : " << list.at(i).first << " " << list.at(i).second;
    }
    return 0;
}

int ProcessCsv::sumInOutCourseLine()
{
    return 0;
}

int ProcessCsv::sumPeakVechicule()
{
    qDebug() << Q_FUNC_INFO;
    QList<QPair<QString, int>> list = sumRoadByLine(Enum::Blocks, "Type", "semaine");
    for (int i = 0; i < list.size(); i++){
        qDebug() << "Somme par ligne : " << list.at(i).first << " " << list.at(i).second;
    }
    return 0;
}

int ProcessCsv::sumOffPeakVechicule()
{
    qDebug() << Q_FUNC_INFO;
    QList<QPair<QString, int>> list = sumRoadByLine(Blocks, "Type", "semaine");
    for (int i = 0; i < list.size(); i++){
        qDebug() << "Somme par ligne : " << list.at(i).first << " " << list.at(i).second;
    }
    return 0;
}

int ProcessCsv::sumComKmLine()
{
    qDebug() << Q_FUNC_INFO;
    QList<QPair<QString, int>> list = sumRoadByLine(Trips, "Type", "Régulier");
        for (int i = 0; i < list.size(); i++){
        qDebug() << "Somme par ligne : " << list.at(i).first << " " << list.at(i).second;
    }
    return 0;
}

int ProcessCsv::sumHLPKmLine()
{
    qDebug() << Q_FUNC_INFO;
    QList<QPair<QString, int>> list = sumRoadByLine(Trips, "Type", "Haut-le-Pied");
    for (int i = 0; i < list.size(); i++){
        qDebug() << "Somme par ligne : " << list.at(i).first << " " << list.at(i).second;
    }
    return 0;
}

int ProcessCsv::sumKmInOutLine()
{
    qDebug() << Q_FUNC_INFO;
    QList<QPair<QString, int>> list = sumRoadByLine(Trips, "Type", "InOut");
    for (int i = 0; i < list.size(); i++){
        qDebug() << "Somme par ligne : " << list.at(i).first << " " << list.at(i).second;
    }
    return 0;}

int ProcessCsv::sumEffectiveHour()
{
    qDebug() << Q_FUNC_INFO;
    QList<QPair<QString, int>> list = sumRoadByLine(Trips, "Type", "InOut");
    for (int i = 0; i < list.size(); i++){
        qDebug() << "Somme par ligne : " << list.at(i).first << " " << list.at(i).second;
    }
    return 0;
}

































