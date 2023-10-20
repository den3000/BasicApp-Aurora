import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    property int inputCounter
    property int counter: inputCounter

    signal onConfirmed

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
            text: qsTr("Было увеличено до = %1").arg(inputCounter)
        }

        Text {
            anchors { left: parent.left; right: parent.right; margins: Theme.horizontalPageMargin }
            id: txtCounter
            text: qsTr("Уменьшено до %1").arg(counter)
        }

        Button {
            anchors { left: parent.left; right: parent.right; margins: Theme.horizontalPageMargin }
            text: qsTr("Уменьшить")
            onClicked: counter = counter - 1
        }

        Button {
            anchors { left: parent.left; right: parent.right; margins: Theme.horizontalPageMargin }
            text: qsTr("Подтвердить")
            onClicked: {
                onConfirmed(counter)
                pageStack.pop()
            }
        }
    }
}
