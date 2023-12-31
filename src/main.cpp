/*******************************************************************************
**
** Copyright (C) 2022 com.den3000
**
** This file is part of the Пример элмементарного приложения на Аворра ОС project.
**
** Redistribution and use in source and binary forms,
** with or without modification, are permitted provided
** that the following conditions are met:
**
** * Redistributions of source code must retain the above copyright notice,
**   this list of conditions and the following disclaimer.
** * Redistributions in binary form must reproduce the above copyright notice,
**   this list of conditions and the following disclaimer
**   in the documentation and/or other materials provided with the distribution.
** * Neither the name of the copyright holder nor the names of its contributors
**   may be used to endorse or promote products derived from this software
**   without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
** THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
** FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
** FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
** OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS;
** OR BUSINESS INTERRUPTION)
** HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
** WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE)
** ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
** EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
*******************************************************************************/

#include <auroraapp.h>
#include <QtQuick>

#include "mainvm.h"
#include "aboutvm.h"

#include "diprovider.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<MainVM>("CustomCppClasses.Module", 1, 0, "MainVM");
    qmlRegisterType<AboutVM>("CustomCppClasses.Module", 1, 0, "AboutVM");
    qmlRegisterType<DiProvider>("CustomCppClasses.Module", 1, 0, "DiProvider");

    QScopedPointer<QGuiApplication> application(Aurora::Application::application(argc, argv));
    application->setOrganizationName(QStringLiteral("com.den3000"));
    application->setApplicationName(QStringLiteral("BasicApp"));

    auto diProvider = make_shared<DiProvider>();

    QScopedPointer<QQuickView> view(Aurora::Application::createView());
    view->rootContext()->setContextProperty("diProvider", diProvider.get());
    // app with qml coordinator, c++ VMs / service / DI
    view->setSource(Aurora::Application::pathTo(QStringLiteral("qml/BasicApp.qml")));
    // pure qml app without coordinator and any arch
    // view->setSource(Aurora::Application::pathTo(QStringLiteral("qml/BasicAppV1.qml")));
    // pure qml app with coordinator
    // view->setSource(Aurora::Application::pathTo(QStringLiteral("qml/BasicAppV2.qml")));
    view->show();

    return application->exec();
}
