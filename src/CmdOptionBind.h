#ifndef _CMDOPTIONBIND_H_
#define _CMDOPTIONBIND_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/*
 * CmdOptionBind.h
 *
 *  Created on: 2011-12-29
 *      Author: OWenT
 *
 * 应用程序命令处理
 * 绑定器模板（处理所有绑定的函数和类成员函数）
 */

#include "CmdOptionBindT_CC.h"
#include "CmdOptionBindT_MF_CC.h"

namespace copt
{
    // 标准指令处理函数(无返回值，参数为选项的映射表)
    // void function_name (CmdOptionList&, [参数]); // 函数参数可选
    // void function_name (callback_param, [参数]); // 函数参数可选

    enum CmdOptionChar 
    {
        SPLITCHAR = 0x0001,     // (第一位)分隔符
        STRINGSYM = 0x0002,     // (第二位)字符串开闭符
        TRANSLATE = 0x0004,     // (第三位)转义字符
        CMDSPLIT  = 0x0008,     // (第四位)指令分隔符
    };
}
#endif /* _CMDOPTIONBIND_H_ */
