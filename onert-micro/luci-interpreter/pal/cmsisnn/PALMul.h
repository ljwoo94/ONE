/*
 * Copyright (c) 2021 Samsung Electronics Co., Ltd. All Rights Reserved
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

#ifndef LUCI_INTERPRETER_PAL_MUL_H
#define LUCI_INTERPRETER_PAL_MUL_H

#include "PALMulCommon.h"
#include "arm_nnfunctions.h"

namespace luci_interpreter_pal
{

template <>
inline void Mul<int8_t>(const ArithmeticParams &params, const int flat_size,
                        const int8_t *input1_data, const int8_t *input2_data, int8_t *output_data)
{
  auto status = arm_elementwise_mul_s8(
    input1_data, input2_data, params.input1_offset, params.input2_offset, output_data,
    params.output_offset, params.output_multiplier, params.output_shift,
    params.quantized_activation_min, params.quantized_activation_max, flat_size);
  assert(status == ARM_CMSIS_NN_SUCCESS);
}

template <>
inline void Mul<int16_t>(const ArithmeticParams &params, const int flat_size,
                         const int16_t *input1_data, const int16_t *input2_data,
                         int16_t *output_data)
{
  auto status = arm_elementwise_mul_s16(
    input1_data, input2_data, params.input1_offset, params.input2_offset, output_data,
    params.output_offset, params.output_multiplier, params.output_shift,
    params.quantized_activation_min, params.quantized_activation_max, flat_size);
  assert(status == ARM_CMSIS_NN_SUCCESS);
}

} // namespace luci_interpreter_pal

#endif // LUCI_INTERPRETER_PAL_MUL_H
