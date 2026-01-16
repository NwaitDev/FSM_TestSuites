#include "procedures.hpp"


void even_bitcount_proc(bool& even, bool bit){
    if (bit){
        even = ! even;
    }
}

void password_locking_proc(int &state, int& output, int password){
    if (state == 0){
        if(password==1){
            output = 1;
        } else {
            output = 0;
        }
        state = 1;
    }
}