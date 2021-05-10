
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>


using namespace std;

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(save, lines)
{
    text txt = create_text();

    append_line(txt, "Hello world1\n");
    append_line(txt, "Hello world2\n");
    append_line(txt, "Hello world3\n");

    save(txt, "save.test.txt");

    text txt2 = create_text();

    load(txt2, "save.test.txt");

    EXPECT_EQ(txt->strs.size(), txt2->strs.size());

    string* txt_arr = new string[txt->strs.size()];
    string* txt2_arr = new string[txt2->strs.size()] ;

    copy(txt->strs.begin(), txt->strs.end(), txt_arr);
    copy(txt2->strs.begin(), txt2->strs.end(), txt2_arr);

    for(unsigned int i = 0; i < txt->strs.size(); i++)
        EXPECT_STREQ(txt_arr[i].c_str(), txt2_arr[i].c_str());

    free(txt);
    free(txt2);
}
TEST(save, empty_file)
{
    text txt = create_text();

    save(txt, "save.test.txt");

    text txt2 = create_text();
    load(txt2, "save.test.txt");

    EXPECT_EQ(txt->strs.size(), txt2->strs.size());

    string* txt_arr = new string[txt->strs.size()];
    string* txt2_arr = new string[txt2->strs.size()];

    copy(txt->strs.begin(), txt->strs.end(), txt_arr);
    copy(txt2->strs.begin(), txt2->strs.end(), txt2_arr);

    for(unsigned int i = 0; i < txt->strs.size(); i++)
        EXPECT_STREQ(txt_arr[i].c_str(), txt2_arr[i].c_str());

    free(txt);
    free(txt2);
}
