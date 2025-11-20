// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tello_msg:action/Spielberg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tello_msg/action/spielberg.hpp"


#ifndef TELLO_MSG__ACTION__DETAIL__SPIELBERG__BUILDER_HPP_
#define TELLO_MSG__ACTION__DETAIL__SPIELBERG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tello_msg/action/detail/spielberg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tello_msg
{

namespace action
{

namespace builder
{

class Init_Spielberg_Goal_start
{
public:
  Init_Spielberg_Goal_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tello_msg::action::Spielberg_Goal start(::tello_msg::action::Spielberg_Goal::_start_type arg)
  {
    msg_.start = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tello_msg::action::Spielberg_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tello_msg::action::Spielberg_Goal>()
{
  return tello_msg::action::builder::Init_Spielberg_Goal_start();
}

}  // namespace tello_msg


namespace tello_msg
{

namespace action
{

namespace builder
{

class Init_Spielberg_Result_message
{
public:
  explicit Init_Spielberg_Result_message(::tello_msg::action::Spielberg_Result & msg)
  : msg_(msg)
  {}
  ::tello_msg::action::Spielberg_Result message(::tello_msg::action::Spielberg_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tello_msg::action::Spielberg_Result msg_;
};

class Init_Spielberg_Result_success
{
public:
  Init_Spielberg_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Spielberg_Result_message success(::tello_msg::action::Spielberg_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Spielberg_Result_message(msg_);
  }

private:
  ::tello_msg::action::Spielberg_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tello_msg::action::Spielberg_Result>()
{
  return tello_msg::action::builder::Init_Spielberg_Result_success();
}

}  // namespace tello_msg


namespace tello_msg
{

namespace action
{

namespace builder
{

class Init_Spielberg_Feedback_elapsed_time
{
public:
  explicit Init_Spielberg_Feedback_elapsed_time(::tello_msg::action::Spielberg_Feedback & msg)
  : msg_(msg)
  {}
  ::tello_msg::action::Spielberg_Feedback elapsed_time(::tello_msg::action::Spielberg_Feedback::_elapsed_time_type arg)
  {
    msg_.elapsed_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tello_msg::action::Spielberg_Feedback msg_;
};

class Init_Spielberg_Feedback_total_steps
{
public:
  explicit Init_Spielberg_Feedback_total_steps(::tello_msg::action::Spielberg_Feedback & msg)
  : msg_(msg)
  {}
  Init_Spielberg_Feedback_elapsed_time total_steps(::tello_msg::action::Spielberg_Feedback::_total_steps_type arg)
  {
    msg_.total_steps = std::move(arg);
    return Init_Spielberg_Feedback_elapsed_time(msg_);
  }

private:
  ::tello_msg::action::Spielberg_Feedback msg_;
};

class Init_Spielberg_Feedback_current_step
{
public:
  Init_Spielberg_Feedback_current_step()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Spielberg_Feedback_total_steps current_step(::tello_msg::action::Spielberg_Feedback::_current_step_type arg)
  {
    msg_.current_step = std::move(arg);
    return Init_Spielberg_Feedback_total_steps(msg_);
  }

private:
  ::tello_msg::action::Spielberg_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tello_msg::action::Spielberg_Feedback>()
{
  return tello_msg::action::builder::Init_Spielberg_Feedback_current_step();
}

}  // namespace tello_msg


namespace tello_msg
{

namespace action
{

namespace builder
{

class Init_Spielberg_SendGoal_Request_goal
{
public:
  explicit Init_Spielberg_SendGoal_Request_goal(::tello_msg::action::Spielberg_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::tello_msg::action::Spielberg_SendGoal_Request goal(::tello_msg::action::Spielberg_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tello_msg::action::Spielberg_SendGoal_Request msg_;
};

class Init_Spielberg_SendGoal_Request_goal_id
{
public:
  Init_Spielberg_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Spielberg_SendGoal_Request_goal goal_id(::tello_msg::action::Spielberg_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Spielberg_SendGoal_Request_goal(msg_);
  }

private:
  ::tello_msg::action::Spielberg_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tello_msg::action::Spielberg_SendGoal_Request>()
{
  return tello_msg::action::builder::Init_Spielberg_SendGoal_Request_goal_id();
}

}  // namespace tello_msg


namespace tello_msg
{

namespace action
{

namespace builder
{

class Init_Spielberg_SendGoal_Response_stamp
{
public:
  explicit Init_Spielberg_SendGoal_Response_stamp(::tello_msg::action::Spielberg_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::tello_msg::action::Spielberg_SendGoal_Response stamp(::tello_msg::action::Spielberg_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tello_msg::action::Spielberg_SendGoal_Response msg_;
};

class Init_Spielberg_SendGoal_Response_accepted
{
public:
  Init_Spielberg_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Spielberg_SendGoal_Response_stamp accepted(::tello_msg::action::Spielberg_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Spielberg_SendGoal_Response_stamp(msg_);
  }

private:
  ::tello_msg::action::Spielberg_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tello_msg::action::Spielberg_SendGoal_Response>()
{
  return tello_msg::action::builder::Init_Spielberg_SendGoal_Response_accepted();
}

}  // namespace tello_msg


namespace tello_msg
{

namespace action
{

namespace builder
{

class Init_Spielberg_SendGoal_Event_response
{
public:
  explicit Init_Spielberg_SendGoal_Event_response(::tello_msg::action::Spielberg_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::tello_msg::action::Spielberg_SendGoal_Event response(::tello_msg::action::Spielberg_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tello_msg::action::Spielberg_SendGoal_Event msg_;
};

class Init_Spielberg_SendGoal_Event_request
{
public:
  explicit Init_Spielberg_SendGoal_Event_request(::tello_msg::action::Spielberg_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_Spielberg_SendGoal_Event_response request(::tello_msg::action::Spielberg_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Spielberg_SendGoal_Event_response(msg_);
  }

private:
  ::tello_msg::action::Spielberg_SendGoal_Event msg_;
};

class Init_Spielberg_SendGoal_Event_info
{
public:
  Init_Spielberg_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Spielberg_SendGoal_Event_request info(::tello_msg::action::Spielberg_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Spielberg_SendGoal_Event_request(msg_);
  }

private:
  ::tello_msg::action::Spielberg_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tello_msg::action::Spielberg_SendGoal_Event>()
{
  return tello_msg::action::builder::Init_Spielberg_SendGoal_Event_info();
}

}  // namespace tello_msg


namespace tello_msg
{

namespace action
{

namespace builder
{

class Init_Spielberg_GetResult_Request_goal_id
{
public:
  Init_Spielberg_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tello_msg::action::Spielberg_GetResult_Request goal_id(::tello_msg::action::Spielberg_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tello_msg::action::Spielberg_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tello_msg::action::Spielberg_GetResult_Request>()
{
  return tello_msg::action::builder::Init_Spielberg_GetResult_Request_goal_id();
}

}  // namespace tello_msg


namespace tello_msg
{

namespace action
{

namespace builder
{

class Init_Spielberg_GetResult_Response_result
{
public:
  explicit Init_Spielberg_GetResult_Response_result(::tello_msg::action::Spielberg_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::tello_msg::action::Spielberg_GetResult_Response result(::tello_msg::action::Spielberg_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tello_msg::action::Spielberg_GetResult_Response msg_;
};

class Init_Spielberg_GetResult_Response_status
{
public:
  Init_Spielberg_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Spielberg_GetResult_Response_result status(::tello_msg::action::Spielberg_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Spielberg_GetResult_Response_result(msg_);
  }

private:
  ::tello_msg::action::Spielberg_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tello_msg::action::Spielberg_GetResult_Response>()
{
  return tello_msg::action::builder::Init_Spielberg_GetResult_Response_status();
}

}  // namespace tello_msg


namespace tello_msg
{

namespace action
{

namespace builder
{

class Init_Spielberg_GetResult_Event_response
{
public:
  explicit Init_Spielberg_GetResult_Event_response(::tello_msg::action::Spielberg_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::tello_msg::action::Spielberg_GetResult_Event response(::tello_msg::action::Spielberg_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tello_msg::action::Spielberg_GetResult_Event msg_;
};

class Init_Spielberg_GetResult_Event_request
{
public:
  explicit Init_Spielberg_GetResult_Event_request(::tello_msg::action::Spielberg_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_Spielberg_GetResult_Event_response request(::tello_msg::action::Spielberg_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Spielberg_GetResult_Event_response(msg_);
  }

private:
  ::tello_msg::action::Spielberg_GetResult_Event msg_;
};

class Init_Spielberg_GetResult_Event_info
{
public:
  Init_Spielberg_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Spielberg_GetResult_Event_request info(::tello_msg::action::Spielberg_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Spielberg_GetResult_Event_request(msg_);
  }

private:
  ::tello_msg::action::Spielberg_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tello_msg::action::Spielberg_GetResult_Event>()
{
  return tello_msg::action::builder::Init_Spielberg_GetResult_Event_info();
}

}  // namespace tello_msg


namespace tello_msg
{

namespace action
{

namespace builder
{

class Init_Spielberg_FeedbackMessage_feedback
{
public:
  explicit Init_Spielberg_FeedbackMessage_feedback(::tello_msg::action::Spielberg_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::tello_msg::action::Spielberg_FeedbackMessage feedback(::tello_msg::action::Spielberg_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tello_msg::action::Spielberg_FeedbackMessage msg_;
};

class Init_Spielberg_FeedbackMessage_goal_id
{
public:
  Init_Spielberg_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Spielberg_FeedbackMessage_feedback goal_id(::tello_msg::action::Spielberg_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Spielberg_FeedbackMessage_feedback(msg_);
  }

private:
  ::tello_msg::action::Spielberg_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tello_msg::action::Spielberg_FeedbackMessage>()
{
  return tello_msg::action::builder::Init_Spielberg_FeedbackMessage_goal_id();
}

}  // namespace tello_msg

#endif  // TELLO_MSG__ACTION__DETAIL__SPIELBERG__BUILDER_HPP_
