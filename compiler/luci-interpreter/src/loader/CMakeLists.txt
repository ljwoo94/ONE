set(SOURCES
    GraphLoader.h
    GraphLoader.cpp
    KernelBuilderHelper.h
    KernelBuilderHelper.cpp
    KernelBuilder.h
    KernelBuilder.cpp
    ModuleLoader.h
    ModuleLoader.cpp
    RuntimeToIR.h
    nodes/Builders.h)

# include kernel specific builders
macro(REGISTER_KERNEL NODE)
  list(APPEND SOURCES "nodes/${NODE}.cpp")
endmacro(REGISTER_KERNEL)
include(${KERNEL_REGISTER_FILE})

add_library(${LUCI_INTERPRETER_LOADER} STATIC ${SOURCES})
if (NOT NNCC_LIBRARY_NO_PIC)
  set_target_properties(${LUCI_INTERPRETER_LOADER} PROPERTIES POSITION_INDEPENDENT_CODE ON)
endif(NOT NNCC_LIBRARY_NO_PIC)
target_include_directories(${LUCI_INTERPRETER_LOADER} PUBLIC "${LUCI_INTERPRETER_PAL_DIR}")
target_include_directories(${LUCI_INTERPRETER_LOADER} PUBLIC "${LUCI_INTERPRETER_SOURCE_DIR}")

target_link_libraries(${LUCI_INTERPRETER_LOADER}
        PUBLIC luci_lang ${LUCI_INTERPRETER_CORE}
        PRIVATE ${LUCI_INTERPRETER_KERNELS} nncc_common luci_plan)

if(NOT ENABLE_TEST)
  return()
endif(NOT ENABLE_TEST)

nnas_find_package(GTest REQUIRED)

set(TEST_SOURCES KernelBuilder.test.cpp)

GTest_AddTest(${LUCI_INTERPRETER_LOADER}_test ${TEST_SOURCES})
target_link_libraries(${LUCI_INTERPRETER_LOADER}_test ${LUCI_INTERPRETER_LOADER})
