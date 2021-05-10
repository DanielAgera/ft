/**
 * process_forward.c -- реализует обобщенную функцию обработки текста
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"
#include <string>
#include <iterator>
#include <list>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;


/**
 * Обрабатывает список, применяя заданную функцию к каждой строке
 * 
 * @param txt текст
 * @param process функция-обработчик
 * @returns none
 */
void process_forward(
    text txt,
    void (*process)(int index, std::string contents, int cursor, void *data),
    void *data
)
{   
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->strs.size() == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    } 
    
    /* Стартуем с начальной строки текста */
    std::list<std::string>::iterator current;
    int index = 0;
    int cursor_position = -1;
    
    /* К каждой строке текста применяем обработчик */
    for( current = txt->strs.begin(); current != txt->strs.end(); current++)
	{
		if (txt->cursor->line == current) 
		{
            		cursor_position = txt->cursor->position;
		}
        	else
            		cursor_position = -1;
            string s = *(current);
        	process(index, s, cursor_position, data);
               	index++;
	}
}



