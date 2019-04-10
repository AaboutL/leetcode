
FILE(GLOB HEADERS include/*.h)
FILE(GLOB SOURCE src/*.cc)

add_library(core STATIC
        ${HEADERS}
        ${SOURCE})

target_include_directories(core PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

