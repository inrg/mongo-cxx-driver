// Copyright 2014 MongoDB Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <mongo/driver/config/prelude.hpp>

#include <mongo/driver/cursor.hpp>
#include <mongo/driver/private/libmongoc.hpp>

namespace mongo {
namespace driver {

class cursor::impl {

   public:
    impl(mongoc_cursor_t* cursor)
        : cursor_t(cursor)
    {}

    ~impl() {
        libmongoc::cursor_destroy(cursor_t);
    }

    mongoc_cursor_t* cursor_t;

}; // class impl

}  // namespace driver
}  // namespace mongo

#include <mongo/driver/config/postlude.hpp>
