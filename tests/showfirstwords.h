#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(show_first, normal)
{
    std::string output_text = "";

    text txt = create_text();

    txt->strs.push_back("Hello world1");
    txt->strs.push_back("Hello world2");
    txt->strs.push_back("Hello world3");

    output_text += "Hello";
    output_text += "Hello" ;
    output_text += "Hello" ;

    //захват вывода
    testing::internal::CaptureStdout();

    showfirstwords(txt);



    std::string text = testing::internal::GetCapturedStdout();



    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);



}
TEST(show_first, negative)
{
    std::string output_text = "";

    text txt = create_text();

    txt->strs.push_back("");
    txt->strs.push_back("");
    txt->strs.push_back("");

    output_text += "";
    output_text += "" ;
    output_text += "" ;

    //захват вывода
    testing::internal::CaptureStdout();

    showfirstwords(txt);



    std::string text = testing::internal::GetCapturedStdout();



    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);



}
