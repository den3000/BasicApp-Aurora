#ifndef DICONTAINER_H
#define DICONTAINER_H

#include "easy_import.h"
#include "mainvm.h"
#include "aboutvm.h"

class DiContainer {
public:
    unique_ptr<MainVM> mainVmInstance()
        { return make_unique<MainVM>(); }

    unique_ptr<AboutVM> aboutVmInstance(QString const & text, int counter)
        { return make_unique<AboutVM>(text, counter); }
};

#endif // DICONTAINER_H
