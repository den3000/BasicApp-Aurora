import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    property int counter: 0

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
            text: qsTr("Увеличено до %1").arg(counter)
        }

        Button {
            anchors { left: parent.left; right: parent.right; margins: Theme.horizontalPageMargin }
            text: qsTr("Увеличить")
            onClicked: counter = counter + 1
        }

        Button {
            anchors { left: parent.left; right: parent.right; margins: Theme.horizontalPageMargin }
            text: qsTr("Дальше")
            onClicked: {
//                var page = pageStack.push(Qt.resolvedUrl("AboutPageV1.qml"), { "inputCounter": counter } )

                var page = pageStack.push(Qt.resolvedUrl("AboutPageV1.qml"))
                page.inputCounter = counter

                page.onConfirmed.connect(function() {
                    counter = page.counter
                })
            }
        }
    }
}
