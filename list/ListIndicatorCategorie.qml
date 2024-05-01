import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import BaseTheme

ListView {
    spacing : 5
    clip: true
    anchors {
        left: parent.left
        right: parent.right
        bottom: parent.bottom
        top: parent.top
        topMargin: Screen.pixelDensity * BaseTheme.list_topMargin_menu_mm
    }
    model: IndicatorByCategorie {}
    delegate: Column {
        id: column
        Rectangle {
            color: "red"
            clip: true
            anchors.horizontalCenter: parent.horizontalCenter
            width: Screen.pixelDensity * BaseTheme.indicator_width_mm
            height: Screen.pixelDensity * BaseTheme.indicator_height_mm
            Text {
                text: value_indicator
                anchors.horizontalCenter: parent.horizontalCenter

            }
        }
    }
}
