// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from tello_msg:msg/TelloStatus.idl
// generated code does not contain a copyright notice

#include "tello_msg/msg/detail/tello_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_type_hash_t *
tello_msg__msg__TelloStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc3, 0x61, 0xe5, 0x95, 0xdf, 0x61, 0x61, 0xc0,
      0xd7, 0x14, 0x36, 0x8a, 0xb0, 0x81, 0x87, 0xb6,
      0x59, 0x0e, 0x25, 0x39, 0xc3, 0xe0, 0x50, 0xe4,
      0xb3, 0xb1, 0xa4, 0x4f, 0x96, 0xee, 0xc8, 0xee,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "geometry_msgs/msg/detail/vector3__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t geometry_msgs__msg__Vector3__EXPECTED_HASH = {1, {
    0xcc, 0x12, 0xfe, 0x83, 0xe4, 0xc0, 0x27, 0x19,
    0xf1, 0xce, 0x80, 0x70, 0xbf, 0xd1, 0x4a, 0xec,
    0xd4, 0x0f, 0x75, 0xa9, 0x66, 0x96, 0xa6, 0x7a,
    0x2a, 0x1f, 0x37, 0xf7, 0xdb, 0xb0, 0x76, 0x5d,
  }};
#endif

static char tello_msg__msg__TelloStatus__TYPE_NAME[] = "tello_msg/msg/TelloStatus";
static char geometry_msgs__msg__Vector3__TYPE_NAME[] = "geometry_msgs/msg/Vector3";

// Define type names, field names, and default values
static char tello_msg__msg__TelloStatus__FIELD_NAME__acceleration[] = "acceleration";
static char tello_msg__msg__TelloStatus__FIELD_NAME__speed[] = "speed";
static char tello_msg__msg__TelloStatus__FIELD_NAME__barometer[] = "barometer";
static char tello_msg__msg__TelloStatus__FIELD_NAME__distance_tof[] = "distance_tof";
static char tello_msg__msg__TelloStatus__FIELD_NAME__battery[] = "battery";
static char tello_msg__msg__TelloStatus__FIELD_NAME__fligth_time[] = "fligth_time";
static char tello_msg__msg__TelloStatus__FIELD_NAME__highest_temperature[] = "highest_temperature";
static char tello_msg__msg__TelloStatus__FIELD_NAME__lowest_temperature[] = "lowest_temperature";
static char tello_msg__msg__TelloStatus__FIELD_NAME__temperature[] = "temperature";
static char tello_msg__msg__TelloStatus__FIELD_NAME__pitch[] = "pitch";
static char tello_msg__msg__TelloStatus__FIELD_NAME__roll[] = "roll";
static char tello_msg__msg__TelloStatus__FIELD_NAME__yaw[] = "yaw";
static char tello_msg__msg__TelloStatus__FIELD_NAME__wifi_snr[] = "wifi_snr";

static rosidl_runtime_c__type_description__Field tello_msg__msg__TelloStatus__FIELDS[] = {
  {
    {tello_msg__msg__TelloStatus__FIELD_NAME__acceleration, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    },
    {NULL, 0, 0},
  },
  {
    {tello_msg__msg__TelloStatus__FIELD_NAME__speed, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    },
    {NULL, 0, 0},
  },
  {
    {tello_msg__msg__TelloStatus__FIELD_NAME__barometer, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tello_msg__msg__TelloStatus__FIELD_NAME__distance_tof, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tello_msg__msg__TelloStatus__FIELD_NAME__battery, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tello_msg__msg__TelloStatus__FIELD_NAME__fligth_time, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tello_msg__msg__TelloStatus__FIELD_NAME__highest_temperature, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tello_msg__msg__TelloStatus__FIELD_NAME__lowest_temperature, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tello_msg__msg__TelloStatus__FIELD_NAME__temperature, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tello_msg__msg__TelloStatus__FIELD_NAME__pitch, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tello_msg__msg__TelloStatus__FIELD_NAME__roll, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tello_msg__msg__TelloStatus__FIELD_NAME__yaw, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tello_msg__msg__TelloStatus__FIELD_NAME__wifi_snr, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription tello_msg__msg__TelloStatus__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tello_msg__msg__TelloStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tello_msg__msg__TelloStatus__TYPE_NAME, 25, 25},
      {tello_msg__msg__TelloStatus__FIELDS, 13, 13},
    },
    {tello_msg__msg__TelloStatus__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&geometry_msgs__msg__Vector3__EXPECTED_HASH, geometry_msgs__msg__Vector3__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = geometry_msgs__msg__Vector3__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Acceleration from IMU\n"
  "geometry_msgs/Vector3 acceleration\n"
  "\n"
  "# Speed from IMU\n"
  "geometry_msgs/Vector3 speed\n"
  "\n"
  "# Altitude of the drone from sensor\n"
  "int32 barometer\n"
  "int32 distance_tof\n"
  "\n"
  "# Percentage of battery left\n"
  "uint8 battery\n"
  "\n"
  "# Time the motors have been active in seconds\n"
  "int32 fligth_time\n"
  "\n"
  "# Highest temperature in celsium\n"
  "int32 highest_temperature\n"
  "# Lowest temperature in celsium\n"
  "int32 lowest_temperature\n"
  "# Temperature in celsium\n"
  "float32 temperature\n"
  "\n"
  "# Pitch in degrees\n"
  "int32 pitch\n"
  "# Roll in degrees\n"
  "int32 roll\n"
  "# Yaw in degrees\n"
  "int32 yaw\n"
  "\n"
  "# Wi-Fi SNR\n"
  "string wifi_snr";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
tello_msg__msg__TelloStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tello_msg__msg__TelloStatus__TYPE_NAME, 25, 25},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 565, 565},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tello_msg__msg__TelloStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tello_msg__msg__TelloStatus__get_individual_type_description_source(NULL),
    sources[1] = *geometry_msgs__msg__Vector3__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
