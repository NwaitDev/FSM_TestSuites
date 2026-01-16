#include "procedures.hpp"

double chips_rand(){
    return (float)(rand()) / (float)(RAND_MAX);
}

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

void source_proc(int min , int max, int& randomNumber){
    randomNumber = (int)(chips_rand()*(double)(max-min))+min;
}