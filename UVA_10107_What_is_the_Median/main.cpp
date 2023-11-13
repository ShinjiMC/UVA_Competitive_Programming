#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <sstream>
#include "code.hpp"
namespace
{
    void runTestCase(const std::string &input_data, const std::string &expected_output)
    {
        std::istringstream input_stream(input_data);                            // Crear stream de entrada con datos simulados
        std::streambuf *original_cin = std::cin.rdbuf(input_stream.rdbuf());    // Redirigir la entrada estándar a nuestro stream de entrada simulado
        std::stringstream output_stream;                                        // Capturar la salida estándar
        std::streambuf *original_cout = std::cout.rdbuf(output_stream.rdbuf()); // Redirigir la salida estándar a nuestro stream de salida capturado
        ASSERT_NO_FATAL_FAILURE(mediam());
        // Restaurar la entrada y salida estándar originales
        std::cin.rdbuf(original_cin);
        std::cout.rdbuf(original_cout);
        // Comparar la salida capturada con la salida esperada
        ASSERT_EQ(output_stream.str(), expected_output);
    }
    TEST(RunCodeTest, Tests)
    {
        ASSERT_NO_FATAL_FAILURE(runTestCase("1 3 4 60 70 50 2", "1\n2\n3\n3\n4\n27\n4\n"));
        ASSERT_NO_FATAL_FAILURE(runTestCase("5 8 12 15 20", "5\n6\n8\n10\n12\n"));
        ASSERT_NO_FATAL_FAILURE(runTestCase("10 9 8 7 6", "10\n9\n9\n8\n8\n"));
        ASSERT_NO_FATAL_FAILURE(runTestCase("100 200 150 120 180", "100\n150\n150\n135\n150\n"));
        ASSERT_NO_FATAL_FAILURE(runTestCase("3 3 3 3 3", "3\n3\n3\n3\n3\n"));
    }

    TEST(RunCodeTest, EmptyInput)
    {
        ASSERT_NO_FATAL_FAILURE(runTestCase("", ""));
        ASSERT_NO_FATAL_FAILURE(runTestCase(" ", ""));
    }

    TEST(RunCodeTest, DuplicateElements)
    {
        ASSERT_NO_FATAL_FAILURE(runTestCase("5 5 5 5 5", "5\n5\n5\n5\n5\n"));
        ASSERT_NO_FATAL_FAILURE(runTestCase("2 2 2 2 2 2 2", "2\n2\n2\n2\n2\n2\n2\n"));
    }

    TEST(RunCodeTest, LargerInput)
    {
        ASSERT_NO_FATAL_FAILURE(runTestCase("10 20 30 40 50 60 70 80 90", "10\n15\n20\n25\n30\n35\n40\n45\n50\n"));
        ASSERT_NO_FATAL_FAILURE(runTestCase("1 2 3 4 5 6 7 8 9 10 11 12 13 14 15", "1\n1\n2\n2\n3\n3\n4\n4\n5\n5\n6\n6\n7\n7\n8\n"));
        ASSERT_NO_FATAL_FAILURE(runTestCase("1000 500 750 250 125 375", "1000\n750\n750\n625\n500\n437\n"));
        ASSERT_NO_FATAL_FAILURE(runTestCase("100 200 300 400 500 600 700 800 900", "100\n150\n200\n250\n300\n350\n400\n450\n500\n"));
    }
} // namespace
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}