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
        ASSERT_NO_FATAL_FAILURE(runTestCase("5\nX...X ....X\n.X... ...X.\n...X. .X...\n..X.X ..X..\n....X XX..X\n6\n....XX X....X\n...X.. X.X...\nXX..X. .X..X.\n..X... ...X.X\n...X.. ..X...\n..X..X ..X...\n2\nX. X.\n.X .X\n4\n..X. ...X\nXX.. ....\n.... XX..\n...X ..X.\n5\nX.... .X...\n.X... ..X..\n.X... ..X..\n...X. ....X\n....X X....\n4\n.X.. ..X.\n.X.X X...\n.... ..XX\n..X. ....\n2\n.. XX\nXX ..\n",
                                            "Pattern 1 was rotated 90 degrees.\nPattern 2 was rotated 270 degrees.\nPattern 3 was preserved.\nPattern 4 was reflected vertically.\nPattern 5 was improperly transformed.\nPattern 6 was reflected vertically and rotated 270 degrees.\nPattern 7 was rotated 180 degrees.\n"));
    }
} // namespace
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}