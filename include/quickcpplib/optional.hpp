/* optional support
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (3 commits)
File Created: Jul 2017


Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License in the accompanying file
Licence.txt or at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.


Distributed under the Boost Software License, Version 1.0.
    (See accompanying file Licence.txt or copy at
          http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QUICKCPPLIB_OPTIONAL_HPP
#define QUICKCPPLIB_OPTIONAL_HPP

#include "config.hpp"

#include "cpp_feature.h"

#if !defined(QUICKCPPLIB_USE_STD_OPTIONAL)
#if _HAS_CXX17 ||                                                                                                      \
(__cplusplus >= 201700 && (!defined(__APPLE__) || _LIBCPP_VERSION > 7000 /* approx end of 2017 */)) ||                 \
!defined(__cpp_exceptions)
#define QUICKCPPLIB_USE_STD_OPTIONAL 1
#else
#define QUICKCPPLIB_USE_STD_OPTIONAL 0
#endif
#endif

#if QUICKCPPLIB_USE_STD_OPTIONAL

#include <optional>

QUICKCPPLIB_NAMESPACE_BEGIN

namespace optional
{
  template <class T> using optional = std::optional<T>;
}

QUICKCPPLIB_NAMESPACE_END

#else  // ^^^ QUICKCPPLIB_USE_STD_OPTIONAL / not QUICKCPPLIB_USE_STD_OPTIONAL vvv

#if !defined(__cpp_exceptions)
#error                                                                                                                 \
"Our <optional> polyfill requires C++ exceptions globally enabled. Try increasing C++ standard to 2017 or higher to enable std <optional>"
#endif

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4702)  // unreachable code
#endif
#include "optional/optional.hpp"
#ifdef _MSC_VER
#pragma warning(pop)
#endif

QUICKCPPLIB_NAMESPACE_BEGIN

namespace optional
{
  template <class T> using optional = std::experimental::optional<T>;
}

QUICKCPPLIB_NAMESPACE_END

#endif  // ^^^ not QUICKCPPLIB_USE_STD_OPTIONAL ^^^

#endif
