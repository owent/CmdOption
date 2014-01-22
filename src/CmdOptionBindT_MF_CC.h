#ifndef _CMDOPTIONBINDT_MF_CC_H_
#define _CMDOPTIONBINDT_MF_CC_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/*
 * CmdOptionBindT_MF_CC.h
 *
 *  Created on: 2012-01-18
 *      Author: OWenT
 *
 * 成员函数绑定器
 */

namespace copt
{
    // 绑定器集合
    namespace binder {

        // ============================
        // ===        类绑定        ===
        // ============================

        template<typename _T, typename _F>
        class CmdOptionBindMFCCCaller
        {
        private:
            _F m_fMemFunc;

        public:
            CmdOptionBindMFCCCaller(_F f) : m_fMemFunc(f){}

            template<typename _TCBP>
            void operator()(_TCBP& args, _T* arg0)
            {
                (arg0->*m_fMemFunc)(args);
            }

            template<typename _TCBP>
            void operator()(_TCBP& args, _T& arg0)
            {
                (arg0.*m_fMemFunc)(args);
            }

            template<typename _TCBP, typename _Arg1>
            void operator()(_TCBP& args, _T* arg0, _Arg1& arg1)
            {
                (arg0->*m_fMemFunc)(args, arg1);
            }

            template<typename _TCBP, typename _Arg1>
            void operator()(_TCBP& args, _T& arg0, _Arg1& arg1)
            {
                (arg0.*m_fMemFunc)(args, arg1);
            }

            template<typename _TCBP, typename _Arg1, typename _Arg2>
            void operator()(_TCBP& args, _T* arg0, _Arg1& arg1, _Arg2& arg2)
            {
                (arg0->*m_fMemFunc)(args, arg1, arg2);
            }

            template<typename _TCBP, typename _Arg1, typename _Arg2>
            void operator()(_TCBP& args, _T& arg0, _Arg1& arg1, _Arg2& arg2)
            {
                (arg0.*m_fMemFunc)(args, arg1, arg2);
            }

            template<typename _TCBP, typename _Arg1, typename _Arg2, typename _Arg3>
            void operator()(_TCBP& args, _T* arg0, _Arg1& arg1, _Arg2& arg2, _Arg3& arg3)
            {
                (arg0->*m_fMemFunc)(args, arg1, arg2, arg3);
            }

            template<typename _TCBP, typename _Arg1, typename _Arg2, typename _Arg3>
            void operator()(_TCBP& args, _T& arg0, _Arg1& arg1, _Arg2& arg2, _Arg3& arg3)
            {
                (arg0.*m_fMemFunc)(args, arg1, arg2, arg3);
            }

        };
    }
}
#endif /* _CMDOPTIONBINDT_MF_CC_H_ */
