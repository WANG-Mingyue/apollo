/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "cyber/croutine/routine_context.h"

namespace apollo {
namespace cyber {
namespace croutine {

void MakeContext(const func &f1, const void *arg, RoutineContext *ctx) {
  char *sp = ctx->stack + STACK_SIZE - 2 * sizeof(void *);
  *reinterpret_cast<void **>(sp) = reinterpret_cast<void *>(f1);
  sp -= sizeof(void *);
  *reinterpret_cast<void **>(sp) = const_cast<void *>(arg);
  ctx->sp = ctx->stack + STACK_SIZE - 2 * sizeof(void *) - REGISTERS_SIZE;
}

}  // namespace croutine
}  // namespace cyber
}  // namespace apollo
