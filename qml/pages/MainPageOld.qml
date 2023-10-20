import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    allowedOrientations: Orientation.All

    PageHeader { title: qsTr("Простое Приложение") }

    Column {
        id: layout
        width: parent.width
        spacing: 16
        anchors.centerIn: parent

        Text {
            anchors { left: parent.left; right: parent.right; margins: Theme.horizontalPageMargin }
            id: txtCounter
            text: "counter"
        }

        Button {
            anchors { left: parent.left; right: parent.right; margins: Theme.horizontalPageMargin }
            text: qsTr("Увеличить")
            onClicked: console.log("increase")
        }

        Button {
            anchors { left: parent.left; right: parent.right; margins: Theme.horizontalPageMargin }
            text: qsTr("Дальше")
            onClicked: pageStack.push(Qt.resolvedUrl("AboutPageOld.qml"))
        }
    }
}
