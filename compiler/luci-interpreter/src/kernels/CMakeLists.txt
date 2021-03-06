nnas_find_package(TensorFlowSource EXACT 2.1.0 QUIET)
nnas_find_package(TensorFlowGEMMLowpSource EXACT 2.1.0 QUIET)
nnas_find_package(TensorFlowEigenSource EXACT 2.1.0 QUIET)
find_package(Threads REQUIRED)
nnas_find_package(GTest REQUIRED)

if (NOT TensorFlowSource_FOUND OR
    NOT TensorFlowGEMMLowpSource_FOUND OR
    NOT TensorFlowEigenSource_FOUND)
  return()
endif ()

set(SOURCES
    Add.h
    Add.cpp
    ArgMax.h
    ArgMax.cpp
    AveragePool2D.h
    AveragePool2D.cpp
    Concatenation.h
    Concatenation.cpp
    Conv2D.h
    Conv2D.cpp
    DepthwiseConv2D.h
    DepthwiseConv2D.cpp
    Elu.h
    Elu.cpp
    FullyConnected.h
    FullyConnected.cpp
    L2Normalize.h
    L2Normalize.cpp
    L2Pool2D.h
    L2Pool2D.cpp
    LeakyRelu.h
    LeakyRelu.cpp
    LocalResponseNormalization.h
    LocalResponseNormalization.cpp
    Logistic.h
    Logistic.cpp
    MaxPool2D.h
    MaxPool2D.cpp
    Mean.h
    Mean.cpp
    Mul.h
    Mul.cpp
    Pad.h
    Pad.cpp
    Reshape.h
    Reshape.cpp
    Softmax.h
    Softmax.cpp
    Split.h
    Split.cpp
    Transpose.h
    Transpose.cpp
    TransposeConv.h
    TransposeConv.cpp
    Unpack.h
    Unpack.cpp)

list(APPEND SOURCES Utils.h Utils.cpp)

add_library(luci_interpreter_kernels STATIC ${SOURCES})
set_target_properties(luci_interpreter_kernels PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_include_directories(luci_interpreter_kernels PUBLIC ${LUCI_INTERPRETER_SOURCE_DIR})
target_include_directories(luci_interpreter_kernels SYSTEM PRIVATE
    "${TensorFlowGEMMLowpSource_DIR}"
    "${TensorFlowEigenSource_DIR}"
    "${TensorFlowSource_DIR}")
target_link_libraries(luci_interpreter_kernels
    PUBLIC luci_interpreter_core
    PRIVATE nncc_common Threads::Threads)


set(TEST_SOURCES
    Add.test.cpp
    ArgMax.test.cpp
    AveragePool2D.test.cpp
    Concatenation.test.cpp
    Conv2D.test.cpp
    DepthwiseConv2D.test.cpp
    Elu.test.cpp
    FullyConnected.test.cpp
    L2Normalize.test.cpp
    L2Pool2D.test.cpp
    LeakyRelu.test.cpp
    LocalResponseNormalization.test.cpp
    Logistic.test.cpp
    MaxPool2D.test.cpp
    Mean.test.cpp
    Mul.test.cpp
    Pad.test.cpp
    Reshape.test.cpp
    Softmax.test.cpp
    Split.test.cpp
    Transpose.test.cpp
    TransposeConv.test.cpp
    Unpack.test.cpp)

list(APPEND TEST_SOURCES TestUtils.h TestUtils.cpp)

GTest_AddTest(luci_interpreter_kernels_test ${TEST_SOURCES})
target_link_libraries(luci_interpreter_kernels_test luci_interpreter_kernels)
