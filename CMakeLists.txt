cmake_minimum_required(VERSION 3.9)
project(macondo_sha256 C)

set(CMAKE_C_STANDARD 99)

link_libraries(crypto)
link_libraries(ssl)

add_executable(macondo_sha256 main.c sha256.c sha256.h hex.c hex.h pow.c pow.h)

target_link_libraries(macondo_sha256 m)