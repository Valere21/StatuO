#include "processcsv.h"
#include "indicatorproperty.h"
#include "qdebug.h"

ProcessCsv::ProcessCsv() {
    QElapsedTimer timer;
    timer.start();

    setListFilterName();
    setListRoadPerFile();
    sumComCourseLine();

    qDebug() << "milliseconds elapsed " << timer.elapsed() << Qt::endl;

}

ProcessCsv::ProcessCsv(Enum::FileType fileType, Enum::Filter filter, Enum::Spec spec, Enum::Operation operation)
{

}

void ProcessCsv::setListFilterName(){
    for (int i = 0; i < m_filter.size(); i++){
        QPair<QString,int> pair(m_filter.at(i), NULL);
        m_listFilter.append(pair);
    }
}

int ProcessCsv::getFilterIndex(QString columnName)
{
    int result = -1;
    for (int i = 0; i < m_listFilter.size(); i++)
        if (m_listFilter.at(i).first == columnName)
            result = m_listFilter.at(i).second;
    if (result == -1)
        qWarning("ColumnName not found !");
    return result;
}

void ProcessCsv::setListFilterIndex(QString firstLine){
    QStringList listFirstLine = firstLine.split(';');
    if (listFirstLine.isEmpty()) {
        qDebug() << "Warning: Empty header line.";
        return;
    }

    for (int i = 0; i < m_listFilter.size(); i++) {
        int index = listFirstLine.indexOf(m_listFilter.at(i).first);
        if (index != -1) {
            m_listFilter[i].second = index;
        } else {
            qDebug() << "Warning: Column name not found in header:" << m_listFilter.at(i).first;
        }
    }
}

void ProcessCsv::setListRoadPerFile() {
    QStringList fileList{m_fileTrips, m_fileBlocks, m_fileDuties, m_fileBreaks};
    QList<QStringList*> roadNameList{&m_listRoadNameTrips, &m_listRoadNameBlocks, &m_listRoadNameDuties, &m_listRoadNameBreaks};

    QString roadColumnName;
    QFile file;

    for (int i = 0; i < fileList.size(); i++) {
        file.setFileName(fileList.at(i));
        if (fileList.at(i) == m_fileTrips || fileList.at(i) == m_fileBlocks)
            roadColumnName = "BlkRoute";
        else if (fileList.at(i) == m_fileBreaks)
            roadColumnName = "BrkType";
        else if (fileList.at(i) == m_fileDuties)
            roadColumnName = "DtyIsValid";

        if (file.open(QIODevice::ReadOnly)) {
            QTextStream stream(&file);
            bool firstLine = false;
            int colIndex = -1;
            while (!stream.atEnd()) {
                QString line = stream.readLine();
                if (!firstLine) {
                    firstLine = true;
                    colIndex = line.split(';').indexOf(roadColumnName);
                    setListFilterIndex(line);
                } else {
                    QStringList list = line.split(';');
                    if (colIndex == -1 || colIndex >= list.size())
                        continue;
                    QString& road = list[colIndex];
                    if (!roadNameList[i]->contains(road)) {
                        roadNameList[i]->append(road);
                    }
                }
            }
            file.close();
        } else {
            //qDebug() << "Could not open file:" << file.fileName() << file.errorString();
        }
    }
}

// void ProcessCsv::setListRoadPerFile(){

//     QStringList fileList{m_fileTrips, m_fileBlocks, m_fileDuties,m_fileBreaks};
//     QList<QStringList*> roadNameList{&m_listRoadNameTrips, &m_listRoadNameBlocks, &m_listRoadNameDuties, &m_listRoadNameBreaks};

//     QString roadColumnName;
//     QFile *file = nullptr;

//     for (int i = 0; i < fileList.size(); i++){
//         file = new QFile(fileList.at(i));
//         if (fileList.at(i) == m_fileTrips) roadColumnName = "BlkRoute";
//         if (fileList.at(i) == m_fileBlocks) roadColumnName = "BlkRoute";
//         if (fileList.at(i) == m_fileBreaks) roadColumnName = "BrkType";
//         if (fileList.at(i) == m_fileDuties) roadColumnName = "DtyIsValid";


//         if (file->open(QIODevice::ReadOnly)){
//             QTextStream stream(file);
//             bool firstLine = false;
//             while (!stream.atEnd()){
//                 if (!firstLine){
//                     firstLine = true;
//                     stream.readLine();
//                 }
//                 else {
//                     QStringList list = stream.readLine().split(';');
//                     if (getFilterIndex(roadColumnName) == -1)
//                         break;
//                     else{
//                         QString road = list.at(getFilterIndex(roadColumnName));
//                         if (!roadNameList.at(i)->contains(road)){
//                             roadNameList.value(i)->append(QString(road));
//                         }
//                     }
//                 }
//             }
//         }
//         // else
//         // qDebug() <<fileList.at(i) << " " << file->fileName() <<" " << file->errorString();
//         if (file)
//             delete file;
//         file = nullptr;
//     }
// }

int ProcessCsv::sumComCourseLine()
{
    // qDebug() << Q_FUNC_INFO;
    IndicatorProperty *indicator = new IndicatorProperty(this, Enum::Trips, Enum::NO_FILTER, Enum::NO_SPEC, Enum::Count);
    // Operation *operation = new Operation(indicator, Enum::CountFilter);
    // QList<QPair<QString, int>> listOperation = operation->getResult();

    // QList<QPair<QString, int>> list = sumRoadByLine(Enum::Trips, Enum::TRP_REG_OPP, Enum::REG);
    for (int i = 0; i < indicator->listResult().size(); i++){
        qDebug() << "Somme par ligne : " << indicator->listResult().at(i).first << " " << indicator->listResult().at(i).second;
    }
    if (indicator)
        delete indicator;
    indicator = nullptr;
    return 0;
}
