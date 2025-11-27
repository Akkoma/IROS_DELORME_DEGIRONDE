// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from tello_msg:srv/DroneMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tello_msg/srv/drone_mode.h"


#ifndef TELLO_MSG__SRV__DETAIL__DRONE_MODE__FUNCTIONS_H_
#define TELLO_MSG__SRV__DETAIL__DRONE_MODE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "tello_msg/msg/rosidl_generator_c__visibility_control.h"

#include "tello_msg/srv/detail/drone_mode__struct.h"

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_type_hash_t *
tello_msg__srv__DroneMode__get_type_hash(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_runtime_c__type_description__TypeDescription *
tello_msg__srv__DroneMode__get_type_description(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_runtime_c__type_description__TypeSource *
tello_msg__srv__DroneMode__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_runtime_c__type_description__TypeSource__Sequence *
tello_msg__srv__DroneMode__get_type_description_sources(
  const rosidl_service_type_support_t * type_support);

/// Initialize srv/DroneMode message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tello_msg__srv__DroneMode_Request
 * )) before or use
 * tello_msg__srv__DroneMode_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
bool
tello_msg__srv__DroneMode_Request__init(tello_msg__srv__DroneMode_Request * msg);

/// Finalize srv/DroneMode message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
void
tello_msg__srv__DroneMode_Request__fini(tello_msg__srv__DroneMode_Request * msg);

/// Create srv/DroneMode message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tello_msg__srv__DroneMode_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
tello_msg__srv__DroneMode_Request *
tello_msg__srv__DroneMode_Request__create(void);

/// Destroy srv/DroneMode message.
/**
 * It calls
 * tello_msg__srv__DroneMode_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
void
tello_msg__srv__DroneMode_Request__destroy(tello_msg__srv__DroneMode_Request * msg);

/// Check for srv/DroneMode message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
bool
tello_msg__srv__DroneMode_Request__are_equal(const tello_msg__srv__DroneMode_Request * lhs, const tello_msg__srv__DroneMode_Request * rhs);

/// Copy a srv/DroneMode message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
bool
tello_msg__srv__DroneMode_Request__copy(
  const tello_msg__srv__DroneMode_Request * input,
  tello_msg__srv__DroneMode_Request * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_type_hash_t *
tello_msg__srv__DroneMode_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_runtime_c__type_description__TypeDescription *
tello_msg__srv__DroneMode_Request__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_runtime_c__type_description__TypeSource *
tello_msg__srv__DroneMode_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_runtime_c__type_description__TypeSource__Sequence *
tello_msg__srv__DroneMode_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/DroneMode messages.
/**
 * It allocates the memory for the number of elements and calls
 * tello_msg__srv__DroneMode_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
bool
tello_msg__srv__DroneMode_Request__Sequence__init(tello_msg__srv__DroneMode_Request__Sequence * array, size_t size);

/// Finalize array of srv/DroneMode messages.
/**
 * It calls
 * tello_msg__srv__DroneMode_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
void
tello_msg__srv__DroneMode_Request__Sequence__fini(tello_msg__srv__DroneMode_Request__Sequence * array);

/// Create array of srv/DroneMode messages.
/**
 * It allocates the memory for the array and calls
 * tello_msg__srv__DroneMode_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
tello_msg__srv__DroneMode_Request__Sequence *
tello_msg__srv__DroneMode_Request__Sequence__create(size_t size);

/// Destroy array of srv/DroneMode messages.
/**
 * It calls
 * tello_msg__srv__DroneMode_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
void
tello_msg__srv__DroneMode_Request__Sequence__destroy(tello_msg__srv__DroneMode_Request__Sequence * array);

/// Check for srv/DroneMode message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
bool
tello_msg__srv__DroneMode_Request__Sequence__are_equal(const tello_msg__srv__DroneMode_Request__Sequence * lhs, const tello_msg__srv__DroneMode_Request__Sequence * rhs);

/// Copy an array of srv/DroneMode messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
bool
tello_msg__srv__DroneMode_Request__Sequence__copy(
  const tello_msg__srv__DroneMode_Request__Sequence * input,
  tello_msg__srv__DroneMode_Request__Sequence * output);

/// Initialize srv/DroneMode message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tello_msg__srv__DroneMode_Response
 * )) before or use
 * tello_msg__srv__DroneMode_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
bool
tello_msg__srv__DroneMode_Response__init(tello_msg__srv__DroneMode_Response * msg);

/// Finalize srv/DroneMode message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
void
tello_msg__srv__DroneMode_Response__fini(tello_msg__srv__DroneMode_Response * msg);

/// Create srv/DroneMode message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tello_msg__srv__DroneMode_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
tello_msg__srv__DroneMode_Response *
tello_msg__srv__DroneMode_Response__create(void);

/// Destroy srv/DroneMode message.
/**
 * It calls
 * tello_msg__srv__DroneMode_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
void
tello_msg__srv__DroneMode_Response__destroy(tello_msg__srv__DroneMode_Response * msg);

/// Check for srv/DroneMode message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
bool
tello_msg__srv__DroneMode_Response__are_equal(const tello_msg__srv__DroneMode_Response * lhs, const tello_msg__srv__DroneMode_Response * rhs);

/// Copy a srv/DroneMode message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
bool
tello_msg__srv__DroneMode_Response__copy(
  const tello_msg__srv__DroneMode_Response * input,
  tello_msg__srv__DroneMode_Response * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_type_hash_t *
tello_msg__srv__DroneMode_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_runtime_c__type_description__TypeDescription *
tello_msg__srv__DroneMode_Response__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_runtime_c__type_description__TypeSource *
tello_msg__srv__DroneMode_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_runtime_c__type_description__TypeSource__Sequence *
tello_msg__srv__DroneMode_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/DroneMode messages.
/**
 * It allocates the memory for the number of elements and calls
 * tello_msg__srv__DroneMode_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
bool
tello_msg__srv__DroneMode_Response__Sequence__init(tello_msg__srv__DroneMode_Response__Sequence * array, size_t size);

/// Finalize array of srv/DroneMode messages.
/**
 * It calls
 * tello_msg__srv__DroneMode_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
void
tello_msg__srv__DroneMode_Response__Sequence__fini(tello_msg__srv__DroneMode_Response__Sequence * array);

/// Create array of srv/DroneMode messages.
/**
 * It allocates the memory for the array and calls
 * tello_msg__srv__DroneMode_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
tello_msg__srv__DroneMode_Response__Sequence *
tello_msg__srv__DroneMode_Response__Sequence__create(size_t size);

/// Destroy array of srv/DroneMode messages.
/**
 * It calls
 * tello_msg__srv__DroneMode_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
void
tello_msg__srv__DroneMode_Response__Sequence__destroy(tello_msg__srv__DroneMode_Response__Sequence * array);

/// Check for srv/DroneMode message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
bool
tello_msg__srv__DroneMode_Response__Sequence__are_equal(const tello_msg__srv__DroneMode_Response__Sequence * lhs, const tello_msg__srv__DroneMode_Response__Sequence * rhs);

/// Copy an array of srv/DroneMode messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
bool
tello_msg__srv__DroneMode_Response__Sequence__copy(
  const tello_msg__srv__DroneMode_Response__Sequence * input,
  tello_msg__srv__DroneMode_Response__Sequence * output);

/// Initialize srv/DroneMode message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tello_msg__srv__DroneMode_Event
 * )) before or use
 * tello_msg__srv__DroneMode_Event__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
bool
tello_msg__srv__DroneMode_Event__init(tello_msg__srv__DroneMode_Event * msg);

/// Finalize srv/DroneMode message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
void
tello_msg__srv__DroneMode_Event__fini(tello_msg__srv__DroneMode_Event * msg);

/// Create srv/DroneMode message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tello_msg__srv__DroneMode_Event__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
tello_msg__srv__DroneMode_Event *
tello_msg__srv__DroneMode_Event__create(void);

/// Destroy srv/DroneMode message.
/**
 * It calls
 * tello_msg__srv__DroneMode_Event__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
void
tello_msg__srv__DroneMode_Event__destroy(tello_msg__srv__DroneMode_Event * msg);

/// Check for srv/DroneMode message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
bool
tello_msg__srv__DroneMode_Event__are_equal(const tello_msg__srv__DroneMode_Event * lhs, const tello_msg__srv__DroneMode_Event * rhs);

/// Copy a srv/DroneMode message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
bool
tello_msg__srv__DroneMode_Event__copy(
  const tello_msg__srv__DroneMode_Event * input,
  tello_msg__srv__DroneMode_Event * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_type_hash_t *
tello_msg__srv__DroneMode_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_runtime_c__type_description__TypeDescription *
tello_msg__srv__DroneMode_Event__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_runtime_c__type_description__TypeSource *
tello_msg__srv__DroneMode_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_runtime_c__type_description__TypeSource__Sequence *
tello_msg__srv__DroneMode_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/DroneMode messages.
/**
 * It allocates the memory for the number of elements and calls
 * tello_msg__srv__DroneMode_Event__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
bool
tello_msg__srv__DroneMode_Event__Sequence__init(tello_msg__srv__DroneMode_Event__Sequence * array, size_t size);

/// Finalize array of srv/DroneMode messages.
/**
 * It calls
 * tello_msg__srv__DroneMode_Event__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
void
tello_msg__srv__DroneMode_Event__Sequence__fini(tello_msg__srv__DroneMode_Event__Sequence * array);

/// Create array of srv/DroneMode messages.
/**
 * It allocates the memory for the array and calls
 * tello_msg__srv__DroneMode_Event__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
tello_msg__srv__DroneMode_Event__Sequence *
tello_msg__srv__DroneMode_Event__Sequence__create(size_t size);

/// Destroy array of srv/DroneMode messages.
/**
 * It calls
 * tello_msg__srv__DroneMode_Event__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
void
tello_msg__srv__DroneMode_Event__Sequence__destroy(tello_msg__srv__DroneMode_Event__Sequence * array);

/// Check for srv/DroneMode message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
bool
tello_msg__srv__DroneMode_Event__Sequence__are_equal(const tello_msg__srv__DroneMode_Event__Sequence * lhs, const tello_msg__srv__DroneMode_Event__Sequence * rhs);

/// Copy an array of srv/DroneMode messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tello_msg
bool
tello_msg__srv__DroneMode_Event__Sequence__copy(
  const tello_msg__srv__DroneMode_Event__Sequence * input,
  tello_msg__srv__DroneMode_Event__Sequence * output);
#ifdef __cplusplus
}
#endif

#endif  // TELLO_MSG__SRV__DETAIL__DRONE_MODE__FUNCTIONS_H_
