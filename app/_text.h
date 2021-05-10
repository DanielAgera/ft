/**
 * _text.h -- внутренние структуры представления текста
 * 
 * Этот файл не должен включаться в клиентские модули
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef _TEXT_H
#define _TEXT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <string>
#include <list>
#include <iterator>
#include "text.h"
#include <iostream>



/**
 * @struct 
 * @brief Представление курсора
 * 
 */
struct _crsr {
    std::list<std::string>::iterator line;;         /**< указатель на строку с курсором */
    int position;               					/**< позиция курсора в строке */
};


/**
 * @struct 
 * @brief Линейный двунаправленный список строк текста
 * 
 */
struct _list {
    
    std::list<std::string> strs;        /**< лист из контейнера list */
    struct _crsr *cursor;      			/**< позиция в тексте, курсор */
};


typedef struct _list *text;

#endif
