import QtQuick 2.0
import Sailfish.Silica 1.0

Item {
    property PageStack pageStack

    property string mainPage:  "pages/MainPage.qml"
    property string aboutPage: "pages/AboutPage.qml"

    function start() {
        var vm = diConsumer.mainVmInstance()
        vm.nextPressed.connect(showAbout)
        pushPageWithVm(mainPage, vm)
    }

    function showAbout() {
        var page = Qt.createComponent(Qt.resolvedUrl(aboutPage)).createObject()
        pageStack.push(page)
    }

    function pushPageWithVm(path, vm) {
        return pageStack.push(Qt.createComponent(Qt.resolvedUrl(path)), { "viewModel" : vm})
    }
}
