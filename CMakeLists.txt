cmake_minimum_required(VERSION 3.25)
project(Pipex C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Pipex
        #learning/initial_pipe.c
        learning/test_header.c learning/working_path.c
        libft/ft_strncmp.c libft/ft_split.c libft/ft_substr.c libft/ft_strlen.c
        libft/ft_substr.c src/pipex.c src/pipex_utils.c src/path_utils.c)
