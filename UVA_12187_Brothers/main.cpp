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
        ASSERT_NO_FATAL_FAILURE(runTestCase("3 4 4 3\n0 1 2 0\n1 0 2 0\n0 1 2 0\n0 1 2 2\n4 2 3 4\n1 0 3\n2 1 2\n8 4 2 1\n0 7\n1 6\n2 5\n3 4\n0 0 0 0\n",
                                            "2 2 2 0\n2 1 0 1\n2 2 2 0\n0 2 0 0\n1 0 3\n2 1 2\n7 6\n0 5\n1 4\n2 3\n"));
    }
} // namespace
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}