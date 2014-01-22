/*
* CmdOptionValue.cpp
*
*  Created on: 2011-12-29
*      Author: OWenT
*
* 应用程序命令处理
*
*/


#include "CmdOptionValue.h"

namespace copt
{
    CmdOptionValue::CmdOptionValue(const char* strData): m_strData(strData)
    {
    }

    const std::string& CmdOptionValue::AsCppString() const
    {
        return m_strData;
    }

    char CmdOptionValue::AsChar() const
    {
        return As<char>();
    }

    short CmdOptionValue::AsShort() const
    {
        return As<short>();
    }

    int CmdOptionValue::AsInt() const
    {
        return As<int>();
    }

    long CmdOptionValue::AsLong() const
    {
        return As<long>();
    }

    long long CmdOptionValue::AsLongLong() const
    {
        return As<long long>();
    }

    double CmdOptionValue::AsDouble() const
    {
        return As<double>();
    }

    float CmdOptionValue::AsFloat() const
    {
        return As<float>();
    }

    const char* CmdOptionValue::AsString() const
    {
        return m_strData.c_str();
    }

    // ============ unsigned ============
    unsigned char CmdOptionValue::AsUChar() const
    {
        return As<unsigned char>();
    }

    unsigned short CmdOptionValue::AsUShort() const
    {
        return As<unsigned short>();
    }

    unsigned int CmdOptionValue::AsUInt() const
    {
        return As<unsigned int>();
    }

    unsigned long CmdOptionValue::AsULong() const
    {
        return As<unsigned long>();
    }

    unsigned long long CmdOptionValue::AsULongLong() const
    {
        return As<unsigned long long>();
    }

    int8_t CmdOptionValue::AsInt8() const
    {
        return static_cast<int8_t>(AsInt());
    }

    uint8_t CmdOptionValue::AsUInt8() const
    {
        return static_cast<uint8_t>(AsUInt());
    }

    int16_t CmdOptionValue::AsInt16() const
    {
        return As<int16_t>();
    }

    uint16_t CmdOptionValue::AsUInt16() const
    {
        return As<uint16_t>();
    }

    int32_t CmdOptionValue::AsInt32() const
    {
        return As<int32_t>();
    }

    uint32_t CmdOptionValue::AsUInt32() const
    {
        return As<uint32_t>();
    }

    int64_t CmdOptionValue::AsInt64() const
    {
        return As<int64_t>();
    }

    uint64_t CmdOptionValue::AsUInt64() const
    {
        return As<uint64_t>();
    }
}

