import QtQuick 2.0
import Sailfish.Silica 1.0

Item {
    property PageStack pageStack

    signal decreaseConfirmed(int counter)

    property string mainPage:  "pages/MainPage.qml"
    property string aboutPage: "pages/AboutPage.qml"

    function start() {
        var vm = diConsumer.mainVmInstance()
        vm.nextPressed.connect(showAbout)
        decreaseConfirmed.connect(vm.decreased)

        pushPageWithVm(mainPage, vm)
    }

    function showAbout(text, counter) {
        var vm = diConsumer.aboutVmInstance(text, counter)
        vm.confirmPressed.connect(decreaseConfirmed)
        vm.confirmPressed.connect(pop)
        pushPageWithVm(aboutPage, vm)
    }

    function pushPageWithVm(path, vm) {
        return pageStack.push(Qt.createComponent(Qt.resolvedUrl(path)), { "viewModel" : vm})
    }

    function pop() {
        pageStack.pop()
    }
}
