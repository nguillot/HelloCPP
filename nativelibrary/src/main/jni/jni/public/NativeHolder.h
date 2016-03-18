//
// Created by Nicolas Guillot on 17/03/2016.
//

#include "../../cpp/public/Hellolib.h"

#ifndef HELLOCPP_NATIVEHOLDER_H
#define HELLOCPP_NATIVEHOLDER_H
struct NativeHolder {
    std::shared_ptr<Hellolib> helloLib;
};
#endif //HELLOCPP_NATIVEHOLDER_H
