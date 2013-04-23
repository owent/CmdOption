#ifndef _CMDOPTIONVALUE_H_
#define _CMDOPTIONVALUE_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/*
 * CmdOptionValue.h
 *
 *  Created on: 2011-12-29
 *      Author: owentou(欧文韬)
 *
 * 应用程序命令处理
 *
 */

#include <stdint.h>
#include <string>
#include <sstream>
#include "smart_ptr.h"

namespace copt
{
    class CmdOptionValue
    {
    protected:
        std::string m_strData;

        template<typename _Tt>
        inline _Tt string2any(const char* strData) const
        {
            _Tt ret;
            std::stringstream stStream;
            stStream.str(strData);
            stStream>> ret;
            return ret;
        }
    public:
        CmdOptionValue(const char* strData);

        template<typename _Tt>
        inline _Tt As() const
        {
            return string2any<_Tt>(m_strData.c_str());
        }

        // 获取存储对象的字符串
        const std::string& AsCppString() const;

        char AsChar() const;

        short AsShort() const;

        int AsInt() const;

        long AsLong() const;

        long long AsLongLong() const;

        double AsDouble() const;

        float AsFloat() const;

        const char* AsString() const;

        unsigned char AsUChar() const;

        unsigned short AsUShort() const;

        unsigned int AsUInt() const;

        unsigned long AsULong() const;

        unsigned long long AsULongLong() const;

        int8_t AsInt8() const;

        uint8_t AsUInt8() const;

        int16_t AsInt16() const;

        uint16_t AsUInt16() const;

        int32_t AsInt32() const;

        uint32_t AsUInt32() const;

        int64_t AsInt64() const;

        uint64_t AsUInt64() const;
    };
}

#endif /* _CMDOPTIONVALUE_H_ */
