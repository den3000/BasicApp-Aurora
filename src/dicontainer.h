#ifndef DICONTAINER_H
#define DICONTAINER_H

#include "easy_import.h"

#include "mainvm.h"
#include "aboutvm.h"
#include "mathservice.h"

class DiContainer {
public:
    unique_ptr<MathService> mathServiceInstance()
        { return make_unique<MathService>(); }

    unique_ptr<MainVM> mainVmInstance(shared_ptr<MathService> service)
//        { return make_unique<MainVM>(service); }
        { return make_unique<MainVM>(); }

    unique_ptr<AboutVM> aboutVmInstance(int counter, shared_ptr<MathService> service)
        { return make_unique<AboutVM>(); }
};

#endif // DICONTAINER_H
