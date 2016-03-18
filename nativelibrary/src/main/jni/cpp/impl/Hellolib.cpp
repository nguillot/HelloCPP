//
// Created by Nicolas Guillot on 22/01/2016.
//

#include "../public/Hellolib.h"

std::u16string Hellolib::sayHello(const std::u16string &name) {

    std::u16string prefix = u"hello ";

    return prefix.append(name);
}
