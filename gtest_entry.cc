#include <gtest/gtest.h>
#include <string>
#include <stdio.h>
extern std::string Walktober(std::string str);

#define ABORT_EQ(in, exp, msg)              \
    if (in == exp)                          \
    {                                       \
        perror(msg);                        \
        ::testing::KilledBySignal(SIGABRT); \
    }

#define ABORT_NEQ(in, exp, msg)             \
    if (in != exp)                          \
    {                                       \
        perror(msg);                        \
        ::testing::KilledBySignal(SIGABRT); \
    }

char *get_file_content(const char *fname)
{
    auto fptr = fopen(fname, "r");
    ABORT_EQ(fptr, NULL, "[failed to open testcase]")
    ABORT_EQ(fseek(fptr, 0, SEEK_END), -1, "[failed to seek to the end]")
    auto fsize = ftell(fptr);
    ABORT_EQ(fsize, -1, "[failed to get filesize]")
    ABORT_EQ(fseek(fptr, 0, SEEK_SET), -1, "[failed to reset file ptr]");
    char *buf = new char[fsize];
    ABORT_EQ(buf, nullptr, "[failed allocate buffer]");
    fread(buf, fsize, 1, fptr);
    ABORT_NEQ(ferror(fptr), 0, "[fread error]")
    return buf;
}

TEST(basic_test, sampletest1)
{
    auto input = get_file_content("../test_data/sample_test_set_1/sample_ts1_input.txt");
    auto output = get_file_content("../test_data/sample_test_set_1/sample_ts1_output.txt");

    delete[] input;
    delete[] output;
}
TEST(basic_test, sampletest2)
{
    auto input = get_file_content("../test_data/sample_test_set_2/sample_ts2_input.txt");
    auto output = get_file_content("../test_data/sample_test_set_2/sample_ts2_output.txt");

    delete[] input;
    delete[] output;
}

TEST(correctness_test, test1)
{
    auto input = get_file_content("../test_data/test_set_1/ts1_input.txt");
    auto output = get_file_content("../test_data/test_set_1/ts1_output.txt");

    delete[] input;
    delete[] output;
}
TEST(correctness_test, test2)
{
    auto input = get_file_content("../test_data/test_set_2/ts2_input.txt");
    auto output = get_file_content("../test_data/test_set_2/ts2_output.txt");

    delete[] input;
    delete[] output;
}

TEST(pressure_test, test1)
{
    auto input = get_file_content("../test_data/test_set_1/ts1_input.txt");
    auto output = get_file_content("../test_data/test_set_1/ts1_output.txt");

    delete[] input;
    delete[] output;
}
TEST(pressure_test, test2)
{
    auto input = get_file_content("../test_data/test_set_2/ts2_input.txt");
    auto output = get_file_content("../test_data/test_set_2/ts2_output.txt");

    delete[] input;
    delete[] output;
}
int main(int argc, char const *argv[])
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
