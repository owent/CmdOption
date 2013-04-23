#ifndef _CMDOPTIONBINDT_CC_H_
#define _CMDOPTIONBINDT_CC_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/*
 * CmdOptionBindT_CC.h
 *
 *  Created on: 2012-01-18
 *      Author: owentou(欧文韬)
 *
 * 自由函数绑定器
 */

#include "CmdOptionBindTBase.h"

namespace copt
{
    // 绑定器集合
    namespace binder {
        // ============================
        // ===       函数绑定       ===
        // ============================

        class CmdOptionBindParamList0
        {
        public:
            template<class _F> 
            void operator()(_F& f, callback_param args, int)
            {
                f(args);
            }
        };

        template<typename _Arg0>
        class CmdOptionBindParamList1
        {
        private:
            _Arg0 m_tArg0;

        public:
            CmdOptionBindParamList1(_Arg0 arg0): m_tArg0(arg0){}

            template<class _F> 
            void operator()(_F& f, callback_param args, int)
            {
                f(args, m_tArg0);
            }
        };

        template<typename _Arg0, typename _Arg1>
        class CmdOptionBindParamList2
        {
        private:
            _Arg0 m_tArg0;
            _Arg1 m_tArg1;

        public:
            CmdOptionBindParamList2(_Arg0 arg0, _Arg1 arg1): 
                m_tArg0(arg0), m_tArg1(arg1){}

            template<class _F> 
            void operator()(_F& f, callback_param args, int)
            {
                f(args, m_tArg0, m_tArg1);
            }
        };

        template<typename _Arg0, typename _Arg1, typename _Arg2>
        class CmdOptionBindParamList3
        {
        private:
            _Arg0 m_tArg0;
            _Arg1 m_tArg1;
            _Arg2 m_tArg2;

        public:
            CmdOptionBindParamList3(_Arg0 arg0, _Arg1 arg1, _Arg2 arg2):
                m_tArg0(arg0), m_tArg1(arg1), m_tArg2(arg2){}

            template<class _F> 
            void operator()(_F& f, callback_param args, int)
            {
                f(args, m_tArg0, m_tArg1, m_tArg2);
            }
        };
    }
}
#endif /* _CMDOPTIONBIND_H_ */
