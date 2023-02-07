#include <iostream>
#include <memory>
#include <vector>
#include "data.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    using dataT = std::unique_ptr<CData>;
    using vecT = std::vector<dataT>;
    using regT = std::unique_ptr<vecT>;
    regT REGS(std::make_unique<vecT>());

    for(int i = 0; i < 10; i++) {
       auto t = std::make_unique<CData>(i);
       REGS->push_back(std::move(t));
    }

    auto citer = REGS.get()->cbegin();
    auto eiter = REGS.get()->cend();

    for(; citer != eiter; citer++ ) {
        cout << "Value "  << citer->get()->data() << endl;
    }

    return 0;
}
