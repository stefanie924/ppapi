// Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef PPAPI_C_PPB_FILE_SYSTEM_H_
#define PPAPI_C_PPB_FILE_SYSTEM_H_

#include "ppapi/c/pp_resource.h"

typedef struct _pp_CompletionCallback PP_CompletionCallback;
typedef struct _pp_FileInfo PP_FileInfo;

#define PPB_FILESYSTEM_INTERFACE "PPB_FileSystem;1"

typedef struct _ppb_FileSystem {
  // Makes a new directory in the filesystem as well as any parent directories
  // if the make_ancestors parameter is true.  It is not valid to make a
  // directory in the external filesystem.  Fails if the directory already
  // exists or if ancestor directories do not exist and make_ancestors was not
  // passed as true.
  int32_t (*MakeDirectory)(PP_Resource directory_ref,
                           bool make_ancestors,
                           PP_CompletionCallback callback);
 
  // Queries info about the file.  You must have read access to this file if it
  // exists in the external filesystem.
  int32_t (*Query)(PP_Resource file_ref,
                   PP_FileInfo* info,
                   PP_CompletionCallback callback);
 
  // Updates timestamps for a file.  You must have write access to the file if
  // it exists in the external filesystem.
  int32_t (*Touch)(PP_Resource file_ref,
                   PP_Time last_access_time,
                   PP_Time last_modified_time,
                   PP_CompletionCallback callback);
 
  // Delete a file or directory.  If file_ref refers to a directory, then the
  // directory must be empty.  It is an error to delete a file or directory
  // that is in use.  It is not valid to delete a file in the external
  // filesystem.
  int32_t (*Delete)(PP_Resource file_ref,
                    PP_CompletionCallback callback);
 
  // Rename a file or directory.  file_ref and new_file_ref must both refer to
  // files in the same filesystem.  It is an error to rename a file or
  // directory that is in use.  It is not valid to rename a file in the
  // external filesystem.
  int32_t (*Rename)(PP_Resource file_ref,
                    PP_Resource new_file_ref,
                    PP_CompletionCallback callback);
} PPB_FileSystem;

#endif  // PPAPI_C_PPB_FILE_SYSTEM_H_
