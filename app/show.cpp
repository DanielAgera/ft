/**
 * show.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include <string.h>
#include "text.h"

static void show_line(int index, std::string contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_line(int index, std::string contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);
    
    /* Выводим строку на экран */
    if(cursor != -1) {
        printf("%.*s|%.*s", cursor, contents.c_str(),(int) contents.length() - cursor, contents.c_str() + cursor);
    } else {
        printf("%s", contents.c_str());
    }
}
