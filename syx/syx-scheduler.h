/* 
   Copyright (c) 2007-2008 Luca Bruno

   This file is part of Smalltalk YX.

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell   
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:
   
   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.
   
   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER    
   DEALINGS IN THE SOFTWARE.
*/

#ifndef SYX_SCHEDULER_H
#define SYX_SCHEDULER_H

#include "syx-platform.h"
#include "syx-types.h"
#include "syx-object.h"

#include <stdio.h>

SYX_BEGIN_DECLS

EXPORT SyxOop syx_processor;
EXPORT SyxOop *_syx_processor_first_process;
EXPORT SyxOop *_syx_processor_active_process;
EXPORT SyxOop *_syx_processor_byteslice;

typedef struct SyxSchedulerPoll SyxSchedulerPoll;

/*! Each scheduler poll is a linked list which nodes contain a file descriptor and a Semaphore. */
struct SyxSchedulerPoll
{
  /*! File descriptor to wait for reading or writing */
  syx_nint fd;
  /*! Semaphore to signal once ready to read or write */
  SyxOop semaphore;
  SyxSchedulerPoll *next;
};

typedef syx_bool (* SyxSchedulerSourceFunc) (void);

EXPORT void syx_scheduler_init (void);
EXPORT syx_bool syx_scheduler_iterate (void);
EXPORT void syx_scheduler_run (void);
EXPORT void syx_scheduler_quit (void);

EXPORT syx_bool syx_scheduler_add_process (SyxOop process);
EXPORT syx_bool syx_scheduler_remove_process (SyxOop process);

EXPORT void syx_scheduler_poll_read_register (syx_nint fd, SyxOop semaphore);
EXPORT void syx_scheduler_poll_write_register (syx_nint fd, SyxOop semaphore);
EXPORT void syx_scheduler_poll_register_source (SyxSchedulerSourceFunc callback, SyxOop semaphore);
EXPORT void syx_scheduler_poll_unregister_source (SyxSchedulerSourceFunc callback, SyxOop semaphore);

/*! Get the byteslice */
#define syx_processor_byteslice (*_syx_processor_byteslice)

/*! Get the active process running on */
#define syx_processor_active_process (*_syx_processor_active_process)


/*! This is used internally */
EXPORT void _syx_scheduler_save (FILE *image);
EXPORT void _syx_scheduler_load (FILE *image);

SYX_END_DECLS

#endif /* SYX_SCHEDULER_H */
