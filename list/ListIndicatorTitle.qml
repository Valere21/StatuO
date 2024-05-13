import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

import "."
import BaseTheme

ListView {
    id: listView
    IndicatorByCategorie{
        id: modelIndCat
    }
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
    // delegate: Column {
    delegate: RowLayout{
        width: Screen.pixelDensity * BaseTheme.indicatorName_width_mm
        height: Screen.pixelDensity * BaseTheme.indicator_height_mm

        id: column
        // Rectangle {
        //     anchors.horizontalCenter: parent.horizontalCenter
        //     color: "#f0d27f"
        //     clip: true
        //     width: Screen.pixelDensity * BaseTheme.indicatorName_width_mm
        //     height: Screen.pixelDensity * BaseTheme.indicator_height_mm
        //     Text {
        //         text: name
        //         wrapMode: Text.NoWrap
        //         font.pointSize: isTitle ? 14 : 10
        //         font.bold : isBold ? true : false
        //         anchors.verticalCenter: parent.verticalCenter
        //     }
        // }

        Rectangle{
            Layout.fillHeight: true;
            Layout.fillWidth: true;
            color: "#f0d27f"
            Text {
                text: name
                wrapMode: Text.NoWrap
                font.pointSize: isTitle ? 14 : 10
                font.bold : isBold ? true : false
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Rectangle {
            color: "red"
            Layout.fillHeight: true;
            Layout.fillWidth: true;

            clip: true
            // anchors.horizontalCenter: parent.horizontalCenter
            // width: Screen.pixelDensity * BaseTheme.indicator_width_mm
            // height: Screen.pixelDensity * BaseTheme.indicator_height_mm
            Text {
                // text: "value_indicator"
                text: modelIndCat.get(listView.index).value_indicator
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }

}
