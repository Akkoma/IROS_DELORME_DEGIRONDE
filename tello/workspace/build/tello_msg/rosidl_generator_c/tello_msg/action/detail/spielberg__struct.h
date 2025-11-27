// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tello_msg:action/Spielberg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tello_msg/action/spielberg.h"


#ifndef TELLO_MSG__ACTION__DETAIL__SPIELBERG__STRUCT_H_
#define TELLO_MSG__ACTION__DETAIL__SPIELBERG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/Spielberg in the package tello_msg.
typedef struct tello_msg__action__Spielberg_Goal
{
  bool start;
} tello_msg__action__Spielberg_Goal;

// Struct for a sequence of tello_msg__action__Spielberg_Goal.
typedef struct tello_msg__action__Spielberg_Goal__Sequence
{
  tello_msg__action__Spielberg_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tello_msg__action__Spielberg_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Spielberg in the package tello_msg.
typedef struct tello_msg__action__Spielberg_Result
{
  bool success;
  rosidl_runtime_c__String message;
} tello_msg__action__Spielberg_Result;

// Struct for a sequence of tello_msg__action__Spielberg_Result.
typedef struct tello_msg__action__Spielberg_Result__Sequence
{
  tello_msg__action__Spielberg_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tello_msg__action__Spielberg_Result__Sequence;

// Constants defined in the message

/// Struct defined in action/Spielberg in the package tello_msg.
typedef struct tello_msg__action__Spielberg_Feedback
{
  int32_t current_step;
  int32_t total_steps;
  float elapsed_time;
} tello_msg__action__Spielberg_Feedback;

// Struct for a sequence of tello_msg__action__Spielberg_Feedback.
typedef struct tello_msg__action__Spielberg_Feedback__Sequence
{
  tello_msg__action__Spielberg_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tello_msg__action__Spielberg_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "tello_msg/action/detail/spielberg__struct.h"

/// Struct defined in action/Spielberg in the package tello_msg.
typedef struct tello_msg__action__Spielberg_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  tello_msg__action__Spielberg_Goal goal;
} tello_msg__action__Spielberg_SendGoal_Request;

// Struct for a sequence of tello_msg__action__Spielberg_SendGoal_Request.
typedef struct tello_msg__action__Spielberg_SendGoal_Request__Sequence
{
  tello_msg__action__Spielberg_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tello_msg__action__Spielberg_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Spielberg in the package tello_msg.
typedef struct tello_msg__action__Spielberg_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} tello_msg__action__Spielberg_SendGoal_Response;

// Struct for a sequence of tello_msg__action__Spielberg_SendGoal_Response.
typedef struct tello_msg__action__Spielberg_SendGoal_Response__Sequence
{
  tello_msg__action__Spielberg_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tello_msg__action__Spielberg_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  tello_msg__action__Spielberg_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  tello_msg__action__Spielberg_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/Spielberg in the package tello_msg.
typedef struct tello_msg__action__Spielberg_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  tello_msg__action__Spielberg_SendGoal_Request__Sequence request;
  tello_msg__action__Spielberg_SendGoal_Response__Sequence response;
} tello_msg__action__Spielberg_SendGoal_Event;

// Struct for a sequence of tello_msg__action__Spielberg_SendGoal_Event.
typedef struct tello_msg__action__Spielberg_SendGoal_Event__Sequence
{
  tello_msg__action__Spielberg_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tello_msg__action__Spielberg_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Spielberg in the package tello_msg.
typedef struct tello_msg__action__Spielberg_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} tello_msg__action__Spielberg_GetResult_Request;

// Struct for a sequence of tello_msg__action__Spielberg_GetResult_Request.
typedef struct tello_msg__action__Spielberg_GetResult_Request__Sequence
{
  tello_msg__action__Spielberg_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tello_msg__action__Spielberg_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "tello_msg/action/detail/spielberg__struct.h"

/// Struct defined in action/Spielberg in the package tello_msg.
typedef struct tello_msg__action__Spielberg_GetResult_Response
{
  int8_t status;
  tello_msg__action__Spielberg_Result result;
} tello_msg__action__Spielberg_GetResult_Response;

// Struct for a sequence of tello_msg__action__Spielberg_GetResult_Response.
typedef struct tello_msg__action__Spielberg_GetResult_Response__Sequence
{
  tello_msg__action__Spielberg_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tello_msg__action__Spielberg_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  tello_msg__action__Spielberg_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  tello_msg__action__Spielberg_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/Spielberg in the package tello_msg.
typedef struct tello_msg__action__Spielberg_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  tello_msg__action__Spielberg_GetResult_Request__Sequence request;
  tello_msg__action__Spielberg_GetResult_Response__Sequence response;
} tello_msg__action__Spielberg_GetResult_Event;

// Struct for a sequence of tello_msg__action__Spielberg_GetResult_Event.
typedef struct tello_msg__action__Spielberg_GetResult_Event__Sequence
{
  tello_msg__action__Spielberg_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tello_msg__action__Spielberg_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "tello_msg/action/detail/spielberg__struct.h"

/// Struct defined in action/Spielberg in the package tello_msg.
typedef struct tello_msg__action__Spielberg_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  tello_msg__action__Spielberg_Feedback feedback;
} tello_msg__action__Spielberg_FeedbackMessage;

// Struct for a sequence of tello_msg__action__Spielberg_FeedbackMessage.
typedef struct tello_msg__action__Spielberg_FeedbackMessage__Sequence
{
  tello_msg__action__Spielberg_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tello_msg__action__Spielberg_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TELLO_MSG__ACTION__DETAIL__SPIELBERG__STRUCT_H_
