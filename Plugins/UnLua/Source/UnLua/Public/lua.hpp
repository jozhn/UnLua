// Tencent is pleased to support the open source community by making UnLua available.
// 
// Copyright (C) 2019 Tencent. All rights reserved.
//
// Licensed under the MIT License (the "License"); 
// you may not use this file except in compliance with the License. You may obtain a copy of the License at
//
// http://opensource.org/licenses/MIT
//
// Unless required by applicable law or agreed to in writing, 
// software distributed under the License is distributed on an "AS IS" BASIS, 
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
// See the License for the specific language governing permissions and limitations under the License.

#pragma once

// Save UE's TString macro to avoid conflict with Lua's TString struct
#ifdef TString
#pragma push_macro("TString")
#undef TString
#define UNLUA_TSTRING_PUSHED
#endif

#ifdef __cplusplus
#if !LUA_COMPILE_AS_CPP
extern "C" {
#endif
#endif

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#ifdef __cplusplus
#if !LUA_COMPILE_AS_CPP
}
#endif
#endif

// Restore UE's TString macro
#ifdef UNLUA_TSTRING_PUSHED
#pragma pop_macro("TString")
#undef UNLUA_TSTRING_PUSHED
#endif
