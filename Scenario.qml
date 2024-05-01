import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import 'list'
import BaseTheme

Rectangle {
    id: scenario
    width: Screen.pixelDensity * BaseTheme.scenario_width_mm

    gradient: Gradient {
        GradientStop { position: 0.0; color: "#505050" } // Gris foncé au début
        GradientStop { position: 0.5; color: "#f0f0f0" } // Gris clair au milieu
        GradientStop { position: 1.0; color: "#505050" } // Retour au gris foncé à la fin
    }

    anchors {
        left: parent.left
        leftMargin: Screen.pixelDenisty * BaseTheme.scenario_leftMargin_title_mm
        top: parent.top
        right: parent.right
        bottom: parent.bottom
    }

    CheckBox {
        id : isRef
        width: 38
        height: 37
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.top: parent.top
        anchors.topMargin: 5
    }

    ListIndicatorCategorie{
        id: listIndicatorCategorie
        onContentYChanged: {
            if (contentY !== root.syncContentY) {
                root.syncContentY = contentY
            }
        }
    }
}









