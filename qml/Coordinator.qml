import QtQuick 2.0
import Sailfish.Silica 1.0
import CustomCppClasses.Module 1.0

Item {
    property PageStack pageStack

    signal onDecreaseConfirmed(int counter)

    property string mainPage:  "pages/MainPage.qml"
    property string aboutPage: "pages/AboutPage.qml"

    function pushPageWithVm(path, vm) { return pageStack.push(Qt.createComponent(Qt.resolvedUrl(path)), { "viewModel" : vm}) }

    function pop() { pageStack.pop() }

    function start() {
        var vm = diProvider.mainVmInstance()
        vm.nextPressed.connect(showAbout)
        onDecreaseConfirmed.connect(vm.decreased)
        pushPageWithVm(mainPage, vm)
    }

    function showAbout(counter) {
        var vm = diProvider.aboutVmInstance(counter)
        vm.confirmPressed.connect(onDecreaseConfirmed)
        vm.confirmPressed.connect(pop)
        pushPageWithVm(aboutPage, vm)
    }
}
