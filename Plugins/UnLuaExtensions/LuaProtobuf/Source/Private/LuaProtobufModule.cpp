// Tencent is pleased to support the open source community by making UnLua available.
// 
// Copyright (C) 2019 THL A29 Limited, a Tencent company. All rights reserved.
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

#include "LuaProtobufModule.h"
#include "LuaEnv.h"
#include "pb.h"

// �����ⲿ C ������������ Lua �����д� Protobuf ��
extern "C" int luaopen_pb(lua_State* L);
extern "C" int luaopen_pb_unsafe(lua_State* L);

// ģ����������
void FLuaProtobufModule::StartupModule()
{
    // ע�ᾲ̬���� OnLuaEnvCreated���� Lua ��������ʱ����
    UnLua::FLuaEnv::OnCreated.AddStatic(&FLuaProtobufModule::OnLuaEnvCreated);
}

// ģ��رպ���
void FLuaProtobufModule::ShutdownModule()
{
    // �Ƴ������뵱ǰģ����ص� Lua ���������¼�
    UnLua::FLuaEnv::OnCreated.RemoveAll(this);
}

// Lua ���������ص�����
void FLuaProtobufModule::OnLuaEnvCreated(UnLua::FLuaEnv& Env)
{
    // �� Lua ������������ü����� "pb" �� "pb.unsafe"
    Env.AddBuiltInLoader(TEXT("pb"), luaopen_pb);
    Env.AddBuiltInLoader(TEXT("pb.unsafe"), luaopen_pb_unsafe);
    // ���� Lua �ű�������·��
    Env.DoString("UnLua.PackagePath = UnLua.PackagePath .. ';/Plugins/UnLuaExtensions/LuaProtobuf/Content/Script/?.lua'");
}

// ģ��ʵ�ֺ꣬ʹ�������ܹ�ʶ��ͼ��ظ�ģ��
IMPLEMENT_MODULE(FLuaProtobufModule, LuaProtobuf)