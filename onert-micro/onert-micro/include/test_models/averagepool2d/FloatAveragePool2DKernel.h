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

#ifndef ONERT_MICRO_TEST_MODELS_FLOAT_AVERAGEPOOL2D_KERNEL_H
#define ONERT_MICRO_TEST_MODELS_FLOAT_AVERAGEPOOL2D_KERNEL_H

#include "TestDataAveragePool2DBase.h"

namespace onert_micro
{
namespace test_model
{
namespace averagepool2d_float
{
/*
 * averagepool2d Kernel:
 *
 *      Input(1, 8, 8, 1)
 *            |
 *      AveragePool2D
 *            |
 *      Output(1, 7, 7, 1)
 */
const unsigned char test_kernel_model_circle[] = {
  0x18, 0x00, 0x00, 0x00, 0x43, 0x49, 0x52, 0x30, 0x00, 0x00, 0x0e, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x08, 0x00, 0x10, 0x00, 0x04, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x2c, 0x00, 0x00, 0x00, 0x48, 0x01, 0x00, 0x00, 0x64, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x18, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff,
  0xfc, 0xff, 0xff, 0xff, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x18, 0x00, 0x14, 0x00, 0x10, 0x00, 0x0c, 0x00,
  0x08, 0x00, 0x04, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00,
  0x7c, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x84, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x0e, 0x00, 0x16, 0x00, 0x00, 0x00, 0x10, 0x00, 0x0c, 0x00, 0x07, 0x00, 0x08, 0x00,
  0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x1c, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00,
  0x34, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x18, 0x00, 0x17, 0x00, 0x10, 0x00, 0x0c, 0x00,
  0x08, 0x00, 0x04, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x40, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xd4, 0xff, 0xff, 0xff, 0x0c, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x6f, 0x66, 0x6d, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x10, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x08, 0x00, 0x04, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x69, 0x66, 0x6d, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x00, 0x00, 0x00,
  0x4f, 0x4e, 0x45, 0x2d, 0x74, 0x66, 0x6c, 0x69, 0x74, 0x65, 0x32, 0x63, 0x69, 0x72, 0x63, 0x6c,
  0x65, 0x00, 0x00, 0x00};

const std::vector<float> input_data = {
  12.10053719, 7.72285052,  9.68137431,  11.75806343, 13.15526008, 8.84076114,  3.89649012,
  5.08537657,  5.83701651,  6.76013136,  12.7101313,  12.78361385, 9.54081657,  13.08970747,
  5.33034769,  8.86342716,  13.01502028, 9.97710148,  6.87673408,  2.52509585,  1.54685839,
  3.8311655,   11.54457301, 5.35917021,  4.56748259,  9.03648093,  8.39788966,  6.45449342,
  1.51089027,  7.12564391,  10.90150032, 5.39767168,  8.99330195,  5.60324272,  12.0761712,
  1.60046693,  11.42969327, 7.53880683,  1.14423351,  6.36556104,  10.32055668, 11.55385514,
  8.57127856,  3.37820787,  1.64478344,  12.19396693, 8.30985251,  3.69866267,  3.78378227,
  1.86568852,  7.82041004,  4.8020888,   4.41597821,  6.58942329,  6.68898032,  8.79502599,
  7.55499098,  5.02695743,  8.41237828,  10.76109451, 9.11473488,  6.82893955,  10.6362216,
  9.19960882};
const std::vector<float> reference_output_data{
  8.105134,  9.218622, 11.733296, 11.809439, 11.156636, 7.789326,  5.79391,   8.897317,  9.081025,
  8.723894,  6.599096, 7.0021367, 8.448948,  7.7743797, 9.149021,  8.572052,  6.063554,  3.0093343,
  3.5036395, 8.35072,  8.300729,  7.0501275, 8.778446,  7.1322556, 5.248886,  6.9012585, 6.6775465,
  5.9522414, 9.11774,  9.451137,  6.4065313, 4.5132875, 8.201813,  7.296715,  4.8795776, 6.880971,
  7.452808,  6.142997, 3.5602646, 6.2110386, 8.445556,  6.87313,   4.5578547, 5.7813587, 7.9489927,
  7.2734737, 6.737269, 7.685891,  8.829959};

} // namespace averagepool2d_float

class TestDataFloatAveragePool2D : public TestDataAveragePool2DBase<float>
{
public:
  TestDataFloatAveragePool2D()
  {
    _input_data = averagepool2d_float::input_data;
    _reference_output_data = averagepool2d_float::reference_output_data;
    _test_kernel_model_circle = averagepool2d_float::test_kernel_model_circle;
  }

  ~TestDataFloatAveragePool2D() override = default;
};

} // namespace test_model
} // namespace onert_micro

#endif // ONERT_MICRO_TEST_MODELS_FLOAT_AVERAGEPOOL2D_KERNEL_H
