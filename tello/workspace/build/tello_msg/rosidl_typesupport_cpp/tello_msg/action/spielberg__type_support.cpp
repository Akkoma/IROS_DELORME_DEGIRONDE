// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from tello_msg:action/Spielberg.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "tello_msg/action/detail/spielberg__functions.h"
#include "tello_msg/action/detail/spielberg__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace tello_msg
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Spielberg_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Spielberg_Goal_type_support_ids_t;

static const _Spielberg_Goal_type_support_ids_t _Spielberg_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Spielberg_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Spielberg_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Spielberg_Goal_type_support_symbol_names_t _Spielberg_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tello_msg, action, Spielberg_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tello_msg, action, Spielberg_Goal)),
  }
};

typedef struct _Spielberg_Goal_type_support_data_t
{
  void * data[2];
} _Spielberg_Goal_type_support_data_t;

static _Spielberg_Goal_type_support_data_t _Spielberg_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Spielberg_Goal_message_typesupport_map = {
  2,
  "tello_msg",
  &_Spielberg_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_Spielberg_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_Spielberg_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Spielberg_Goal_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Spielberg_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tello_msg__action__Spielberg_Goal__get_type_hash,
  &tello_msg__action__Spielberg_Goal__get_type_description,
  &tello_msg__action__Spielberg_Goal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tello_msg

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tello_msg::action::Spielberg_Goal>()
{
  return &::tello_msg::action::rosidl_typesupport_cpp::Spielberg_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tello_msg, action, Spielberg_Goal)() {
  return get_message_type_support_handle<tello_msg::action::Spielberg_Goal>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "tello_msg/action/detail/spielberg__functions.h"
// already included above
// #include "tello_msg/action/detail/spielberg__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tello_msg
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Spielberg_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Spielberg_Result_type_support_ids_t;

static const _Spielberg_Result_type_support_ids_t _Spielberg_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Spielberg_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Spielberg_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Spielberg_Result_type_support_symbol_names_t _Spielberg_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tello_msg, action, Spielberg_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tello_msg, action, Spielberg_Result)),
  }
};

typedef struct _Spielberg_Result_type_support_data_t
{
  void * data[2];
} _Spielberg_Result_type_support_data_t;

static _Spielberg_Result_type_support_data_t _Spielberg_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Spielberg_Result_message_typesupport_map = {
  2,
  "tello_msg",
  &_Spielberg_Result_message_typesupport_ids.typesupport_identifier[0],
  &_Spielberg_Result_message_typesupport_symbol_names.symbol_name[0],
  &_Spielberg_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Spielberg_Result_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Spielberg_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tello_msg__action__Spielberg_Result__get_type_hash,
  &tello_msg__action__Spielberg_Result__get_type_description,
  &tello_msg__action__Spielberg_Result__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tello_msg

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tello_msg::action::Spielberg_Result>()
{
  return &::tello_msg::action::rosidl_typesupport_cpp::Spielberg_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tello_msg, action, Spielberg_Result)() {
  return get_message_type_support_handle<tello_msg::action::Spielberg_Result>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "tello_msg/action/detail/spielberg__functions.h"
// already included above
// #include "tello_msg/action/detail/spielberg__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tello_msg
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Spielberg_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Spielberg_Feedback_type_support_ids_t;

static const _Spielberg_Feedback_type_support_ids_t _Spielberg_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Spielberg_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Spielberg_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Spielberg_Feedback_type_support_symbol_names_t _Spielberg_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tello_msg, action, Spielberg_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tello_msg, action, Spielberg_Feedback)),
  }
};

typedef struct _Spielberg_Feedback_type_support_data_t
{
  void * data[2];
} _Spielberg_Feedback_type_support_data_t;

static _Spielberg_Feedback_type_support_data_t _Spielberg_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Spielberg_Feedback_message_typesupport_map = {
  2,
  "tello_msg",
  &_Spielberg_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_Spielberg_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_Spielberg_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Spielberg_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Spielberg_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tello_msg__action__Spielberg_Feedback__get_type_hash,
  &tello_msg__action__Spielberg_Feedback__get_type_description,
  &tello_msg__action__Spielberg_Feedback__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tello_msg

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tello_msg::action::Spielberg_Feedback>()
{
  return &::tello_msg::action::rosidl_typesupport_cpp::Spielberg_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tello_msg, action, Spielberg_Feedback)() {
  return get_message_type_support_handle<tello_msg::action::Spielberg_Feedback>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "tello_msg/action/detail/spielberg__functions.h"
// already included above
// #include "tello_msg/action/detail/spielberg__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tello_msg
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Spielberg_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Spielberg_SendGoal_Request_type_support_ids_t;

static const _Spielberg_SendGoal_Request_type_support_ids_t _Spielberg_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Spielberg_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Spielberg_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Spielberg_SendGoal_Request_type_support_symbol_names_t _Spielberg_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tello_msg, action, Spielberg_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tello_msg, action, Spielberg_SendGoal_Request)),
  }
};

typedef struct _Spielberg_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _Spielberg_SendGoal_Request_type_support_data_t;

static _Spielberg_SendGoal_Request_type_support_data_t _Spielberg_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Spielberg_SendGoal_Request_message_typesupport_map = {
  2,
  "tello_msg",
  &_Spielberg_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Spielberg_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Spielberg_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Spielberg_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Spielberg_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tello_msg__action__Spielberg_SendGoal_Request__get_type_hash,
  &tello_msg__action__Spielberg_SendGoal_Request__get_type_description,
  &tello_msg__action__Spielberg_SendGoal_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tello_msg

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tello_msg::action::Spielberg_SendGoal_Request>()
{
  return &::tello_msg::action::rosidl_typesupport_cpp::Spielberg_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tello_msg, action, Spielberg_SendGoal_Request)() {
  return get_message_type_support_handle<tello_msg::action::Spielberg_SendGoal_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "tello_msg/action/detail/spielberg__functions.h"
// already included above
// #include "tello_msg/action/detail/spielberg__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tello_msg
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Spielberg_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Spielberg_SendGoal_Response_type_support_ids_t;

static const _Spielberg_SendGoal_Response_type_support_ids_t _Spielberg_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Spielberg_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Spielberg_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Spielberg_SendGoal_Response_type_support_symbol_names_t _Spielberg_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tello_msg, action, Spielberg_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tello_msg, action, Spielberg_SendGoal_Response)),
  }
};

typedef struct _Spielberg_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _Spielberg_SendGoal_Response_type_support_data_t;

static _Spielberg_SendGoal_Response_type_support_data_t _Spielberg_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Spielberg_SendGoal_Response_message_typesupport_map = {
  2,
  "tello_msg",
  &_Spielberg_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Spielberg_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Spielberg_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Spielberg_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Spielberg_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tello_msg__action__Spielberg_SendGoal_Response__get_type_hash,
  &tello_msg__action__Spielberg_SendGoal_Response__get_type_description,
  &tello_msg__action__Spielberg_SendGoal_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tello_msg

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tello_msg::action::Spielberg_SendGoal_Response>()
{
  return &::tello_msg::action::rosidl_typesupport_cpp::Spielberg_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tello_msg, action, Spielberg_SendGoal_Response)() {
  return get_message_type_support_handle<tello_msg::action::Spielberg_SendGoal_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "tello_msg/action/detail/spielberg__functions.h"
// already included above
// #include "tello_msg/action/detail/spielberg__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tello_msg
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Spielberg_SendGoal_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Spielberg_SendGoal_Event_type_support_ids_t;

static const _Spielberg_SendGoal_Event_type_support_ids_t _Spielberg_SendGoal_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Spielberg_SendGoal_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Spielberg_SendGoal_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Spielberg_SendGoal_Event_type_support_symbol_names_t _Spielberg_SendGoal_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tello_msg, action, Spielberg_SendGoal_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tello_msg, action, Spielberg_SendGoal_Event)),
  }
};

typedef struct _Spielberg_SendGoal_Event_type_support_data_t
{
  void * data[2];
} _Spielberg_SendGoal_Event_type_support_data_t;

static _Spielberg_SendGoal_Event_type_support_data_t _Spielberg_SendGoal_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Spielberg_SendGoal_Event_message_typesupport_map = {
  2,
  "tello_msg",
  &_Spielberg_SendGoal_Event_message_typesupport_ids.typesupport_identifier[0],
  &_Spielberg_SendGoal_Event_message_typesupport_symbol_names.symbol_name[0],
  &_Spielberg_SendGoal_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Spielberg_SendGoal_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Spielberg_SendGoal_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tello_msg__action__Spielberg_SendGoal_Event__get_type_hash,
  &tello_msg__action__Spielberg_SendGoal_Event__get_type_description,
  &tello_msg__action__Spielberg_SendGoal_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tello_msg

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tello_msg::action::Spielberg_SendGoal_Event>()
{
  return &::tello_msg::action::rosidl_typesupport_cpp::Spielberg_SendGoal_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tello_msg, action, Spielberg_SendGoal_Event)() {
  return get_message_type_support_handle<tello_msg::action::Spielberg_SendGoal_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "tello_msg/action/detail/spielberg__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tello_msg
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Spielberg_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Spielberg_SendGoal_type_support_ids_t;

static const _Spielberg_SendGoal_type_support_ids_t _Spielberg_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Spielberg_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Spielberg_SendGoal_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Spielberg_SendGoal_type_support_symbol_names_t _Spielberg_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tello_msg, action, Spielberg_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tello_msg, action, Spielberg_SendGoal)),
  }
};

typedef struct _Spielberg_SendGoal_type_support_data_t
{
  void * data[2];
} _Spielberg_SendGoal_type_support_data_t;

static _Spielberg_SendGoal_type_support_data_t _Spielberg_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Spielberg_SendGoal_service_typesupport_map = {
  2,
  "tello_msg",
  &_Spielberg_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_Spielberg_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_Spielberg_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Spielberg_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Spielberg_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<tello_msg::action::Spielberg_SendGoal_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<tello_msg::action::Spielberg_SendGoal_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<tello_msg::action::Spielberg_SendGoal_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<tello_msg::action::Spielberg_SendGoal>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<tello_msg::action::Spielberg_SendGoal>,
  &tello_msg__action__Spielberg_SendGoal__get_type_hash,
  &tello_msg__action__Spielberg_SendGoal__get_type_description,
  &tello_msg__action__Spielberg_SendGoal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tello_msg

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<tello_msg::action::Spielberg_SendGoal>()
{
  return &::tello_msg::action::rosidl_typesupport_cpp::Spielberg_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, tello_msg, action, Spielberg_SendGoal)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<tello_msg::action::Spielberg_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "tello_msg/action/detail/spielberg__functions.h"
// already included above
// #include "tello_msg/action/detail/spielberg__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tello_msg
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Spielberg_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Spielberg_GetResult_Request_type_support_ids_t;

static const _Spielberg_GetResult_Request_type_support_ids_t _Spielberg_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Spielberg_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Spielberg_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Spielberg_GetResult_Request_type_support_symbol_names_t _Spielberg_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tello_msg, action, Spielberg_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tello_msg, action, Spielberg_GetResult_Request)),
  }
};

typedef struct _Spielberg_GetResult_Request_type_support_data_t
{
  void * data[2];
} _Spielberg_GetResult_Request_type_support_data_t;

static _Spielberg_GetResult_Request_type_support_data_t _Spielberg_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Spielberg_GetResult_Request_message_typesupport_map = {
  2,
  "tello_msg",
  &_Spielberg_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Spielberg_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Spielberg_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Spielberg_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Spielberg_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tello_msg__action__Spielberg_GetResult_Request__get_type_hash,
  &tello_msg__action__Spielberg_GetResult_Request__get_type_description,
  &tello_msg__action__Spielberg_GetResult_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tello_msg

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tello_msg::action::Spielberg_GetResult_Request>()
{
  return &::tello_msg::action::rosidl_typesupport_cpp::Spielberg_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tello_msg, action, Spielberg_GetResult_Request)() {
  return get_message_type_support_handle<tello_msg::action::Spielberg_GetResult_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "tello_msg/action/detail/spielberg__functions.h"
// already included above
// #include "tello_msg/action/detail/spielberg__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tello_msg
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Spielberg_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Spielberg_GetResult_Response_type_support_ids_t;

static const _Spielberg_GetResult_Response_type_support_ids_t _Spielberg_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Spielberg_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Spielberg_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Spielberg_GetResult_Response_type_support_symbol_names_t _Spielberg_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tello_msg, action, Spielberg_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tello_msg, action, Spielberg_GetResult_Response)),
  }
};

typedef struct _Spielberg_GetResult_Response_type_support_data_t
{
  void * data[2];
} _Spielberg_GetResult_Response_type_support_data_t;

static _Spielberg_GetResult_Response_type_support_data_t _Spielberg_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Spielberg_GetResult_Response_message_typesupport_map = {
  2,
  "tello_msg",
  &_Spielberg_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Spielberg_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Spielberg_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Spielberg_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Spielberg_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tello_msg__action__Spielberg_GetResult_Response__get_type_hash,
  &tello_msg__action__Spielberg_GetResult_Response__get_type_description,
  &tello_msg__action__Spielberg_GetResult_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tello_msg

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tello_msg::action::Spielberg_GetResult_Response>()
{
  return &::tello_msg::action::rosidl_typesupport_cpp::Spielberg_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tello_msg, action, Spielberg_GetResult_Response)() {
  return get_message_type_support_handle<tello_msg::action::Spielberg_GetResult_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "tello_msg/action/detail/spielberg__functions.h"
// already included above
// #include "tello_msg/action/detail/spielberg__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tello_msg
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Spielberg_GetResult_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Spielberg_GetResult_Event_type_support_ids_t;

static const _Spielberg_GetResult_Event_type_support_ids_t _Spielberg_GetResult_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Spielberg_GetResult_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Spielberg_GetResult_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Spielberg_GetResult_Event_type_support_symbol_names_t _Spielberg_GetResult_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tello_msg, action, Spielberg_GetResult_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tello_msg, action, Spielberg_GetResult_Event)),
  }
};

typedef struct _Spielberg_GetResult_Event_type_support_data_t
{
  void * data[2];
} _Spielberg_GetResult_Event_type_support_data_t;

static _Spielberg_GetResult_Event_type_support_data_t _Spielberg_GetResult_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Spielberg_GetResult_Event_message_typesupport_map = {
  2,
  "tello_msg",
  &_Spielberg_GetResult_Event_message_typesupport_ids.typesupport_identifier[0],
  &_Spielberg_GetResult_Event_message_typesupport_symbol_names.symbol_name[0],
  &_Spielberg_GetResult_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Spielberg_GetResult_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Spielberg_GetResult_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tello_msg__action__Spielberg_GetResult_Event__get_type_hash,
  &tello_msg__action__Spielberg_GetResult_Event__get_type_description,
  &tello_msg__action__Spielberg_GetResult_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tello_msg

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tello_msg::action::Spielberg_GetResult_Event>()
{
  return &::tello_msg::action::rosidl_typesupport_cpp::Spielberg_GetResult_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tello_msg, action, Spielberg_GetResult_Event)() {
  return get_message_type_support_handle<tello_msg::action::Spielberg_GetResult_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "tello_msg/action/detail/spielberg__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tello_msg
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Spielberg_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Spielberg_GetResult_type_support_ids_t;

static const _Spielberg_GetResult_type_support_ids_t _Spielberg_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Spielberg_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Spielberg_GetResult_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Spielberg_GetResult_type_support_symbol_names_t _Spielberg_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tello_msg, action, Spielberg_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tello_msg, action, Spielberg_GetResult)),
  }
};

typedef struct _Spielberg_GetResult_type_support_data_t
{
  void * data[2];
} _Spielberg_GetResult_type_support_data_t;

static _Spielberg_GetResult_type_support_data_t _Spielberg_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Spielberg_GetResult_service_typesupport_map = {
  2,
  "tello_msg",
  &_Spielberg_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_Spielberg_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_Spielberg_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Spielberg_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Spielberg_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<tello_msg::action::Spielberg_GetResult_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<tello_msg::action::Spielberg_GetResult_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<tello_msg::action::Spielberg_GetResult_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<tello_msg::action::Spielberg_GetResult>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<tello_msg::action::Spielberg_GetResult>,
  &tello_msg__action__Spielberg_GetResult__get_type_hash,
  &tello_msg__action__Spielberg_GetResult__get_type_description,
  &tello_msg__action__Spielberg_GetResult__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tello_msg

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<tello_msg::action::Spielberg_GetResult>()
{
  return &::tello_msg::action::rosidl_typesupport_cpp::Spielberg_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, tello_msg, action, Spielberg_GetResult)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<tello_msg::action::Spielberg_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "tello_msg/action/detail/spielberg__functions.h"
// already included above
// #include "tello_msg/action/detail/spielberg__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace tello_msg
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Spielberg_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Spielberg_FeedbackMessage_type_support_ids_t;

static const _Spielberg_FeedbackMessage_type_support_ids_t _Spielberg_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Spielberg_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Spielberg_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Spielberg_FeedbackMessage_type_support_symbol_names_t _Spielberg_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tello_msg, action, Spielberg_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tello_msg, action, Spielberg_FeedbackMessage)),
  }
};

typedef struct _Spielberg_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _Spielberg_FeedbackMessage_type_support_data_t;

static _Spielberg_FeedbackMessage_type_support_data_t _Spielberg_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Spielberg_FeedbackMessage_message_typesupport_map = {
  2,
  "tello_msg",
  &_Spielberg_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_Spielberg_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_Spielberg_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Spielberg_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Spielberg_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &tello_msg__action__Spielberg_FeedbackMessage__get_type_hash,
  &tello_msg__action__Spielberg_FeedbackMessage__get_type_description,
  &tello_msg__action__Spielberg_FeedbackMessage__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tello_msg

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tello_msg::action::Spielberg_FeedbackMessage>()
{
  return &::tello_msg::action::rosidl_typesupport_cpp::Spielberg_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tello_msg, action, Spielberg_FeedbackMessage)() {
  return get_message_type_support_handle<tello_msg::action::Spielberg_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "tello_msg/action/detail/spielberg__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_typesupport_cpp/action_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"

namespace tello_msg
{

namespace action
{

namespace rosidl_typesupport_cpp
{

static rosidl_action_type_support_t Spielberg_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL,
  &tello_msg__action__Spielberg__get_type_hash,
  &tello_msg__action__Spielberg__get_type_description,
  &tello_msg__action__Spielberg__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace tello_msg

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<tello_msg::action::Spielberg>()
{
  using ::tello_msg::action::rosidl_typesupport_cpp::Spielberg_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  Spielberg_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::tello_msg::action::Spielberg::Impl::SendGoalService>();
  Spielberg_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::tello_msg::action::Spielberg::Impl::GetResultService>();
  Spielberg_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::tello_msg::action::Spielberg::Impl::CancelGoalService>();
  Spielberg_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::tello_msg::action::Spielberg::Impl::FeedbackMessage>();
  Spielberg_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::tello_msg::action::Spielberg::Impl::GoalStatusMessage>();
  return &Spielberg_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(rosidl_typesupport_cpp, tello_msg, action, Spielberg)() {
  return ::rosidl_typesupport_cpp::get_action_type_support_handle<tello_msg::action::Spielberg>();
}

#ifdef __cplusplus
}
#endif
