import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import "."
import BaseTheme

ListView {
    id: listView
    spacing : 5
    clip: true
    anchors {
        left: parent.left
        right: parent.right
        bottom: parent.bottom
        top: parent.top
        topMargin: Screen.pixelDensity * BaseTheme.list_topMargin_menu_mm
    }

    model: IndicatorTitle {}
    delegate: Column {
        id: column
        Rectangle {
            anchors.horizontalCenter: parent.horizontalCenter
            color: "#f0d27f"
            clip: true
            width: Screen.pixelDensity * BaseTheme.indicatorName_width_mm
            height: Screen.pixelDensity * BaseTheme.indicator_height_mm
            Text {
                text: name
                wrapMode: Text.NoWrap
                font.pointSize: isTitle ? 14 : 10
                font.bold : isBold ? true : false
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }
}
