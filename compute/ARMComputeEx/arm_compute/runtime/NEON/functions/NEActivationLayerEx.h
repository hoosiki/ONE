/*
 * Copyright (c) 2020 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Copyright (c) 2017-2019 ARM Limited.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __ARM_COMPUTE_NEACTIVATIONLAYEREX_H__
#define __ARM_COMPUTE_NEACTIVATIONLAYEREX_H__

#include "arm_compute/runtime/NEON/INESimpleFunctionNoBorder.h"

#include "arm_compute/core/Types.h"

namespace arm_compute
{
// Forward declarations
class ITensor;

/** Basic function to run @ref NEActivationLayerKernelEx
 *
 * @note The function simulates an activation layer with the specified activation function.
 */
class NEActivationLayerEx : public INESimpleFunctionNoBorder
{
public:
  /** Constructor
   *
   * @param[in] ctx Runtime context to be used by the function
   */
  NEActivationLayerEx(IRuntimeContext *ctx = nullptr);
  /** Prevent instances of this class from being copied (As this class contains pointers) */
  NEActivationLayerEx(const NEActivationLayerEx &) = delete;
  /** Default move constructor */
  NEActivationLayerEx(NEActivationLayerEx &&) = default;
  /** Prevent instances of this class from being copied (As this class contains pointers) */
  NEActivationLayerEx &operator=(const NEActivationLayerEx &) = delete;
  /** Default move assignment operator */
  NEActivationLayerEx &operator=(NEActivationLayerEx &&) = default;
  /** [NEActivationLayerEx snippet] **/
  /** Set the input and output tensor.
   *
   * @note If the output tensor is a nullptr or is equal to the input, the activation function will
   * be performed in-place
   *
   * @param[in, out] input           Source tensor. In case of @p output tensor = nullptr, this
   * tensor will store the result
   *                                 of the activation function. Data types supported:
   * QASYMM8/QSYMM16/F16/F32.
   * @param[out]     output          Destination tensor. Data type supported: same as @p input
   * @param[in]      activation_info Activation layer parameters.
   */
  void configure(ITensor *input, ITensor *output, ActivationLayerInfo activation_info);
  /** [NEActivationLayerEx snippet] **/
  /** Static function to check if given info will lead to a valid configuration of @ref
   * NEActivationLayerEx
   *
   * @param[in] input    Source tensor info. In case of @p output tensor info = nullptr, this tensor
   * will store the result
   *                     of the activation function. Data types supported: QASYMM8/QSYMM16/F16/F32.
   * @param[in] output   Destination tensor info. Data type supported: same as @p input
   * @param[in] act_info Activation layer information.
   *
   * @return a status
   */
  static Status validate(const ITensorInfo *input, const ITensorInfo *output,
                         const ActivationLayerInfo &act_info);
};
} // namespace arm_compute
#endif /* __ARM_COMPUTE_NEACTIVATIONLAYEREX_H__ */
