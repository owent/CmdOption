#ifndef _CMDOPTIONBINDPARAMLIST_H_
#define _CMDOPTIONBINDPARAMLIST_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/*
 * CmdOptionBindParamList.h
 *
 *  Created on: 2014-01-22
 *      Author: OWenT
 *
 * 绑定器参数列表类
 */

#include "CmdOptionBindT_CC.h"
#include "CmdOptionBindT_MF_CC.h"

namespace copt
{
    namespace binder {

        /**
        *  Maps member pointers into instances of _Mem_fn but leaves all
        *  primary template handles the non--member-pointer case.
        */
        template<typename _Tp>
        struct MaybeWrapMemberPointer
        {
            typedef _Tp type;
            typedef CmdOptionBindCCCaller<_Tp> caller_type;

            static const _Tp& DoWrap(const _Tp& __x) {
                return __x;
            }

            static _Tp& DoWrap(_Tp& __x) {
                return __x;
            }
        };


        /**
        *  Maps member pointers into instances of _Mem_fn but leaves all
        *  partial specialization handles the member pointer case.
        */
        template<typename _Tp, typename _Class>
        struct MaybeWrapMemberPointer<_Tp _Class::*>
        {
            typedef _Tp _Class::* type;
            typedef CmdOptionBindMFCCCaller<_Class, type> caller_type;

            static type DoWrap(_Tp _Class::* __pm) {
                return type(__pm);
            }
        };

        // ============================
        // ===       参数列表       ===
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
            CmdOptionBindParamList1(_Arg0 arg0) : m_tArg0(arg0){}

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
            CmdOptionBindParamList2(_Arg0 arg0, _Arg1 arg1) :
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
            CmdOptionBindParamList3(_Arg0 arg0, _Arg1 arg1, _Arg2 arg2) :
                m_tArg0(arg0), m_tArg1(arg1), m_tArg2(arg2){}

            template<class _F>
            void operator()(_F& f, callback_param args, int)
            {
                f(args, m_tArg0, m_tArg1, m_tArg2);
            }
        };

        template<typename _Arg0, typename _Arg1, typename _Arg2, typename _Arg3>
        class CmdOptionBindParamList4
        {
        private:
            _Arg0 m_tArg0;
            _Arg1 m_tArg1;
            _Arg2 m_tArg2;
            _Arg2 m_tArg3;

        public:
            CmdOptionBindParamList4(_Arg0 arg0, _Arg1 arg1, _Arg2 arg2, _Arg2 arg3) :
                m_tArg0(arg0), m_tArg1(arg1), m_tArg2(arg2), m_tArg3(arg3){}

            template<class _F>
            void operator()(_F& f, callback_param args, int)
            {
                f(args, m_tArg0, m_tArg1, m_tArg2, m_tArg3);
            }
        };

    }
}
#endif /* _CMDOPTIONBINDPARAMLIST_H_ */
