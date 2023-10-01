# Пример элмементарного приложения на Аворра ОС

Пример элмементарного приложения на Аворра ОС

The source code of the project is provided under
[the license](LICENSE.BSD-3-CLAUSE.md),
that allows it to be used in third-party applications.

## Project Structure

The project has a common structure
of an application based on C++ and QML for Aurora OS.

* **[com.den3000.BasicApp.pro](com.den3000.BasicApp.pro)** file
  describes the project structure for the qmake build system.
* **[icons](icons)** directory contains application icons for different screen resolutions.
* **[qml](qml)** directory contains the QML source code and the UI resources.
  * **[cover](qml/cover)** directory contains the application cover implementations.
  * **[icons](qml/icons)** directory contains the custom UI icons.
  * **[pages](qml/pages)** directory contains the application pages.
  * **[BasicApp.qml](qml/BasicApp.qml)** file
    provides the application window implementation.
* **[rpm](rpm)** directory contains the rpm-package build settings.
  **[com.den3000.BasicApp.spec](rpm/com.den3000.BasicApp.spec)** file is used by rpmbuild tool.
  It is generated from **[com.den3000.BasicApp.yaml](rpm/com.den3000.BasicApp.yaml)** file.
* **[src](src)** directory contains the C++ source code.
  * **[main.cpp](src/main.cpp)** file is the application entry point.
* **[translations](translations)** directory contains the UI translation files.
* **[com.den3000.BasicApp.desktop](com.den3000.BasicApp.desktop)** file
  defines the display and parameters for launching the application.