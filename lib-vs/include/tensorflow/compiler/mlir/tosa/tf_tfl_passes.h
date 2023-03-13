/* Copyright 2021 The TensorFlow Authors. All Rights Reserved.

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

#ifndef TENSORFLOW_COMPILER_MLIR_TOSA_TF_TFL_PASSES_H
#define TENSORFLOW_COMPILER_MLIR_TOSA_TF_TFL_PASSES_H

#include "mlir/Pass/PassManager.h"  // from @llvm-project
#include "mlir/Pass/PassOptions.h"  // from @llvm-project

namespace mlir {
namespace tosa {

struct TOSATFTFLLegalizationPipelineOptions
    : public PassPipelineOptions<TOSATFTFLLegalizationPipelineOptions> {};

// Legalizes TF dialect(s) to Tosa.
void createTFTFLtoTOSALegalizationPipeline(
    OpPassManager& pm, const TOSATFTFLLegalizationPipelineOptions& opts);

void registerTFTFLtoTOSALegalizationPipeline();

}  // namespace tosa
}  // namespace mlir

#endif  // TENSORFLOW_COMPILER_MLIR_TOSA_TF_TFL_PASSES_H
