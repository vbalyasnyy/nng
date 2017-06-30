//
// Copyright 2017 Garrett D'Amore <garrett@damore.org>
//
// This software is supplied under the terms of the MIT License, a
// copy of which should be located in the distribution where this
// file was obtained (LICENSE.txt).  A copy of the license may also be
// found online at https://opensource.org/licenses/MIT.
//

#ifndef PLATFORM_POSIX_AIO_H
#define PLATFORM_POSIX_AIO_H

// This file defines structures we will use for emulating asynchronous I/O
// on POSIX.  POSIX lacks the support for callback based asynchronous I/O
// that we have on Windows, although it has a non-widely support aio layer
// that is not very performant on many systems.   So we emulate this using
// one of several possible different backends.

#include "core/nng_impl.h"


typedef struct nni_posix_pipedesc	nni_posix_pipedesc;
typedef struct nni_posix_epdesc		nni_posix_epdesc;

extern int nni_posix_pipedesc_sysinit(void);
extern void nni_posix_pipedesc_sysfini(void);
extern int nni_posix_pipedesc_init(nni_posix_pipedesc **, int);
extern void nni_posix_pipedesc_fini(nni_posix_pipedesc *);
extern void nni_posix_pipedesc_read(nni_posix_pipedesc *, nni_aio *);
extern void nni_posix_pipedesc_write(nni_posix_pipedesc *, nni_aio *);
extern void nni_posix_pipedesc_close(nni_posix_pipedesc *);

#endif // PLATFORM_POSIX_AIO_H
