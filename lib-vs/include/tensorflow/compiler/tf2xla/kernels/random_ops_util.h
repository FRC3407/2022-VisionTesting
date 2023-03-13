/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_COMPILER_TF2XLA_KERNELS_RANDOM_OPS_UTIL_H_
#define TENSORFLOW_COMPILER_TF2XLA_KERNELS_RANDOM_OPS_UTIL_H_

#include <cmath>

#include "tensorflow/compiler/xla/client/xla_builder.h"
#include "tensorflow/core/framework/tensor.h"

namespace tensorflow {
// Returns a tensor containing 'shape' random values uniformly distributed in
// the range [minval, maxval). The raw random bits are generated by the given
// `bit_generator` and converted to the requested data type and range. This
// routine requires 2 32-bit integer seeds and currently only supports 'shape's
// of type F32, S32 and S64.
xla::XlaOp StatelessRngUniform(absl::string_view device_type_string,
                               xla::XlaOp seeds, const xla::Shape& shape,
                               xla::XlaOp minval, xla::XlaOp maxval);

// Converts to bfloat16 if `dtype` equals DT_BFLOAT16, no-op otherwise.
// It masks the last 16 bit. With normal rounding, values near "maxval" would be
// converted to "maxval" which is out of range ["minval", "maxval"). In
// addition, the distribution near the limit is not uniform.
xla::XlaOp MaybeConvertF32ToBF16(xla::XlaOp input, DataType dtype);

// Combines two signed 32-bit seeds into a single unsigned 64 bit seed.
xla::XlaOp GetU64FromS32Seeds(xla::XlaOp seed0, xla::XlaOp seed1);

}  // namespace tensorflow

#endif  // TENSORFLOW_COMPILER_TF2XLA_KERNELS_RANDOM_OPS_UTIL_H_
