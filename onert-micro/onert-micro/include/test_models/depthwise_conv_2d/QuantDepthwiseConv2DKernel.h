/*
 * Copyright (c) 2024 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ONERT_MICRO_TEST_MODELS_DEPTHWISE_CONV_2D_KERNEL_QUANT_H
#define ONERT_MICRO_TEST_MODELS_DEPTHWISE_CONV_2D_KERNEL_QUANT_H

#include "TestDataDepthwiseConv2DBase.h"

namespace onert_micro
{
namespace test_model
{
namespace depthwiseconv2d_int8
{

/*
 * DepthwiseConv2D Kernel:
 *
 * Input(1, 5, 5, 3)-Int8   Weight(1, 3, 3, 3) -Int8   Bias(3)-Int32
 *              \            |             /
 *               \           |            /
 *                    DepthwiseConv2D
 *                           |
 *                    Output(1, 5, 5, 3)-Int8
 */
const unsigned char test_kernel_model_circle[] = {
  0x1c, 0x00, 0x00, 0x00, 0x43, 0x49, 0x52, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00,
  0x14, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x08, 0x00, 0x10, 0x00, 0x04, 0x00, 0x0e, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x50, 0x03, 0x00, 0x00, 0x6c, 0x03, 0x00, 0x00,
  0x05, 0x00, 0x00, 0x00, 0x68, 0x00, 0x00, 0x00, 0x5c, 0x00, 0x00, 0x00, 0x54, 0x00, 0x00, 0x00,
  0x28, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xe6, 0xff, 0xff, 0xff, 0x04, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0x00, 0x00, 0x06, 0x00, 0x08, 0x00, 0x04, 0x00, 0x06, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x1b, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x00, 0x00,
  0xf8, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x18, 0x00, 0x14, 0x00,
  0x10, 0x00, 0x0c, 0x00, 0x08, 0x00, 0x04, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x1c, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x14, 0x00, 0x00, 0x00, 0x10, 0x00, 0x0c, 0x00,
  0x07, 0x00, 0x08, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x18, 0x00, 0x00, 0x00,
  0x24, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x10, 0x00, 0x00, 0x00, 0x0c, 0x00,
  0x08, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0xac, 0x01, 0x00, 0x00, 0x04, 0x01, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x72, 0xfe, 0xff, 0xff, 0x14, 0x00, 0x00, 0x00, 0x4c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x09, 0x48, 0x00, 0x00, 0x00, 0x64, 0xfe, 0xff, 0xff, 0x30, 0x00, 0x00, 0x00,
  0x24, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0xba, 0xc0, 0xc0, 0x3c, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x6f, 0x66, 0x6d, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0xe2, 0xfe, 0xff, 0xff, 0x14, 0x00, 0x00, 0x00, 0x5c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x02, 0x5c, 0x00, 0x00, 0x00, 0xd4, 0xfe, 0xff, 0xff, 0x44, 0x00, 0x00, 0x00,
  0x3c, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0xee, 0x25, 0x2a, 0x25, 0xbb, 0x32, 0x04, 0x38, 0xbe, 0x1f, 0xb9, 0x37, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x62, 0x69, 0x61, 0x73, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x1a, 0x00, 0x14, 0x00,
  0x13, 0x00, 0x0c, 0x00, 0x08, 0x00, 0x04, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00,
  0x70, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x6c, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x12, 0x00, 0x18, 0x00, 0x04, 0x00, 0x08, 0x00, 0x0c, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x14, 0x00, 0x12, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00,
  0x28, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0xdf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x7b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x43, 0x37, 0x0b, 0x3e,
  0xea, 0x15, 0x60, 0x3c, 0xb5, 0x15, 0xab, 0x3d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x6b, 0x65, 0x72, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00,
  0x18, 0x00, 0x14, 0x00, 0x13, 0x00, 0x0c, 0x00, 0x08, 0x00, 0x04, 0x00, 0x0e, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x00, 0x00, 0x58, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09,
  0x54, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x14, 0x00, 0x04, 0x00, 0x08, 0x00, 0x0c, 0x00, 0x10, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xba, 0xc0, 0xc0, 0x3c, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xc0, 0x40, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x69, 0x66, 0x6d, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00,
  0x05, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x0c, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x11, 0x00, 0x00, 0x00, 0x4f, 0x4e, 0x45, 0x2d,
  0x74, 0x66, 0x6c, 0x69, 0x74, 0x65, 0x32, 0x63, 0x69, 0x72, 0x63, 0x6c, 0x65, 0x00, 0x00, 0x00};

const std::vector<int8_t> input_data = {
  -5, 43, -44, 2,   -13, -22, -28, -27, -34, 35,  -37, -47, -22, 49,  -36, 0,   -9,  9,  45,
  20, 28, 43,  32,  -30, 5,   5,   23,  0,   -16, -24, -18, -21, 38,  5,   -40, -12, 6,  -36,
  4,  4,  -14, -22, 42,  39,  -8,  -16, 47,  19,  -3,  -20, -38, -4,  23,  13,  -26, 46, -36,
  -4, -4, -31, 46,  -44, -44, 21,  11,  48,  1,   -38, 17,  -42, -29, 3,   8,   -32, -41};

const std::vector<int8_t> reference_output_data = {
  6, 0,  -2, 6,  -1, -3, 1,  0,  -4, 0,  0, -3,  0,  1,  0,  1, 0,  2,  1, 1, -3, 0,  1,  2, 10,
  0, -2, -5, 0,  0,  -1, 0,  -1, -1, -1, 0, -10, -1, -2, -7, 0, -1, -1, 1, 0, 3,  1,  -3, 3, 0,
  1, -7, 1,  -3, 0,  1,  -3, -1, 0,  0,  0, -1,  4,  2,  0,  1, 0,  -1, 0, 1, 0,  -4, 4,  0, 0};

} // namespace depthwiseconv2d_int8

class TestDataInt8DepthwiseConv2D : public TestDataDepthwiseConv2DBase<int8_t>
{
public:
  TestDataInt8DepthwiseConv2D()
  {
    _input_data = depthwiseconv2d_int8::input_data;
    _reference_output_data = depthwiseconv2d_int8::reference_output_data;
    _test_kernel_model_circle = depthwiseconv2d_int8::test_kernel_model_circle;
  }

  ~TestDataInt8DepthwiseConv2D() override = default;
};

} // namespace test_model
} // namespace onert_micro

#endif // ONERT_MICRO_TEST_MODELS_DEPTHWISE_CONV_2D_KERNEL_QUANT_H
