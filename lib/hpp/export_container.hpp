/*
 * Copyright (c) 2023 Ryota Sasaki.
 *
 * This source code is licensed under the MIT license found in the LICENSE file in the root
 * directory of this source tree.
 */

#pragma once

#include <string>
#include <type_traits>

#include "./type_check.hpp"
#include "./utility.hpp"

namespace cpp_dump {

extern inline size_t max_line_width;

extern inline size_t max_depth;

extern inline size_t max_iteration_count;

namespace _detail {

template <typename T>
std::string export_var(const T &, const std::string &, size_t, size_t, bool);

template <typename T>
inline auto export_container(
    const T &container,
    const std::string &indent,
    size_t last_line_length,
    size_t current_depth,
    bool fail_on_newline
) -> std::enable_if_t<is_container<T>, std::string> {
  if (is_empty_iterable(container)) return "[ ]";

  if (current_depth >= max_depth) return "[ ... ]";

  bool shift_indent = is_iterable_like<iterable_elem_type<T>>;
  // 中身がiterable_likeでも常に長さに応じて改行するかどうかを決める場合は次
  // bool shift_indent = false;

  if (shift_indent && fail_on_newline) return "\n";

  std::string new_indent = indent + "  ";
  size_t next_depth      = current_depth + 1;

rollback:
  std::string output     = "[ ";
  bool is_first          = true;
  size_t iteration_count = 0;
  for (const auto &elem : container) {
    if (is_first) {
      is_first = false;
    } else {
      output += ", ";
    }

    if (shift_indent) {
      if (++iteration_count > max_iteration_count) {
        output += "\n" + new_indent + "...";
        break;
      }

      output +=
          "\n" + new_indent + export_var(elem, new_indent, new_indent.length(), next_depth, false);
      continue;
    }

    if (++iteration_count > max_iteration_count) {
      output += "...";

      if (last_line_length + (output + " ]").length() <= max_line_width) break;

      shift_indent = true;
      goto rollback;
    }

    std::string elem_string =
        export_var(elem, indent, last_line_length + output.length(), next_depth, true);
    if (!has_newline(elem_string)) {
      output += elem_string;

      if (last_line_length + (output + " ]").length() <= max_line_width) continue;
    }

    if (fail_on_newline) return "\n";

    shift_indent = true;
    goto rollback;
  }

  if (shift_indent) {
    output += "\n" + indent + "]";
  } else {
    output += " ]";
  }

  return output;
}

}  // namespace _detail

}  // namespace cpp_dump
