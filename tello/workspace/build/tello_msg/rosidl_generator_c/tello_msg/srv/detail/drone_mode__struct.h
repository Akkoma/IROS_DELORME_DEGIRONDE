// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tello_msg:srv/DroneMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tello_msg/srv/drone_mode.h"


#ifndef TELLO_MSG__SRV__DETAIL__DRONE_MODE__STRUCT_H_
#define TELLO_MSG__SRV__DETAIL__DRONE_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/DroneMode in the package tello_msg.
typedef struct tello_msg__srv__DroneMode_Request
{
  int32_t mode;
} tello_msg__srv__DroneMode_Request;

// Struct for a sequence of tello_msg__srv__DroneMode_Request.
typedef struct tello_msg__srv__DroneMode_Request__Sequence
{
  tello_msg__srv__DroneMode_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tello_msg__srv__DroneMode_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/DroneMode in the package tello_msg.
typedef struct tello_msg__srv__DroneMode_Response
{
  bool success;
  rosidl_runtime_c__String message;
} tello_msg__srv__DroneMode_Response;

// Struct for a sequence of tello_msg__srv__DroneMode_Response.
typedef struct tello_msg__srv__DroneMode_Response__Sequence
{
  tello_msg__srv__DroneMode_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tello_msg__srv__DroneMode_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  tello_msg__srv__DroneMode_Event__request__MAX_SIZE = 1
};
// response
enum
{
  tello_msg__srv__DroneMode_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/DroneMode in the package tello_msg.
typedef struct tello_msg__srv__DroneMode_Event
{
  service_msgs__msg__ServiceEventInfo info;
  tello_msg__srv__DroneMode_Request__Sequence request;
  tello_msg__srv__DroneMode_Response__Sequence response;
} tello_msg__srv__DroneMode_Event;

// Struct for a sequence of tello_msg__srv__DroneMode_Event.
typedef struct tello_msg__srv__DroneMode_Event__Sequence
{
  tello_msg__srv__DroneMode_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tello_msg__srv__DroneMode_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TELLO_MSG__SRV__DETAIL__DRONE_MODE__STRUCT_H_
