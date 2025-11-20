// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tello_msg:srv/Surveillance.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tello_msg/srv/detail/surveillance__rosidl_typesupport_introspection_c.h"
#include "tello_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tello_msg/srv/detail/surveillance__functions.h"
#include "tello_msg/srv/detail/surveillance__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void tello_msg__srv__Surveillance_Request__rosidl_typesupport_introspection_c__Surveillance_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tello_msg__srv__Surveillance_Request__init(message_memory);
}

void tello_msg__srv__Surveillance_Request__rosidl_typesupport_introspection_c__Surveillance_Request_fini_function(void * message_memory)
{
  tello_msg__srv__Surveillance_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tello_msg__srv__Surveillance_Request__rosidl_typesupport_introspection_c__Surveillance_Request_message_member_array[1] = {
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tello_msg__srv__Surveillance_Request, data),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tello_msg__srv__Surveillance_Request__rosidl_typesupport_introspection_c__Surveillance_Request_message_members = {
  "tello_msg__srv",  // message namespace
  "Surveillance_Request",  // message name
  1,  // number of fields
  sizeof(tello_msg__srv__Surveillance_Request),
  false,  // has_any_key_member_
  tello_msg__srv__Surveillance_Request__rosidl_typesupport_introspection_c__Surveillance_Request_message_member_array,  // message members
  tello_msg__srv__Surveillance_Request__rosidl_typesupport_introspection_c__Surveillance_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  tello_msg__srv__Surveillance_Request__rosidl_typesupport_introspection_c__Surveillance_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tello_msg__srv__Surveillance_Request__rosidl_typesupport_introspection_c__Surveillance_Request_message_type_support_handle = {
  0,
  &tello_msg__srv__Surveillance_Request__rosidl_typesupport_introspection_c__Surveillance_Request_message_members,
  get_message_typesupport_handle_function,
  &tello_msg__srv__Surveillance_Request__get_type_hash,
  &tello_msg__srv__Surveillance_Request__get_type_description,
  &tello_msg__srv__Surveillance_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tello_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tello_msg, srv, Surveillance_Request)() {
  if (!tello_msg__srv__Surveillance_Request__rosidl_typesupport_introspection_c__Surveillance_Request_message_type_support_handle.typesupport_identifier) {
    tello_msg__srv__Surveillance_Request__rosidl_typesupport_introspection_c__Surveillance_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tello_msg__srv__Surveillance_Request__rosidl_typesupport_introspection_c__Surveillance_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "tello_msg/srv/detail/surveillance__rosidl_typesupport_introspection_c.h"
// already included above
// #include "tello_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "tello_msg/srv/detail/surveillance__functions.h"
// already included above
// #include "tello_msg/srv/detail/surveillance__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void tello_msg__srv__Surveillance_Response__rosidl_typesupport_introspection_c__Surveillance_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tello_msg__srv__Surveillance_Response__init(message_memory);
}

void tello_msg__srv__Surveillance_Response__rosidl_typesupport_introspection_c__Surveillance_Response_fini_function(void * message_memory)
{
  tello_msg__srv__Surveillance_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tello_msg__srv__Surveillance_Response__rosidl_typesupport_introspection_c__Surveillance_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tello_msg__srv__Surveillance_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tello_msg__srv__Surveillance_Response__rosidl_typesupport_introspection_c__Surveillance_Response_message_members = {
  "tello_msg__srv",  // message namespace
  "Surveillance_Response",  // message name
  1,  // number of fields
  sizeof(tello_msg__srv__Surveillance_Response),
  false,  // has_any_key_member_
  tello_msg__srv__Surveillance_Response__rosidl_typesupport_introspection_c__Surveillance_Response_message_member_array,  // message members
  tello_msg__srv__Surveillance_Response__rosidl_typesupport_introspection_c__Surveillance_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  tello_msg__srv__Surveillance_Response__rosidl_typesupport_introspection_c__Surveillance_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tello_msg__srv__Surveillance_Response__rosidl_typesupport_introspection_c__Surveillance_Response_message_type_support_handle = {
  0,
  &tello_msg__srv__Surveillance_Response__rosidl_typesupport_introspection_c__Surveillance_Response_message_members,
  get_message_typesupport_handle_function,
  &tello_msg__srv__Surveillance_Response__get_type_hash,
  &tello_msg__srv__Surveillance_Response__get_type_description,
  &tello_msg__srv__Surveillance_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tello_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tello_msg, srv, Surveillance_Response)() {
  if (!tello_msg__srv__Surveillance_Response__rosidl_typesupport_introspection_c__Surveillance_Response_message_type_support_handle.typesupport_identifier) {
    tello_msg__srv__Surveillance_Response__rosidl_typesupport_introspection_c__Surveillance_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tello_msg__srv__Surveillance_Response__rosidl_typesupport_introspection_c__Surveillance_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "tello_msg/srv/detail/surveillance__rosidl_typesupport_introspection_c.h"
// already included above
// #include "tello_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "tello_msg/srv/detail/surveillance__functions.h"
// already included above
// #include "tello_msg/srv/detail/surveillance__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "tello_msg/srv/surveillance.h"
// Member `request`
// Member `response`
// already included above
// #include "tello_msg/srv/detail/surveillance__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__Surveillance_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tello_msg__srv__Surveillance_Event__init(message_memory);
}

void tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__Surveillance_Event_fini_function(void * message_memory)
{
  tello_msg__srv__Surveillance_Event__fini(message_memory);
}

size_t tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__size_function__Surveillance_Event__request(
  const void * untyped_member)
{
  const tello_msg__srv__Surveillance_Request__Sequence * member =
    (const tello_msg__srv__Surveillance_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__get_const_function__Surveillance_Event__request(
  const void * untyped_member, size_t index)
{
  const tello_msg__srv__Surveillance_Request__Sequence * member =
    (const tello_msg__srv__Surveillance_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__get_function__Surveillance_Event__request(
  void * untyped_member, size_t index)
{
  tello_msg__srv__Surveillance_Request__Sequence * member =
    (tello_msg__srv__Surveillance_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__fetch_function__Surveillance_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tello_msg__srv__Surveillance_Request * item =
    ((const tello_msg__srv__Surveillance_Request *)
    tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__get_const_function__Surveillance_Event__request(untyped_member, index));
  tello_msg__srv__Surveillance_Request * value =
    (tello_msg__srv__Surveillance_Request *)(untyped_value);
  *value = *item;
}

void tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__assign_function__Surveillance_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tello_msg__srv__Surveillance_Request * item =
    ((tello_msg__srv__Surveillance_Request *)
    tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__get_function__Surveillance_Event__request(untyped_member, index));
  const tello_msg__srv__Surveillance_Request * value =
    (const tello_msg__srv__Surveillance_Request *)(untyped_value);
  *item = *value;
}

bool tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__resize_function__Surveillance_Event__request(
  void * untyped_member, size_t size)
{
  tello_msg__srv__Surveillance_Request__Sequence * member =
    (tello_msg__srv__Surveillance_Request__Sequence *)(untyped_member);
  tello_msg__srv__Surveillance_Request__Sequence__fini(member);
  return tello_msg__srv__Surveillance_Request__Sequence__init(member, size);
}

size_t tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__size_function__Surveillance_Event__response(
  const void * untyped_member)
{
  const tello_msg__srv__Surveillance_Response__Sequence * member =
    (const tello_msg__srv__Surveillance_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__get_const_function__Surveillance_Event__response(
  const void * untyped_member, size_t index)
{
  const tello_msg__srv__Surveillance_Response__Sequence * member =
    (const tello_msg__srv__Surveillance_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__get_function__Surveillance_Event__response(
  void * untyped_member, size_t index)
{
  tello_msg__srv__Surveillance_Response__Sequence * member =
    (tello_msg__srv__Surveillance_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__fetch_function__Surveillance_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tello_msg__srv__Surveillance_Response * item =
    ((const tello_msg__srv__Surveillance_Response *)
    tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__get_const_function__Surveillance_Event__response(untyped_member, index));
  tello_msg__srv__Surveillance_Response * value =
    (tello_msg__srv__Surveillance_Response *)(untyped_value);
  *value = *item;
}

void tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__assign_function__Surveillance_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tello_msg__srv__Surveillance_Response * item =
    ((tello_msg__srv__Surveillance_Response *)
    tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__get_function__Surveillance_Event__response(untyped_member, index));
  const tello_msg__srv__Surveillance_Response * value =
    (const tello_msg__srv__Surveillance_Response *)(untyped_value);
  *item = *value;
}

bool tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__resize_function__Surveillance_Event__response(
  void * untyped_member, size_t size)
{
  tello_msg__srv__Surveillance_Response__Sequence * member =
    (tello_msg__srv__Surveillance_Response__Sequence *)(untyped_member);
  tello_msg__srv__Surveillance_Response__Sequence__fini(member);
  return tello_msg__srv__Surveillance_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__Surveillance_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tello_msg__srv__Surveillance_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(tello_msg__srv__Surveillance_Event, request),  // bytes offset in struct
    NULL,  // default value
    tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__size_function__Surveillance_Event__request,  // size() function pointer
    tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__get_const_function__Surveillance_Event__request,  // get_const(index) function pointer
    tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__get_function__Surveillance_Event__request,  // get(index) function pointer
    tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__fetch_function__Surveillance_Event__request,  // fetch(index, &value) function pointer
    tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__assign_function__Surveillance_Event__request,  // assign(index, value) function pointer
    tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__resize_function__Surveillance_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(tello_msg__srv__Surveillance_Event, response),  // bytes offset in struct
    NULL,  // default value
    tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__size_function__Surveillance_Event__response,  // size() function pointer
    tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__get_const_function__Surveillance_Event__response,  // get_const(index) function pointer
    tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__get_function__Surveillance_Event__response,  // get(index) function pointer
    tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__fetch_function__Surveillance_Event__response,  // fetch(index, &value) function pointer
    tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__assign_function__Surveillance_Event__response,  // assign(index, value) function pointer
    tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__resize_function__Surveillance_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__Surveillance_Event_message_members = {
  "tello_msg__srv",  // message namespace
  "Surveillance_Event",  // message name
  3,  // number of fields
  sizeof(tello_msg__srv__Surveillance_Event),
  false,  // has_any_key_member_
  tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__Surveillance_Event_message_member_array,  // message members
  tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__Surveillance_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__Surveillance_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__Surveillance_Event_message_type_support_handle = {
  0,
  &tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__Surveillance_Event_message_members,
  get_message_typesupport_handle_function,
  &tello_msg__srv__Surveillance_Event__get_type_hash,
  &tello_msg__srv__Surveillance_Event__get_type_description,
  &tello_msg__srv__Surveillance_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tello_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tello_msg, srv, Surveillance_Event)() {
  tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__Surveillance_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__Surveillance_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tello_msg, srv, Surveillance_Request)();
  tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__Surveillance_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tello_msg, srv, Surveillance_Response)();
  if (!tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__Surveillance_Event_message_type_support_handle.typesupport_identifier) {
    tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__Surveillance_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__Surveillance_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "tello_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "tello_msg/srv/detail/surveillance__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers tello_msg__srv__detail__surveillance__rosidl_typesupport_introspection_c__Surveillance_service_members = {
  "tello_msg__srv",  // service namespace
  "Surveillance",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // tello_msg__srv__detail__surveillance__rosidl_typesupport_introspection_c__Surveillance_Request_message_type_support_handle,
  NULL,  // response message
  // tello_msg__srv__detail__surveillance__rosidl_typesupport_introspection_c__Surveillance_Response_message_type_support_handle
  NULL  // event_message
  // tello_msg__srv__detail__surveillance__rosidl_typesupport_introspection_c__Surveillance_Response_message_type_support_handle
};


static rosidl_service_type_support_t tello_msg__srv__detail__surveillance__rosidl_typesupport_introspection_c__Surveillance_service_type_support_handle = {
  0,
  &tello_msg__srv__detail__surveillance__rosidl_typesupport_introspection_c__Surveillance_service_members,
  get_service_typesupport_handle_function,
  &tello_msg__srv__Surveillance_Request__rosidl_typesupport_introspection_c__Surveillance_Request_message_type_support_handle,
  &tello_msg__srv__Surveillance_Response__rosidl_typesupport_introspection_c__Surveillance_Response_message_type_support_handle,
  &tello_msg__srv__Surveillance_Event__rosidl_typesupport_introspection_c__Surveillance_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    tello_msg,
    srv,
    Surveillance
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    tello_msg,
    srv,
    Surveillance
  ),
  &tello_msg__srv__Surveillance__get_type_hash,
  &tello_msg__srv__Surveillance__get_type_description,
  &tello_msg__srv__Surveillance__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tello_msg, srv, Surveillance_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tello_msg, srv, Surveillance_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tello_msg, srv, Surveillance_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tello_msg
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tello_msg, srv, Surveillance)(void) {
  if (!tello_msg__srv__detail__surveillance__rosidl_typesupport_introspection_c__Surveillance_service_type_support_handle.typesupport_identifier) {
    tello_msg__srv__detail__surveillance__rosidl_typesupport_introspection_c__Surveillance_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)tello_msg__srv__detail__surveillance__rosidl_typesupport_introspection_c__Surveillance_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tello_msg, srv, Surveillance_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tello_msg, srv, Surveillance_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tello_msg, srv, Surveillance_Event)()->data;
  }

  return &tello_msg__srv__detail__surveillance__rosidl_typesupport_introspection_c__Surveillance_service_type_support_handle;
}
