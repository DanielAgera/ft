/**
 * load.c -- функция загрузки текста из файла
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <string.h>
#include "common.h"
#include "text.h"
using namespace std;
/**
 * Загружает содержимое указанного файла
 */
void load(text txt, string filename)
{
     FILE *f;

    char buf[MAXLINE + 1];

    char str[100];
    strcpy(str, filename.c_str());

    /* Открываем файл для чтения, контролируя ошибки */
    if ((f = fopen(str, "r")) == NULL) {
        printf("The file cannot be opened\n");
        return;
    }
    /* Удаляем предыдущее содержимое */
    remove_all(txt);
    /* Считываем содержимое строка за строкой */
    while (fgets(buf, MAXLINE, f)) {

        append_line(txt, buf);
    }


    fclose(f);
}
