// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from tello_msg:msg/TelloID.idl
// generated code does not contain a copyright notice

#include "tello_msg/msg/detail/tello_id__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_type_hash_t *
tello_msg__msg__TelloID__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd8, 0xd2, 0x1d, 0x24, 0x77, 0xbd, 0x01, 0xa9,
      0xf3, 0x44, 0xe8, 0xc2, 0xe1, 0xec, 0x30, 0x7c,
      0xce, 0x9b, 0xb9, 0x66, 0x23, 0x27, 0x6e, 0x94,
      0x43, 0xc7, 0x37, 0xaa, 0x9b, 0xc9, 0x31, 0x90,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char tello_msg__msg__TelloID__TYPE_NAME[] = "tello_msg/msg/TelloID";

// Define type names, field names, and default values
static char tello_msg__msg__TelloID__FIELD_NAME__sdk_version[] = "sdk_version";
static char tello_msg__msg__TelloID__FIELD_NAME__serial_number[] = "serial_number";

static rosidl_runtime_c__type_description__Field tello_msg__msg__TelloID__FIELDS[] = {
  {
    {tello_msg__msg__TelloID__FIELD_NAME__sdk_version, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tello_msg__msg__TelloID__FIELD_NAME__serial_number, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tello_msg__msg__TelloID__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tello_msg__msg__TelloID__TYPE_NAME, 21, 21},
      {tello_msg__msg__TelloID__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# SDK version\n"
  "string sdk_version\n"
  "\n"
  "# Serial number\n"
  "string serial_number";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
tello_msg__msg__TelloID__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tello_msg__msg__TelloID__TYPE_NAME, 21, 21},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 70, 70},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tello_msg__msg__TelloID__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tello_msg__msg__TelloID__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
