import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import BaseTheme

ListModel {
    ListElement { isTitle: true; isBold: true; name: " Graphicage" }

        //Ajouter fct soustitre, enelver rectVALUE

    ListElement { isTitle: false; isBold: true; name: " nombre de courses" }
    ListElement { isTitle: false; isBold: false; name: " nombre de courses commerciales" }
    ListElement { isTitle: false; isBold: false; name: " nombre de courses HLP" }
    ListElement { isTitle: false; isBold: false; name: " nombre de courses Entrées/Sorties" }
    ListElement { isTitle: false; isBold: true; name: " nombre de courses totaux" }

    ListElement { isTitle: false; isBold: true; name: " nombre de véhicules" }
    ListElement { isTitle: false; isBold: false; name: " heure pointe matin" }
    ListElement { isTitle: false; isBold: false; name: " heure creuse midi" }
    ListElement { isTitle: false; isBold: false; name: " heure pointe soir" }

    ListElement { isTitle: false; isBold: true; name: " distances" }
    ListElement { isTitle: false; isBold: false; name: " km commerciaux (KC)" }
    ListElement { isTitle: false; isBold: false; name: " km HLP" }
    ListElement { isTitle: false; isBold: false; name: " km Entrées/Sorties" }
    ListElement { isTitle: false; isBold: true; name: " km totaux (KT)" }

    ListElement { isTitle: false; isBold: true; name: " heures véhicule" }
    ListElement { isTitle: false; isBold: false; name: " heures commerciales" }
    ListElement { isTitle: false; isBold: false; name: " heures HLP" }
    ListElement { isTitle: false; isBold: false; name: " heures Entrées/Sorties" }
    ListElement { isTitle: false; isBold: false; name: " heures battement" }
    ListElement { isTitle: false; isBold: false; name: " heures battement suppl. (attente)" }
    ListElement { isTitle: false; isBold: false; name: " heures prép/déprep. véhicule" }
    ListElement { isTitle: false; isBold: true; name: " heures totales véhicule (TUV)" }

    ListElement { isTitle: false; isBold: true; name: " indicateurs custom" }
    ListElement { isTitle: false; isBold: false; name: " vitesse commerciale" }
    ListElement { isTitle: false; isBold: false; name: " vitesse d'exploitation" }
    ListElement { isTitle: false; isBold: false; name: " % HLP / KC" }
    ListElement { isTitle: false; isBold: false; name: " % battement / HC" }
    ListElement { isTitle: false; isBold: false; name: " KC / nombre de véhicules" }

    //-----------------------------------------------------------------------------------------------//

    ListElement { isTitle: true; isBold: true; name: " Habillage" }

    ListElement { isTitle: false; isBold: true; name: " services-agent" }
    ListElement { isTitle: false; isBold: false; name: " nombre de services continus" }
    ListElement { isTitle: false; isBold: false; name: " nombre de services brisées (en deux fois)" }
    ListElement { isTitle: false; isBold: false; name: " nombre de services partiels" }
    ListElement { isTitle: false; isBold: false; name: " nombre de services invalides" }
    ListElement { isTitle: false; isBold: true; name: " nombre de services-agent" }

    ListElement { isTitle: false; isBold: true; name: " heures travaillées" }
    ListElement { isTitle: false; isBold: false; name: " temps au volant" }
    ListElement { isTitle: false; isBold: false; name: " temps de déplacement" }
    ListElement { isTitle: false; isBold: false; name: " temps de prise/fin de service" }
    ListElement { isTitle: false; isBold: true; name: " temps annexes" }
    ListElement { isTitle: false; isBold: false; name: " temps pause" }
    ListElement { isTitle: false; isBold: false; name: " temps pause glissement" }
    ListElement { isTitle: false; isBold: true; name: " temps travaillé effectif (TTE)" }
    ListElement { isTitle: false; isBold: false; name: " temps coupure" }
    ListElement { isTitle: false; isBold: true; name: " amplitude" }

    ListElement { isTitle: false; isBold: true; name: " Primes et compensations" }
    ListElement { isTitle: false; isBold: false; name: " nb de services avec panier midi" }
    ListElement { isTitle: false; isBold: false; name: " heures de nuit" }
    ListElement { isTitle: false; isBold: false; name: " heures supplémentaires" }
    ListElement { isTitle: false; isBold: false; name: " prime de nuit" }
    ListElement { isTitle: false; isBold: false; name: " prime vacation" }
    ListElement { isTitle: false; isBold: false; name: " prime d'amplitude" }

    ListElement { isTitle: false; isBold: true; name: " indicateurs custom" }
    ListElement { isTitle: false; isBold: false; name: " temps travaillé moyen (TTE/SA)" }
    ListElement { isTitle: false; isBold: false; name: " heures commerciales / TTE" }
    ListElement { isTitle: false; isBold: false; name: " KC/SA" }
    ListElement { isTitle: false; isBold: false; name: " TCC/SA" }
    ListElement { isTitle: false; isBold: false; name: " TUV/TTT" }
}
