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

#include <syx/syx.h>
#include <readline/readline.h>
#include <readline/history.h>

SYX_FUNC_PRIMITIVE(Readline_readline)
{
  SyxOop string;
  SYX_PRIM_ARGS(1);
  char *s = readline (SYX_OBJECT_STRING(es->message_arguments[0]));
  string = syx_string_new_ref (s);
  SYX_PRIM_RETURN(string);
}

SYX_FUNC_PRIMITIVE(Readline_addHistory)
{
  SYX_PRIM_ARGS(1);
  if (SYX_IS_NIL (es->message_arguments[0]))
    {
      SYX_PRIM_RETURN(es->message_receiver);
    }
  add_history (SYX_OBJECT_STRING(es->message_arguments[0]));
  SYX_PRIM_RETURN(es->message_receiver);
}

syx_bool
syx_plugin_initialize (void)
{
  static syx_bool _syx_readline_initialized = FALSE;
  syx_symbol *filename;
  syx_string full_filename;
  static syx_symbol gtk_filenames[] = {
    "Readline.st",
    NULL
  };

  if (_syx_readline_initialized)
    return TRUE;

  _syx_readline_initialized = TRUE;

  for (filename = gtk_filenames; *filename; filename++)
    {
      full_filename = syx_find_file ("st", "readline", *filename);
      syx_file_in_blocking (full_filename);
      syx_free (full_filename);
    }

  using_history ();
  return TRUE;
}

void
syx_plugin_finalize (void)
{
  clear_history ();
}
