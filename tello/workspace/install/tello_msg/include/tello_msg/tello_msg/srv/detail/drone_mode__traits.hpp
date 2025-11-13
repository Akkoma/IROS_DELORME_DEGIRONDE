// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tello_msg:srv/DroneMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tello_msg/srv/drone_mode.hpp"


#ifndef TELLO_MSG__SRV__DETAIL__DRONE_MODE__TRAITS_HPP_
#define TELLO_MSG__SRV__DETAIL__DRONE_MODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tello_msg/srv/detail/drone_mode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace tello_msg
{

namespace srv
{

inline void to_flow_style_yaml(
  const DroneMode_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DroneMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DroneMode_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace tello_msg

namespace rosidl_generator_traits
{

[[deprecated("use tello_msg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tello_msg::srv::DroneMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  tello_msg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tello_msg::srv::to_yaml() instead")]]
inline std::string to_yaml(const tello_msg::srv::DroneMode_Request & msg)
{
  return tello_msg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tello_msg::srv::DroneMode_Request>()
{
  return "tello_msg::srv::DroneMode_Request";
}

template<>
inline const char * name<tello_msg::srv::DroneMode_Request>()
{
  return "tello_msg/srv/DroneMode_Request";
}

template<>
struct has_fixed_size<tello_msg::srv::DroneMode_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<tello_msg::srv::DroneMode_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<tello_msg::srv::DroneMode_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace tello_msg
{

namespace srv
{

inline void to_flow_style_yaml(
  const DroneMode_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DroneMode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DroneMode_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace tello_msg

namespace rosidl_generator_traits
{

[[deprecated("use tello_msg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tello_msg::srv::DroneMode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  tello_msg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tello_msg::srv::to_yaml() instead")]]
inline std::string to_yaml(const tello_msg::srv::DroneMode_Response & msg)
{
  return tello_msg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tello_msg::srv::DroneMode_Response>()
{
  return "tello_msg::srv::DroneMode_Response";
}

template<>
inline const char * name<tello_msg::srv::DroneMode_Response>()
{
  return "tello_msg/srv/DroneMode_Response";
}

template<>
struct has_fixed_size<tello_msg::srv::DroneMode_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tello_msg::srv::DroneMode_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tello_msg::srv::DroneMode_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace tello_msg
{

namespace srv
{

inline void to_flow_style_yaml(
  const DroneMode_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DroneMode_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DroneMode_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace tello_msg

namespace rosidl_generator_traits
{

[[deprecated("use tello_msg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tello_msg::srv::DroneMode_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  tello_msg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tello_msg::srv::to_yaml() instead")]]
inline std::string to_yaml(const tello_msg::srv::DroneMode_Event & msg)
{
  return tello_msg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tello_msg::srv::DroneMode_Event>()
{
  return "tello_msg::srv::DroneMode_Event";
}

template<>
inline const char * name<tello_msg::srv::DroneMode_Event>()
{
  return "tello_msg/srv/DroneMode_Event";
}

template<>
struct has_fixed_size<tello_msg::srv::DroneMode_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tello_msg::srv::DroneMode_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<tello_msg::srv::DroneMode_Request>::value && has_bounded_size<tello_msg::srv::DroneMode_Response>::value> {};

template<>
struct is_message<tello_msg::srv::DroneMode_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tello_msg::srv::DroneMode>()
{
  return "tello_msg::srv::DroneMode";
}

template<>
inline const char * name<tello_msg::srv::DroneMode>()
{
  return "tello_msg/srv/DroneMode";
}

template<>
struct has_fixed_size<tello_msg::srv::DroneMode>
  : std::integral_constant<
    bool,
    has_fixed_size<tello_msg::srv::DroneMode_Request>::value &&
    has_fixed_size<tello_msg::srv::DroneMode_Response>::value
  >
{
};

template<>
struct has_bounded_size<tello_msg::srv::DroneMode>
  : std::integral_constant<
    bool,
    has_bounded_size<tello_msg::srv::DroneMode_Request>::value &&
    has_bounded_size<tello_msg::srv::DroneMode_Response>::value
  >
{
};

template<>
struct is_service<tello_msg::srv::DroneMode>
  : std::true_type
{
};

template<>
struct is_service_request<tello_msg::srv::DroneMode_Request>
  : std::true_type
{
};

template<>
struct is_service_response<tello_msg::srv::DroneMode_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TELLO_MSG__SRV__DETAIL__DRONE_MODE__TRAITS_HPP_
