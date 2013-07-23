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

#include "CmdOptionBindTBase.h"

namespace copt
{
    // 绑定器集合
    namespace binder {

        // ============================
        // ===        类绑定        ===
        // ============================

        template<typename _T>
        class CmdOptionBindMFParamList0
        {
        private:
            _T& m_tInstance;

        public:
            CmdOptionBindMFParamList0(_T& tIns): m_tInstance(tIns){}

            template<class _F> 
            void operator()(_F& f, callback_param args, int)
            {
                (m_tInstance.*f)(args);
            }
        };

        template<typename _T, typename _Arg0>
        class CmdOptionBindMFParamList1
        {
        private:
            _T& m_tInstance;
            _Arg0 m_tArg0;

        public:
            CmdOptionBindMFParamList1(_T& tIns, _Arg0 arg0): m_tInstance(tIns), m_tArg0(arg0){}

            template<class _F> 
            void operator()(_F& f, callback_param args, int)
            {
                (m_tInstance.*f)(args, m_tArg0);
            }
        };

        template<typename _T, typename _Arg0, typename _Arg1>
        class CmdOptionBindMFParamList2
        {
        private:
            _T& m_tInstance;
            _Arg0 m_tArg0;
            _Arg1 m_tArg1;

        public:
            CmdOptionBindMFParamList2(_T& tIns, _Arg0 arg0, _Arg1 arg1):
                m_tInstance(tIns), m_tArg0(arg0), m_tArg1(arg1){}

            template<class _F> 
            void operator()(_F& f, callback_param args, int)
            {
                (m_tInstance.*f)(args, m_tArg0, m_tArg1);
            }
        };

        template<typename _T, typename _Arg0, typename _Arg1, typename _Arg2>
        class CmdOptionBindMFParamList3
        {
        private:
            _T& m_tInstance;
            _Arg0 m_tArg0;
            _Arg1 m_tArg1;
            _Arg2 m_tArg2;

        public:
            CmdOptionBindMFParamList3(_T& tIns, _Arg0 arg0, _Arg1 arg1, _Arg2 arg2):
                m_tInstance(tIns), m_tArg0(arg0), m_tArg1(arg1), m_tArg2(arg2){}

            template<class _F> 
            void operator()(_F& f, callback_param args, int)
            {
                (m_tInstance.*f)(args, m_tArg0, m_tArg1, m_tArg2);
            }
        };
    }
}
#endif /* _CMDOPTIONBIND_H_ */
