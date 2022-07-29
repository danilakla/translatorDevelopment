#pragma once

#include "stdafx.h"
#include "Parm.h"
#include "Error.h"

namespace Parm
{
    PARM getparm(int argc, wchar_t* argv[]) {
        PARM parm;

        for (int i = 1; i < argc; i++) {
            if (wcslen(argv[i]) > PARM_MAX_SIZE)
                throw ERROR_THROW(104);

            if (wcsstr(argv[i], PARM_IN)) {
                wcscpy_s(parm.in, argv[i] + wcslen(PARM_IN));
                parm.in_found = 1;
            }

            if (wcsstr(argv[i], PARM_OUT)) {
                wcscpy_s(parm.out, argv[i] + wcslen(PARM_OUT));
                parm.out_found = 1;
            }

            if (wcsstr(argv[i], PARM_LOG)) {
                wcscpy_s(parm.log, argv[i] + wcslen(PARM_LOG));
                parm.log_found = 1;
            }
        }

        if (!parm.in_found) throw ERROR_THROW(100);

        if (!parm.out_found) {
            wcscpy_s(parm.out, parm.in);
            wcscat_s(parm.out, PARM_OUT_DEFAULT_EXIT);
        }

        if (!parm.log_found) {
            wcscpy_s(parm.log, parm.in);
            wcscat_s(parm.log, PARM_LOG_DEFAULT_EXIT);
        }
        return parm;
    }
}