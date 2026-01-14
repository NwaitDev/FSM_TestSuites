#include "procedures.hpp"


void even_bitcount_proc(bool& even, bool bit){
    if (bit){
        even = ! even;
    }
}