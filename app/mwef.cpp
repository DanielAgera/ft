#include <stdio.h>
#include <string.h>
#include "_text.h"


void mwef(text txt)
{
    
    std::string line = *(txt->cursor->line);
    std::list<std::string>::iterator current = txt->strs.begin();
    
    while(current != txt->cursor->line){
        
        
        current++;

    }
    int lenght, pos = txt->cursor->position;

        int i = pos;
        
        lenght = line.length();
        
        while((i < lenght) && (line[i] != ' ') && (line[i] != '\n') && (line[i] != '?') && (line[i] != '\0') && (line[i] != ',') && (line[i] != '.') && (line[i] != '!')){
            
            
            txt->cursor->position = i++;
        
        }
        txt->cursor->position = i++;
        return;
}
        
        
        
