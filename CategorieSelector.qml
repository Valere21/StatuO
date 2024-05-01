import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import BaseTheme

Item {
    id: itemRowBtType
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.top: parent.top
    anchors.topMargin: 15
    width: parent.width
    height: 30
    ButtonGroup {buttons: rowBtType.children; exclusive: true}
    Row {
        id: rowBtType
        spacing : 25
        anchors.fill: parent.fill
        anchors.horizontalCenter: parent.horizontalCenter
        Button {
            id: btTypeLigne
            height: 30
            text: "LIGNE"
            font.bold: true
            font.pointSize: 12
            width: 90
        }
        Button {
            id: btTypeVehicule
            height: 30
            text: "VEHICULE"
            font.bold: true
            font.pointSize: 12
            width: 90
        }
        Button {
            id: btTypeAll
            height: 30
            text: "TOTAL"
            font.pointSize: 12
            font.bold: true
            width: 90
        }
    }
}
