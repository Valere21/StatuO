import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import 'list'
import BaseTheme


Rectangle {
    radius: 30
    id: rectDragDrop
    opacity: 0
    anchors{
        left: parent.left
        top:parent.top
    }

    Timer {
        id: timerAnimation
        interval: 100
        repeat: true
        onTriggered:{
            if(!rectDragDrop.opacity === 1)
                timerAnimation.running = false
            else
                rectDragDrop.opacity += 0.05
        }
    }

    Component.onCompleted:{
         timerAnimation.running = true
        console.log("Created")
    }

    // Component.onCompleted: timerAnimation.running = true

    width: Screen.pixelDensity * BaseTheme.popUp_width_mm
    height: Screen.pixelDensity * BaseTheme.popUp_height_mm
    color: "#5aa84a";
    border.width: 3
    border.color: "grey"
    Rectangle {

        radius:30
        anchors.centerIn: parent
        border.width: 3
        border.color: "#68bd57"

        color: "#56a845";

        width:parent.width*0.95
        height:parent.height*0.95

        Component.onCompleted: {
            console.log(width, height);
        }

        Image {
            anchors.centerIn: parent
            width: Screen.pixelDensity * BaseTheme.popUp_image_width_mm
            height: Screen.pixelDensity * BaseTheme.popUp_image_height_mm
            source: "./image/Picture2.jpg"
            fillMode: Image.PreserveAspectFit

            Component.onCompleted:{
                console.log("height" + height)
                console.log("width " + width)
            }
        }

        DropArea {
            anchors.fill: parent
            onDropped: {
                if (drop.hasUrls) {
                    for (var i = 0; i < drop.urls.length; ++i) {
                        console.log("Dropped file: " + drop.urls[i]);
                        // Ajouter ici le traitement des fichiers
                    }
                }
                drop.acceptProposedAction();
            }
            onEntered: {
                drag.acceptProposedAction();
            }
        }
    }
}
