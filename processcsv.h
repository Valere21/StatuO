#ifndef PROCESSCSV_H
#define PROCESSCSV_H

#include <QObject>
#include <QtCore>

#include "enum.h"


class IndicatorProperty;
class Operation;
class ProcessCsv : public QObject
{

public:

    Q_OBJECT

    ProcessCsv();
    ProcessCsv(Enum::FileType file, Enum::Filter filter, Enum::Spec spec);


    //Initialise les pairs de m_listFilter avec le nom de chaque mot-cle. membre->first de chaque pair = les noms de m_filter
    void setListFilterName();
    //Definit le second membre de chaque pair m_listFilter. second membre = numero de colonne dans fichier csv.
    //firstLine = première ligne lu d'un fichier csv
    void setListFilterIndex(QString firstLine);
    //Recupere le numero de colonne.
    //columnName = le nom de la colonne a recuperee
    int getFilterIndex(QString columnName);

    //Initialise la liste
    void setListRoadPerFile();

    // void setListRoadTrips();
    // void setListRoadBlocks();
    // void setListRoadDuties();
    // void setListRoadBreaks();


    //Modifie m_listResultTemp.
    //Renvoie la somme de filter, de la catégorie columnName,
    // QList<QPair<QString, int>> sumRoadByLine(FileType fileType, QString columnTypeName, QString filter);

    // QList<QPair<QString, int>> computeFilter(FileType fileType, Filter filter, Spec spec, Operation operation);

    // QList<QPair<QString, int>> filterFct(FileType fileType, QString columnTypeName, QString filter);



    //Graphicage
    // 1
    int sumComCourseLine();
    //2
    int sumHLPCourseLine();
    //3
    int sumInOutCourseLine();
    //4
    int sumPeakVechicule();
    //5
    int sumOffPeakVechicule();
    //6
    int sumComKmLine();
    //7
    int sumHLPKmLine();
    //8
    int sumKmInOutLine();
    //9
    int sumEffectiveHour();



    QList<QPair<QString, int> *> listFilter() const;
    void setListFilter(const QList<QPair<QString, int> *> &newListFilter);

private:

    IndicatorProperty   *m_indicator = nullptr;
    Operation           *m_operation = nullptr;

    QString m_fileTrips = "C:\\QtProject\\Hastus\\trips-LOT1_TR_02-T1T2T5T6-Semaine-99.csv";
    QString m_fileBlocks = "C:\\QtProject\\Hastus\\blocks-LOT1_TR_02 T1T2T5T6-Semaine-99.csv";
    QString m_fileDuties = "C:\\QtProject\\Hastus\\file1.csv";
    QString m_fileBreaks = "C:\\QtProject\\Hastus\\file2.csv";

    //Liste des routes différentes
    QStringList m_listRoadNameTrips;
    QStringList m_listRoadNameBlocks;
    QStringList m_listRoadNameDuties;
    QStringList m_listRoadNameBreaks;



    //Liste des noms de filtres. Ils sont à ajoutées manuellement
    QStringList m_filter = {"Route","Type","BlkRoute", "Block Route", "Entrées","Sorties", "semaine", "TrpType"};
    //Liste de Pair avec association du nom avec leurs index de colonne dans csv
    QList<QPair<QString,int>*> m_listFilter;



    //Liste contenant les résultat des indicateurs graphique
    QList<QPair<QString,QStringList>> m_listResultTemp;
    //Liste contenant les résultat des indicateurs habillage
    QStringList m_listResultHab;
};

#endif // PROCESSCSV_H
