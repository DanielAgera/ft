#include <stdio.h>
#include <string.h>
#include "_text.h"

void rn(text txt, int num_str)
{

    int index = 0;
    std::list<std::string>::iterator current = txt->strs.begin();

    if(num_str < index){
        return;
    }
    while(current != txt->strs.end()) {
        if(index == num_str)
            break;
        current++;
        index++;
    }
    if(num_str > index){
        return;
    }
    txt->strs.erase(current);

    return;
}


