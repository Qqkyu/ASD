#include "myStruct.hpp"

Struct::Struct(int range) : n{ range + 1 } {
    // We ignore index 0, hence range + 1
    arr = new int[n];
    for(int i{ 0 }; i != n; ++i) {
        arr[i] = 0;
    }
}

void Struct::select() {
    if(!elems.empty()) {
        int x = elems.top();
        elems.pop();
        arr[x] = 0;
    }
}

bool Struct::search(int x) const {
    if(x > 0 && x <= n) {
        return arr[x] == 1;
    }
    return false;
}

void Struct::insert(int x) {
    if(x > 0 && x <= n) {
        arr[x] = 1;
        elems.push(x);
    }
}
