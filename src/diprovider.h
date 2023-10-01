#ifndef DIPROVIDER_H
#define DIPROVIDER_H

#include "easy_import.h"
#include "mainvm.h"

class DiProvider {
public:
    unique_ptr<MainVM> mainVmInstance()
        { return make_unique<MainVM>(); }
};

#endif // DIPROVIDER_H
