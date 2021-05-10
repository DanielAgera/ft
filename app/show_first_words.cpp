#include <stdio.h>
#include <assert.h>
#include "common.h"
#include <string.h>
#include "text.h"

static void showf_words(int index, std::string contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void showfirstwords(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, showf_words, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void showf_words(int index, std::string contents, int cursor, void *data)
{
        /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);
    

    int i;

    for(  i = 0; contents[i] == ' '; i++){
        ;
    }

    while((contents[i] != ' ')  && (contents[i] != '\0')){
        
        printf("%c", contents[i]);
        
        i++;
    }

}

//static void show_line(int index, std::string contents, int cursor, void *data);

//**
// * Выводит содержимое указанного файла на экран
// */
//void show(text txt)
//{
//    /* Применяем функцию show_line к каждой строке текста */
//    process_forward(txt, show_line, NULL);
//}

//**
// * Выводит содержимое указанного файла на экран
// */
//static void show_line(int index, std::string contents, int cursor, void *data)
//{
//    /* Функция обработчик всегда получает существующую строку */


//    /* Декларируем неиспользуемые параметры */
//    UNUSED(index);
//    UNUSED(data);

//    /* Выводим строку на экран */
//    if(cursor != -1) {
//        printf("%.*s|%.*s", cursor, contents.c_str(),(int) contents.length() - cursor, contents.c_str() + cursor);
//    } else {
//        printf("%s", contents.c_str());
//    }
//}
