#ifndef _CMDOPTIONBINDTBASE_H_
#define _CMDOPTIONBINDTBASE_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/*
 * CmdOptionBindTBase.h
 *
 *  Created on: 2012-01-18
 *      Author: OWenT
 *
 * 绑定器基类及公共定义
 */

#include "CmdOptionList.h"

namespace copt
{
    // 标准指令处理函数参数类型
    
    // 标准指令处理函数(无返回值，参数为选项的映射表)
    // void function_name (CmdOptionList&, [参数]); // 函数参数可选
    // void function_name (callback_param, [参数]); // 函数参数可选

    // 绑定器集合
    namespace binder {
        // 函数、函数结构绑定器
        template<class _R, class _F, class _PL> 
        class CmdOptionBindT : public CmdOptionBindBase
        {
        protected:
            _F m_fFuncObj;      // 函数结构
            _PL m_stParamList;   // 参数列表结构

        public:
            typedef CmdOptionBindT this_type;

            CmdOptionBindT(_F f, _PL l): m_fFuncObj(f), m_stParamList(l) {}

            void operator()(callback_param args)
            {
                m_stParamList(m_fFuncObj, args, 0);
            }                      
        };

    }
}
#endif /* _CMDOPTIONBIND_H_ */
