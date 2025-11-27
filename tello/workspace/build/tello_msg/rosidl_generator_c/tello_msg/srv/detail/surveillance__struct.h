// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tello_msg:srv/Surveillance.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tello_msg/srv/surveillance.h"


#ifndef TELLO_MSG__SRV__DETAIL__SURVEILLANCE__STRUCT_H_
#define TELLO_MSG__SRV__DETAIL__SURVEILLANCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Surveillance in the package tello_msg.
typedef struct tello_msg__srv__Surveillance_Request
{
  bool data;
} tello_msg__srv__Surveillance_Request;

// Struct for a sequence of tello_msg__srv__Surveillance_Request.
typedef struct tello_msg__srv__Surveillance_Request__Sequence
{
  tello_msg__srv__Surveillance_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tello_msg__srv__Surveillance_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/Surveillance in the package tello_msg.
typedef struct tello_msg__srv__Surveillance_Response
{
  bool success;
} tello_msg__srv__Surveillance_Response;

// Struct for a sequence of tello_msg__srv__Surveillance_Response.
typedef struct tello_msg__srv__Surveillance_Response__Sequence
{
  tello_msg__srv__Surveillance_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tello_msg__srv__Surveillance_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  tello_msg__srv__Surveillance_Event__request__MAX_SIZE = 1
};
// response
enum
{
  tello_msg__srv__Surveillance_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/Surveillance in the package tello_msg.
typedef struct tello_msg__srv__Surveillance_Event
{
  service_msgs__msg__ServiceEventInfo info;
  tello_msg__srv__Surveillance_Request__Sequence request;
  tello_msg__srv__Surveillance_Response__Sequence response;
} tello_msg__srv__Surveillance_Event;

// Struct for a sequence of tello_msg__srv__Surveillance_Event.
typedef struct tello_msg__srv__Surveillance_Event__Sequence
{
  tello_msg__srv__Surveillance_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tello_msg__srv__Surveillance_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TELLO_MSG__SRV__DETAIL__SURVEILLANCE__STRUCT_H_
