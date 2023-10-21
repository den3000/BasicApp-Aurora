import QtQuick 2.0
import Sailfish.Silica 1.0
import CustomCppClasses.Module 1.0

Item {
    property PageStack pageStack

    signal onDecreaseConfirmed(int counter)

    property string mainPage:  "pages/MainPage.qml"
    property string aboutPage: "pages/AboutPage.qml"

    function pushPage(path) { return pageStack.push(Qt.resolvedUrl(path) ) }

    function pop() { pageStack.pop() }

    function start() {
        var page = pushPage(mainPage)
        page.viewModel.nextPressed.connect(showAbout)
        onDecreaseConfirmed.connect(page.viewModel.decreased)
    }

    function showAbout(counter) {
        var page = pushPage(aboutPage)
        page.viewModel.inputCounter = counter
        page.viewModel.counter = counter
        page.viewModel.confirmPressed.connect(onDecreaseConfirmed)
        page.viewModel.confirmPressed.connect(pop)
    }

//    function pushPageWithVm(path, vm) {
//        return pageStack.push(Qt.createComponent(Qt.resolvedUrl(path)), { "viewModel" : vm})
//    }
}
