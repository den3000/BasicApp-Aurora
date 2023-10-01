import QtQuick 2.0
import Sailfish.Silica 1.0

Item {
    property PageStack pageStack

    property string mainPage:  "pages/MainPage.qml"
    property string aboutPage: "pages/AboutPage.qml"

    function start() {
        var page = Qt.createComponent(Qt.resolvedUrl(mainPage)).createObject()
        page.nextPressed.connect(showAbout)
        pageStack.push(page)
    }

    function showAbout() {
        var page = Qt.createComponent(Qt.resolvedUrl(aboutPage)).createObject()
        pageStack.push(page)
    }
}
