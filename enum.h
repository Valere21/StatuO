#ifndef ENUM_H
#define ENUM_H

#include <QObject>

class Enum
{

public:
    Enum();

    enum Filter {
        NO_FILTER,
        TRP_REG_OPP,
        TRP_DH,
        TRP_IN_OUT,
        BRK_BREAK_COFFEE_CREWB01_MEALBREAK,
        BRK_DROPBACK,
        DTY_VALID,
        DTY_INVALID
    };
    enum FileType{
        Trips,
        Blocks,
        Duties,
        Breaks
    };
    enum Spec {
        NO_SPEC,
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
};

#endif // ENUM_H
