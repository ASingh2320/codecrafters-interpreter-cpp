#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::string read_file_contents(const std::string &filename);

int main(int argc, char *argv[])
{
    // Disable output buffering
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    // You can use print statements as follows for debugging, they'll be visible when running tests.
    // std::cerr << "Logs from your program will appear here!" << std::endl;

    if (argc < 3)
    {
        std::cerr << "Usage: ./your_program tokenize <filename>" << std::endl;
        return 1;
    }

    const std::string command = argv[1];

    int code = 0;

    if (command == "tokenize")
    {
        std::string file_contents = read_file_contents(argv[2]);

        bool saw_equal = false;
        bool saw_bang = false;

        for (char &token : file_contents)
        {
            if (saw_equal)
            {
                saw_equal = false;
                if (token == '=')
                {
                    std::cout << "EQUAL_EQUAL == null\n";
                    continue;
                }
                std::cout << "EQUAL = null\n";
            }
            if (saw_bang)
            {
                saw_bang = false;
                if (token == '=')
                {
                    std::cout << "BANG_EQUAL != null\n";
                    continue;
                }
                std::cout << "BANG ! null\n";
            }
            switch (token)
            {
            case '=':
                saw_equal = true;
                break;
            case '!':
                saw_bang = true;
                break;
            case '(':
                std::cout << "LEFT_PAREN ( null\n";
                break;
            case '{':
                std::cout << "LEFT_BRACE { null\n";
                break;
            case '}':
                std::cout << "RIGHT_BRACE } null\n";
                break;
            case ')':
                std::cout << "RIGHT_PAREN ) null\n";
                break;
            case ',':
                std::cout << "COMMA , null\n";
                break;
            case '.':
                std::cout << "DOT . null\n";
                break;
            case '-':
                std::cout << "MINUS - null\n";
                break;
            case '+':
                std::cout << "PLUS + null\n";
                break;
            case ';':
                std::cout << "SEMICOLON ; null\n";
                break;
            case '*':
                std::cout << "STAR * null\n";
                break;
            default:
                code = 65;
                std::cerr << "[line 1] Error: Unexpected character: " << token << "\n";
            }
        }
        if (saw_equal)
        {
            std::cout << "EQUAL = null\n";
        }
        if (saw_bang)
        {
            std::cout << "BANG ! null\n";
        }
        std::cout << "EOF  null" << std::endl; // Placeholder, remove this line when implementing the scanner
    }
    else
    {
        std::cerr << "Unknown command: " << command << std::endl;
        return 1;
    }

    return code;
}

std::string read_file_contents(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error reading file: " << filename << std::endl;
        std::exit(1);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
}
