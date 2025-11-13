// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tello_msg:srv/DroneMode.idl
// generated code does not contain a copyright notice
#include "tello_msg/srv/detail/drone_mode__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
tello_msg__srv__DroneMode_Request__init(tello_msg__srv__DroneMode_Request * msg)
{
  if (!msg) {
    return false;
  }
  // mode
  return true;
}

void
tello_msg__srv__DroneMode_Request__fini(tello_msg__srv__DroneMode_Request * msg)
{
  if (!msg) {
    return;
  }
  // mode
}

bool
tello_msg__srv__DroneMode_Request__are_equal(const tello_msg__srv__DroneMode_Request * lhs, const tello_msg__srv__DroneMode_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  return true;
}

bool
tello_msg__srv__DroneMode_Request__copy(
  const tello_msg__srv__DroneMode_Request * input,
  tello_msg__srv__DroneMode_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // mode
  output->mode = input->mode;
  return true;
}

tello_msg__srv__DroneMode_Request *
tello_msg__srv__DroneMode_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tello_msg__srv__DroneMode_Request * msg = (tello_msg__srv__DroneMode_Request *)allocator.allocate(sizeof(tello_msg__srv__DroneMode_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tello_msg__srv__DroneMode_Request));
  bool success = tello_msg__srv__DroneMode_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tello_msg__srv__DroneMode_Request__destroy(tello_msg__srv__DroneMode_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tello_msg__srv__DroneMode_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tello_msg__srv__DroneMode_Request__Sequence__init(tello_msg__srv__DroneMode_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tello_msg__srv__DroneMode_Request * data = NULL;

  if (size) {
    data = (tello_msg__srv__DroneMode_Request *)allocator.zero_allocate(size, sizeof(tello_msg__srv__DroneMode_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tello_msg__srv__DroneMode_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tello_msg__srv__DroneMode_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tello_msg__srv__DroneMode_Request__Sequence__fini(tello_msg__srv__DroneMode_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tello_msg__srv__DroneMode_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tello_msg__srv__DroneMode_Request__Sequence *
tello_msg__srv__DroneMode_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tello_msg__srv__DroneMode_Request__Sequence * array = (tello_msg__srv__DroneMode_Request__Sequence *)allocator.allocate(sizeof(tello_msg__srv__DroneMode_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tello_msg__srv__DroneMode_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tello_msg__srv__DroneMode_Request__Sequence__destroy(tello_msg__srv__DroneMode_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tello_msg__srv__DroneMode_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tello_msg__srv__DroneMode_Request__Sequence__are_equal(const tello_msg__srv__DroneMode_Request__Sequence * lhs, const tello_msg__srv__DroneMode_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tello_msg__srv__DroneMode_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tello_msg__srv__DroneMode_Request__Sequence__copy(
  const tello_msg__srv__DroneMode_Request__Sequence * input,
  tello_msg__srv__DroneMode_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tello_msg__srv__DroneMode_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tello_msg__srv__DroneMode_Request * data =
      (tello_msg__srv__DroneMode_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tello_msg__srv__DroneMode_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tello_msg__srv__DroneMode_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tello_msg__srv__DroneMode_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
tello_msg__srv__DroneMode_Response__init(tello_msg__srv__DroneMode_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    tello_msg__srv__DroneMode_Response__fini(msg);
    return false;
  }
  return true;
}

void
tello_msg__srv__DroneMode_Response__fini(tello_msg__srv__DroneMode_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
tello_msg__srv__DroneMode_Response__are_equal(const tello_msg__srv__DroneMode_Response * lhs, const tello_msg__srv__DroneMode_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
tello_msg__srv__DroneMode_Response__copy(
  const tello_msg__srv__DroneMode_Response * input,
  tello_msg__srv__DroneMode_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

tello_msg__srv__DroneMode_Response *
tello_msg__srv__DroneMode_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tello_msg__srv__DroneMode_Response * msg = (tello_msg__srv__DroneMode_Response *)allocator.allocate(sizeof(tello_msg__srv__DroneMode_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tello_msg__srv__DroneMode_Response));
  bool success = tello_msg__srv__DroneMode_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tello_msg__srv__DroneMode_Response__destroy(tello_msg__srv__DroneMode_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tello_msg__srv__DroneMode_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tello_msg__srv__DroneMode_Response__Sequence__init(tello_msg__srv__DroneMode_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tello_msg__srv__DroneMode_Response * data = NULL;

  if (size) {
    data = (tello_msg__srv__DroneMode_Response *)allocator.zero_allocate(size, sizeof(tello_msg__srv__DroneMode_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tello_msg__srv__DroneMode_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tello_msg__srv__DroneMode_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tello_msg__srv__DroneMode_Response__Sequence__fini(tello_msg__srv__DroneMode_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tello_msg__srv__DroneMode_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tello_msg__srv__DroneMode_Response__Sequence *
tello_msg__srv__DroneMode_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tello_msg__srv__DroneMode_Response__Sequence * array = (tello_msg__srv__DroneMode_Response__Sequence *)allocator.allocate(sizeof(tello_msg__srv__DroneMode_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tello_msg__srv__DroneMode_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tello_msg__srv__DroneMode_Response__Sequence__destroy(tello_msg__srv__DroneMode_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tello_msg__srv__DroneMode_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tello_msg__srv__DroneMode_Response__Sequence__are_equal(const tello_msg__srv__DroneMode_Response__Sequence * lhs, const tello_msg__srv__DroneMode_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tello_msg__srv__DroneMode_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tello_msg__srv__DroneMode_Response__Sequence__copy(
  const tello_msg__srv__DroneMode_Response__Sequence * input,
  tello_msg__srv__DroneMode_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tello_msg__srv__DroneMode_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tello_msg__srv__DroneMode_Response * data =
      (tello_msg__srv__DroneMode_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tello_msg__srv__DroneMode_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tello_msg__srv__DroneMode_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tello_msg__srv__DroneMode_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "tello_msg/srv/detail/drone_mode__functions.h"

bool
tello_msg__srv__DroneMode_Event__init(tello_msg__srv__DroneMode_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    tello_msg__srv__DroneMode_Event__fini(msg);
    return false;
  }
  // request
  if (!tello_msg__srv__DroneMode_Request__Sequence__init(&msg->request, 0)) {
    tello_msg__srv__DroneMode_Event__fini(msg);
    return false;
  }
  // response
  if (!tello_msg__srv__DroneMode_Response__Sequence__init(&msg->response, 0)) {
    tello_msg__srv__DroneMode_Event__fini(msg);
    return false;
  }
  return true;
}

void
tello_msg__srv__DroneMode_Event__fini(tello_msg__srv__DroneMode_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  tello_msg__srv__DroneMode_Request__Sequence__fini(&msg->request);
  // response
  tello_msg__srv__DroneMode_Response__Sequence__fini(&msg->response);
}

bool
tello_msg__srv__DroneMode_Event__are_equal(const tello_msg__srv__DroneMode_Event * lhs, const tello_msg__srv__DroneMode_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!tello_msg__srv__DroneMode_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!tello_msg__srv__DroneMode_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
tello_msg__srv__DroneMode_Event__copy(
  const tello_msg__srv__DroneMode_Event * input,
  tello_msg__srv__DroneMode_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!tello_msg__srv__DroneMode_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!tello_msg__srv__DroneMode_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

tello_msg__srv__DroneMode_Event *
tello_msg__srv__DroneMode_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tello_msg__srv__DroneMode_Event * msg = (tello_msg__srv__DroneMode_Event *)allocator.allocate(sizeof(tello_msg__srv__DroneMode_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tello_msg__srv__DroneMode_Event));
  bool success = tello_msg__srv__DroneMode_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tello_msg__srv__DroneMode_Event__destroy(tello_msg__srv__DroneMode_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tello_msg__srv__DroneMode_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tello_msg__srv__DroneMode_Event__Sequence__init(tello_msg__srv__DroneMode_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tello_msg__srv__DroneMode_Event * data = NULL;

  if (size) {
    data = (tello_msg__srv__DroneMode_Event *)allocator.zero_allocate(size, sizeof(tello_msg__srv__DroneMode_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tello_msg__srv__DroneMode_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tello_msg__srv__DroneMode_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tello_msg__srv__DroneMode_Event__Sequence__fini(tello_msg__srv__DroneMode_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tello_msg__srv__DroneMode_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tello_msg__srv__DroneMode_Event__Sequence *
tello_msg__srv__DroneMode_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tello_msg__srv__DroneMode_Event__Sequence * array = (tello_msg__srv__DroneMode_Event__Sequence *)allocator.allocate(sizeof(tello_msg__srv__DroneMode_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tello_msg__srv__DroneMode_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tello_msg__srv__DroneMode_Event__Sequence__destroy(tello_msg__srv__DroneMode_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tello_msg__srv__DroneMode_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tello_msg__srv__DroneMode_Event__Sequence__are_equal(const tello_msg__srv__DroneMode_Event__Sequence * lhs, const tello_msg__srv__DroneMode_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tello_msg__srv__DroneMode_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tello_msg__srv__DroneMode_Event__Sequence__copy(
  const tello_msg__srv__DroneMode_Event__Sequence * input,
  tello_msg__srv__DroneMode_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tello_msg__srv__DroneMode_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tello_msg__srv__DroneMode_Event * data =
      (tello_msg__srv__DroneMode_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tello_msg__srv__DroneMode_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tello_msg__srv__DroneMode_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tello_msg__srv__DroneMode_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
