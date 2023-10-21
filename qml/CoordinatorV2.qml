import QtQuick 2.0
import Sailfish.Silica 1.0

Item {
    property PageStack pageStack

    signal onDecreaseConfirmed(int counter)

    property string mainPage:  "pages/MainPageV2.qml"
    property string aboutPage: "pages/AboutPageV2.qml"

    function pushPage(path) { return pageStack.push(Qt.resolvedUrl(path) ) }

    function popPage() { pageStack.pop() }

    function start() {
        var page = pushPage(mainPage)
        page.onNextPressed.connect(showAbout)
        onDecreaseConfirmed.connect(page.decreased)
    }

    function showAbout(counter) {
        var page = pushPage(aboutPage)
        page.inputCounter = counter
        page.onConfirmed.connect(function() {
            onDecreaseConfirmed(page.counter)
            popPage()
        })
    }
}
