cmake_minimum_required(VERSION 3.26)
project(proj1_submission C)

set(CMAKE_C_STANDARD 11)

add_executable(proj1_submission

        Node/Node.c
        lex.yy.c
        syntax.tab.c
        main.c)
