#ifndef PROCESSCSV_H
#define PROCESSCSV_H

#include <QObject>
#include <QtCore>

class ProcessCsv : public QObject
{

    enum class Filter {
        TRP_REG_OPP,
        TRP_DH,
        TRP_IN_OUT,
        BRK_BREAK_COFFEE_CREWB01_MEALBREAK,
        BRK_DROPBACK,
        DTY_VALID,
        DTY_INVALID
    };

    enum class Spec {
        VEH_TASK_NUMBER,
        TRP_DISTANCE,
        TRP_DURATION,
        TRP_END_LAY,
        TRP_EXTRA_LAY,
        BLK_START_PREP_DUR_END_PREP_DUR,
        BLK_TOTAL_DUR,
        BRK_DURATION,
        DTY_PROCESS_GRP_STRAIGHT,
        DTY_PROCESS_GRP_BROKEN,
        DTY_PROCESS_GRP_FREE_OTHER_PART,
        DTY_PLAT_TIME,
        DTY_TRAVEL_TIME,
        DTY_SIGN_TIME,
        DTY_WORK_TIME,
        DTY_SPLIT_BRK,
        DTY_SPREAD,
        DTY_BASKET_EMPTY,
        DTY_OVERTIME,
        DTY_NIGHT_HRS,
        DTY_NIGHT_BONUS,
        DTY_GUARANTEE,
        SPELL_GUARANTEE
    };


    enum FileType{
        Trips,
        Blocks,
        Duties,
        Breaks
    };

    enum Operation{
        Count,
        CountFilter,
        CountSpec,
        CountFilterSpec,
        CountSpecUnique,

        CountPeakAM,
        CountOffPeak,
        CountPeakPM,

        Sum,
        SumFilterSpec,
        SumSpec
    };

    Q_OBJECT
public:
    ProcessCsv(QFile file);

    //Initialise les pairs de m_listFilter avec le nom de chaque mot-cle. membre->first de chaque pair = les noms de m_filter
    void setListFilterName();
    //Definit le second membre de chaque pair m_listFilter. second membre = numero de colonne dans fichier csv.
    //firstLine = première ligne lu d'un fichier csv
    void setListFilterIndex(QString firstLine);
    //Recupere le numero de colonne.
    //columnName = le nom de la colonne a recuperee
    int getFilterIndex(QString columnName);

    //Initialise la liste
    void setListRoadPerFile(FileType fileType, Filter filter, Spec spec);

    // void setListRoadTrips();
    // void setListRoadBlocks();
    // void setListRoadDuties();
    // void setListRoadBreaks();


    //Modifie m_listResultTemp.
    //Renvoie la somme de filter, de la catégorie columnName,
    QList<QPair<QString, int>> sumRoadByLine(FileType fileType, QString columnTypeName, QString filter);

    QList<QPair<QString, int>> computeFilter();

    QList<QPair<QString, int>> filterFct(FileType fileType, QString columnTypeName, QString filter);



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
