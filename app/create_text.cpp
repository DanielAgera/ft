/**
 * create_text.c -- создает в памяти структуры для представления текста
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Создает новый текстовый объект
 * @returns текст
 */
text create_text()
{  
    text txt;

    /* Создаем структуру описания текста */
    if ((txt = (_list *) malloc(sizeof(_list))) == NULL) 
    {
        fprintf(stderr, "Not enough memory!\n");
        exit(EXIT_FAILURE);
    }
    
    txt = new _list;
    
    /* Создаем структуру описания курсора */
    if ((txt->cursor = (_crsr *) malloc(sizeof(_crsr))) == NULL) 
    {
        fprintf(stderr, "Not enough memory!\n");
        exit(EXIT_FAILURE);
    }    

    txt->strs = std::list<std::string>();
    

    txt->cursor->line = txt->strs.end();
    txt->cursor->position = 0;
	
    return txt;
}
