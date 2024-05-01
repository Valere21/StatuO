import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import 'list'
import BaseTheme

Window {
    id: root
    width: 940
    height: 580
    visible: true
    title: qsTr("Hello World")

    property var rectDragDrop
    property real syncContentY
    onSyncContentYChanged: {
        listIndicatorTitle.contentY = syncContentY
        listIndicatorCategorie.contentY = syncContentY
    }

    MenuBar {
        id: menu
        anchors.left: parent.left
        anchors.right: parent.right
        Menu {
            id: importMenu
            title: qsTr("&Import")
            Action {id: importCs;text: qsTr("Nouveau Scénario");
                onTriggered: {
                    // var item = Qt.createComponent("./RectDragDrop.qml")
                    const rectDragDrop = Qt.createComponent("RectDragDrop.qml");
                    // if (rectDragDrop)
                    //     rectDragDrop.destroy()
                    if (rectDragDrop.status === Component.Ready){
                        rectDragDrop.createObject(root, { x: 500, y: 300 });
                        rectDragDrop.x = 500
                        rectDragDrop.y = 500
                        console.log(rectDragDrop.x)
                    }
                }
            }
        }

        Menu {
            id: editMenu
            title: qsTr("&Export CSV")
        }
    }

    Rectangle {
        id: rectIndicatorTitle
        property int marginLeft : width
        // color : "green"
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#505050" } // Gris foncé au début
            GradientStop { position: 0.5; color: "#f0f0f0" } // Gris clair au milieu
            GradientStop { position: 1.0; color: "#505050" } // Retour au gris foncé à la fin
        }

        anchors{
            top: menu.bottom
            bottom: parent.bottom
            left: parent.left
        }
        width: Screen.pixelDensity * BaseTheme.rectIndicatorTitle_width_mm
        ListIndicatorTitle {
            id: listIndicatorTitle
            onContentYChanged: {
                if (contentY !== root.syncContentY) {
                    root.syncContentY = contentY
                }
            }
        }
    }

    Rectangle {
        id: rectAllScenario
        anchors {
            top: menu.bottom
            bottom: parent.bottom
            left: rectIndicatorTitle.right
            right: parent.right
        }
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#505050" } // Gris foncé au début
            GradientStop { position: 0.5; color: "#f0f0f0" } // Gris clair au milieu
            GradientStop { position: 1.0; color: "#505050" } // Retour au gris foncé à la fin
        }

        CategorieSelector {
            id: itemRowBtType
        }

        Scenario {
            id: scenario
        }
    }
}

