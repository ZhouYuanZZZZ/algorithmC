cmake_minimum_required(VERSION 3.17)
project(c C)

set(CMAKE_C_STANDARD 99)

add_executable(c seq/seqList.c seq/linkList.c stack/seqStack.c stack/linkStack.c queue/seqQueue.c)
add_executable(c seq/seqList.c seq/linkList.c seq/seqStack.c seq/linkStack.c queue/circulQueue.c queue/linkQueue.c)