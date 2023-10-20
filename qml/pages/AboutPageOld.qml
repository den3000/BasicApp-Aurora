import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    allowedOrientations: Orientation.All

    PageHeader { title: qsTr("О приложении") }

    Column {
        id: layout
        width: parent.width
        spacing: 16
        anchors.centerIn: parent

        Text {
            anchors { left: parent.left; right: parent.right; margins: Theme.horizontalPageMargin }
            id: txtOld
            text: "Old value"
        }

        Text {
            anchors { left: parent.left; right: parent.right; margins: Theme.horizontalPageMargin }
            id: txtCounter
            text: "counter"
        }

        Button {
            anchors { left: parent.left; right: parent.right; margins: Theme.horizontalPageMargin }
            text: qsTr("Уменьшить")
            onClicked: console.log("decrease")
        }

        Button {
            anchors { left: parent.left; right: parent.right; margins: Theme.horizontalPageMargin }
            text: qsTr("Подтвердить")
            onClicked: pageStack.pop()
        }
    }
}
