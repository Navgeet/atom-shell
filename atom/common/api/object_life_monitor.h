// Copyright (c) 2013 GitHub, Inc. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef ATOM_COMMON_API_OBJECT_LIFE_MONITOR_H_
#define ATOM_COMMON_API_OBJECT_LIFE_MONITOR_H_

#include "base/basictypes.h"
#include "native_mate/scoped_persistent.h"

namespace atom {

class ObjectLifeMonitor {
 public:
  static void BindTo(v8::Handle<v8::Object> target,
                     v8::Handle<v8::Value> destructor);

 private:
  ObjectLifeMonitor();

  static void WeakCallback(v8::Isolate* isolate,
                           v8::Persistent<v8::Object>* value,
                           ObjectLifeMonitor* self);

  mate::ScopedPersistent<v8::Object> handle_;

  DISALLOW_COPY_AND_ASSIGN(ObjectLifeMonitor);
};

}  // namespace atom

#endif  // ATOM_COMMON_API_OBJECT_LIFE_MONITOR_H_
