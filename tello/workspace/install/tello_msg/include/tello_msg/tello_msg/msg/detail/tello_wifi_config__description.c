// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from tello_msg:msg/TelloWifiConfig.idl
// generated code does not contain a copyright notice

#include "tello_msg/msg/detail/tello_wifi_config__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_type_hash_t *
tello_msg__msg__TelloWifiConfig__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x3b, 0xee, 0x40, 0xd7, 0x4c, 0x03, 0x16, 0x77,
      0xb1, 0x66, 0xc8, 0xc5, 0x26, 0x46, 0x27, 0x76,
      0x59, 0x69, 0xe0, 0x81, 0x96, 0x10, 0x22, 0x44,
      0x81, 0xa7, 0x13, 0x43, 0x3f, 0xd7, 0x65, 0x02,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char tello_msg__msg__TelloWifiConfig__TYPE_NAME[] = "tello_msg/msg/TelloWifiConfig";

// Define type names, field names, and default values
static char tello_msg__msg__TelloWifiConfig__FIELD_NAME__ssid[] = "ssid";
static char tello_msg__msg__TelloWifiConfig__FIELD_NAME__password[] = "password";

static rosidl_runtime_c__type_description__Field tello_msg__msg__TelloWifiConfig__FIELDS[] = {
  {
    {tello_msg__msg__TelloWifiConfig__FIELD_NAME__ssid, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tello_msg__msg__TelloWifiConfig__FIELD_NAME__password, 8, 8},
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
tello_msg__msg__TelloWifiConfig__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tello_msg__msg__TelloWifiConfig__TYPE_NAME, 29, 29},
      {tello_msg__msg__TelloWifiConfig__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Wifi SSID name\n"
  "string ssid\n"
  "\n"
  "# Wifi network password\n"
  "string password";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
tello_msg__msg__TelloWifiConfig__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tello_msg__msg__TelloWifiConfig__TYPE_NAME, 29, 29},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 69, 69},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tello_msg__msg__TelloWifiConfig__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tello_msg__msg__TelloWifiConfig__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
