#ifndef _CMDOPTIONBINDT_CC_H_
#define _CMDOPTIONBINDT_CC_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/*
 * CmdOptionBindT_CC.h
 *
 *  Created on: 2012-01-18
 *      Author: OWenT
 *
 * 自由函数绑定器
 */

namespace copt
{
    // 绑定器集合
    namespace binder {
        // ============================
        // ===       函数绑定       ===
        // ============================

        template<typename _TF>
        class CmdOptionBindCCCaller
        {
        private:
            _TF m_fFunc;

        public:
            CmdOptionBindCCCaller(_TF f) : m_fFunc(f){}

            template<typename _TCBP>
            void operator()(_TCBP& args)
            {
                m_fFunc(args);
            }

            template<typename _TCBP, typename _Arg0>
            void operator()(_TCBP& args, _Arg0& arg0)
            {
                m_fFunc(args, arg0);
            }

            template<typename _TCBP, typename _Arg0, typename _Arg1>
            void operator()(_TCBP& args, _Arg0& arg0, _Arg1& arg1)
            {
                m_fFunc(args, arg0, arg1);
            }

            template<typename _TCBP, typename _Arg0, typename _Arg1, typename _Arg2>
            void operator()(_TCBP& args, _Arg0& arg0, _Arg1& arg1, _Arg2& arg2)
            {
                m_fFunc(args, arg0, arg1, arg2);
            }

        };
    }
}
#endif /* CmdOptionBindCCCaller */
