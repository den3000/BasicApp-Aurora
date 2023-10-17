#ifndef DIPROVIDER_H
#define DIPROVIDER_H

#include "easy_import.h"
#include "mainvm.h"
#include "aboutvm.h"

class DiProvider {
public:
    unique_ptr<MainVM> mainVmInstance()
        { return make_unique<MainVM>(); }

    unique_ptr<AboutVM> aboutVmInstance(QString const & text, int counter)
        { return make_unique<AboutVM>(text, counter); }
};

#endif // DIPROVIDER_H
