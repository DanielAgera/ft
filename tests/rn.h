#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "common.h"
#include "text.h"
#include "_text.h"


TEST(rn, normal)
{
    std::string output_text = "";

    text txt = create_text();

    txt->strs.push_back("Hello world1");
    txt->strs.push_back("Hello world2");
    txt->strs.push_back("Hello world3");

    output_text += "Hello world1";
    output_text += "Hello world2" ;


    //захват вывода
    testing::internal::CaptureStdout();

    rn(txt, 2);

    show(txt);

    std::string text = testing::internal::GetCapturedStdout();



    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}
TEST(rn,  negative)
{
    std::string output_text = "";

    text txt = create_text();

    txt->strs.push_back("Hello world1");
    txt->strs.push_back("Hello world2");
    txt->strs.push_back("Hello world3");

    output_text += "Hello world1";
    output_text += "Hello world2";
    output_text += "Hello world3";

    //захват вывода
    testing::internal::CaptureStdout();

    rn(txt, 100);

    show(txt);

    std::string text = testing::internal::GetCapturedStdout();



    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}
TEST(rn,  negative2)
{
    std::string output_text = "";

    text txt = create_text();

    txt->strs.push_back("Hello world1");
    txt->strs.push_back("Hello world2");
    txt->strs.push_back("Hello world3");

    output_text += "Hello world1";
    output_text += "Hello world2";
    output_text += "Hello world3";

    //захват вывода
    testing::internal::CaptureStdout();

    rn(txt, -100);

    show(txt);

    std::string text = testing::internal::GetCapturedStdout();



    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}
