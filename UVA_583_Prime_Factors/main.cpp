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
        ASSERT_NO_FATAL_FAILURE(code());
        // Restaurar la entrada y salida estándar originales
        std::cin.rdbuf(original_cin);
        std::cout.rdbuf(original_cout);
        // Comparar la salida capturada con la salida esperada
        ASSERT_EQ(output_stream.str(), expected_output);
    }
    TEST(RunCodeTest, Tests)
    {
        ASSERT_NO_FATAL_FAILURE(runTestCase("-190\n-191\n-192\n-193\n-194\n195\n196\n197\n198\n199\n200\n0\n", "-190 = -1 x 2 x 5 x 19\n-191 = -1 x 191\n-192 = -1 x 2 x 2 x 2 x 2 x 2 x 2 x 3\n-193 = -1 x 193\n-194 = -1 x 2 x 97\n195 = 3 x 5 x 13\n196 = 2 x 2 x 7 x 7\n197 = 197\n198 = 2 x 3 x 3 x 11\n199 = 199\n200 = 2 x 2 x 2 x 5 x 5\n"));
    }

    TEST(RunCodeTest, EmptyInput)
    {
        ASSERT_NO_FATAL_FAILURE(runTestCase("0", ""));
    }
} // namespace
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}