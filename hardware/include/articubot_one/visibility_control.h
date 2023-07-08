// Copyright 2021 ros2_control Development Team
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/* This header must be included by all rclcpp headers which declare symbols
 * which are defined in the rclcpp library. When not building the rclcpp
 * library, i.e. when using the headers in other package's code, the contents
 * of this header change the visibility of certain symbols which the rclcpp
 * library cannot have, but the consuming code must have inorder to link.
 */

#ifndef ARTICUBOT_ONE__VISIBILITY_CONTROL_H_
#define ARTICUBOT_ONE__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
#define ARTICUBOT_ONE_EXPORT __attribute__((dllexport))
#define ARTICUBOT_ONE_IMPORT __attribute__((dllimport))
#else
#define ARTICUBOT_ONE_EXPORT __declspec(dllexport)
#define ARTICUBOT_ONE_IMPORT __declspec(dllimport)
#endif
#ifdef ARTICUBOT_ONE_BUILDING_DLL
#define ARTICUBOT_ONE_PUBLIC ARTICUBOT_ONE_EXPORT
#else
#define ARTICUBOT_ONE_PUBLIC ARTICUBOT_ONE_IMPORT
#endif
#define ARTICUBOT_ONE_PUBLIC_TYPE ARTICUBOT_ONE_PUBLIC
#define ARTICUBOT_ONE_LOCAL
#else
#define ARTICUBOT_ONE_EXPORT __attribute__((visibility("default")))
#define ARTICUBOT_ONE_IMPORT
#if __GNUC__ >= 4
#define ARTICUBOT_ONE_PUBLIC __attribute__((visibility("default")))
#define ARTICUBOT_ONE_LOCAL __attribute__((visibility("hidden")))
#else
#define ARTICUBOT_ONE_PUBLIC
#define ARTICUBOT_ONE_LOCAL
#endif
#define ARTICUBOT_ONE_PUBLIC_TYPE
#endif

#endif  // ARTICUBOT_ONE__VISIBILITY_CONTROL_H_
