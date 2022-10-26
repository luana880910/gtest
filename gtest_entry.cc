#include <gtest/gtest.h>
#include <string>
#include <stdio.h>
extern std::string Curling(std::string str);

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

long get_file_content(const char* fname, char **buf_ptr)
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
    *buf_ptr = buf;
    return fsize;
}

TEST(basic_test, sampletest1) {
    char *input, *output;
    long input_len, output_len = 0;
    input_len = get_file_content("../test_data/sample_test_set_1/sample_ts1_input.txt" , &input);
    output_len = get_file_content("../test_data/sample_test_set_1/sample_ts1_output.txt", &output);

    auto str_in = std::string(input, input_len);
    auto str_out = std::string(output, output_len);

    delete [] input;
    delete [] output;

    auto p_out = Curling(str_in);

    EXPECT_STREQ(p_out.c_str(), str_out.c_str());
}


TEST(basic_test, sampletest2) {
    char *input, *output;
    long input_len, output_len = 0;
    input_len = get_file_content("../test_data/sample_test_set_2/sample_ts2_input.txt" , &input);
    output_len = get_file_content("../test_data/sample_test_set_2/sample_ts2_output.txt", &output);

    auto str_in = std::string(input, input_len);
    auto str_out = std::string(output, output_len);

    delete [] input;
    delete [] output;

    auto p_out = Curling(str_in);

    EXPECT_STREQ(p_out.c_str(), str_out.c_str());
}


TEST(correctness_pressure_test, test1) {
    char *input, *output;
    long input_len, output_len = 0;
    input_len = get_file_content("../test_data/test_set_1/ts1_input.txt" , &input);
    output_len = get_file_content("../test_data/test_set_1/ts1_output.txt", &output);

    auto str_in = std::string(input, input_len);
    auto str_out = std::string(output, output_len);

    delete [] input;
    delete [] output;

    auto p_out = Curling(str_in);

    EXPECT_STREQ(p_out.c_str(), str_out.c_str());
}

TEST(correctness_pressure_test, test2) {
    char *input, *output;
    long input_len, output_len = 0;
    input_len = get_file_content("../test_data/test_set_2/ts2_input.txt" , &input);
    output_len = get_file_content("../test_data/test_set_2/ts2_output.txt", &output);

    auto str_in = std::string(input, input_len);
    auto str_out = std::string(output, output_len);

    delete [] input;
    delete [] output;

    auto p_out = Curling(str_in);

    EXPECT_STREQ(p_out.c_str(), str_out.c_str());
}

int main(int argc, char const *argv[])
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
