// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tello_msg:srv/Surveillance.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tello_msg/srv/surveillance.hpp"


#ifndef TELLO_MSG__SRV__DETAIL__SURVEILLANCE__BUILDER_HPP_
#define TELLO_MSG__SRV__DETAIL__SURVEILLANCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tello_msg/srv/detail/surveillance__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tello_msg
{

namespace srv
{

namespace builder
{

class Init_Surveillance_Request_data
{
public:
  Init_Surveillance_Request_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tello_msg::srv::Surveillance_Request data(::tello_msg::srv::Surveillance_Request::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tello_msg::srv::Surveillance_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tello_msg::srv::Surveillance_Request>()
{
  return tello_msg::srv::builder::Init_Surveillance_Request_data();
}

}  // namespace tello_msg


namespace tello_msg
{

namespace srv
{

namespace builder
{

class Init_Surveillance_Response_success
{
public:
  Init_Surveillance_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tello_msg::srv::Surveillance_Response success(::tello_msg::srv::Surveillance_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tello_msg::srv::Surveillance_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tello_msg::srv::Surveillance_Response>()
{
  return tello_msg::srv::builder::Init_Surveillance_Response_success();
}

}  // namespace tello_msg


namespace tello_msg
{

namespace srv
{

namespace builder
{

class Init_Surveillance_Event_response
{
public:
  explicit Init_Surveillance_Event_response(::tello_msg::srv::Surveillance_Event & msg)
  : msg_(msg)
  {}
  ::tello_msg::srv::Surveillance_Event response(::tello_msg::srv::Surveillance_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tello_msg::srv::Surveillance_Event msg_;
};

class Init_Surveillance_Event_request
{
public:
  explicit Init_Surveillance_Event_request(::tello_msg::srv::Surveillance_Event & msg)
  : msg_(msg)
  {}
  Init_Surveillance_Event_response request(::tello_msg::srv::Surveillance_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Surveillance_Event_response(msg_);
  }

private:
  ::tello_msg::srv::Surveillance_Event msg_;
};

class Init_Surveillance_Event_info
{
public:
  Init_Surveillance_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Surveillance_Event_request info(::tello_msg::srv::Surveillance_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Surveillance_Event_request(msg_);
  }

private:
  ::tello_msg::srv::Surveillance_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tello_msg::srv::Surveillance_Event>()
{
  return tello_msg::srv::builder::Init_Surveillance_Event_info();
}

}  // namespace tello_msg

#endif  // TELLO_MSG__SRV__DETAIL__SURVEILLANCE__BUILDER_HPP_
