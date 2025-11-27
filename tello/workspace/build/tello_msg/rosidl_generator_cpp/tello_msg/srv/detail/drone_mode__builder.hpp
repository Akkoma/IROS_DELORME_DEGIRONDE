// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tello_msg:srv/DroneMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tello_msg/srv/drone_mode.hpp"


#ifndef TELLO_MSG__SRV__DETAIL__DRONE_MODE__BUILDER_HPP_
#define TELLO_MSG__SRV__DETAIL__DRONE_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tello_msg/srv/detail/drone_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tello_msg
{

namespace srv
{

namespace builder
{

class Init_DroneMode_Request_mode
{
public:
  Init_DroneMode_Request_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tello_msg::srv::DroneMode_Request mode(::tello_msg::srv::DroneMode_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tello_msg::srv::DroneMode_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tello_msg::srv::DroneMode_Request>()
{
  return tello_msg::srv::builder::Init_DroneMode_Request_mode();
}

}  // namespace tello_msg


namespace tello_msg
{

namespace srv
{

namespace builder
{

class Init_DroneMode_Response_message
{
public:
  explicit Init_DroneMode_Response_message(::tello_msg::srv::DroneMode_Response & msg)
  : msg_(msg)
  {}
  ::tello_msg::srv::DroneMode_Response message(::tello_msg::srv::DroneMode_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tello_msg::srv::DroneMode_Response msg_;
};

class Init_DroneMode_Response_success
{
public:
  Init_DroneMode_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DroneMode_Response_message success(::tello_msg::srv::DroneMode_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_DroneMode_Response_message(msg_);
  }

private:
  ::tello_msg::srv::DroneMode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tello_msg::srv::DroneMode_Response>()
{
  return tello_msg::srv::builder::Init_DroneMode_Response_success();
}

}  // namespace tello_msg


namespace tello_msg
{

namespace srv
{

namespace builder
{

class Init_DroneMode_Event_response
{
public:
  explicit Init_DroneMode_Event_response(::tello_msg::srv::DroneMode_Event & msg)
  : msg_(msg)
  {}
  ::tello_msg::srv::DroneMode_Event response(::tello_msg::srv::DroneMode_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tello_msg::srv::DroneMode_Event msg_;
};

class Init_DroneMode_Event_request
{
public:
  explicit Init_DroneMode_Event_request(::tello_msg::srv::DroneMode_Event & msg)
  : msg_(msg)
  {}
  Init_DroneMode_Event_response request(::tello_msg::srv::DroneMode_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_DroneMode_Event_response(msg_);
  }

private:
  ::tello_msg::srv::DroneMode_Event msg_;
};

class Init_DroneMode_Event_info
{
public:
  Init_DroneMode_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DroneMode_Event_request info(::tello_msg::srv::DroneMode_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_DroneMode_Event_request(msg_);
  }

private:
  ::tello_msg::srv::DroneMode_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tello_msg::srv::DroneMode_Event>()
{
  return tello_msg::srv::builder::Init_DroneMode_Event_info();
}

}  // namespace tello_msg

#endif  // TELLO_MSG__SRV__DETAIL__DRONE_MODE__BUILDER_HPP_
