// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from tello_msg:srv/DroneMode.idl
// generated code does not contain a copyright notice

#include "tello_msg/srv/detail/drone_mode__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_type_hash_t *
tello_msg__srv__DroneMode__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9f, 0xa4, 0x4a, 0x4e, 0x18, 0xa2, 0x20, 0x8e,
      0xb2, 0xe1, 0xf8, 0x3d, 0x94, 0xcb, 0xd7, 0x7d,
      0x7b, 0xc5, 0x59, 0xe4, 0xf1, 0xe1, 0x89, 0x86,
      0xe6, 0x5b, 0xa9, 0x20, 0xca, 0xa2, 0xa1, 0xd3,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_type_hash_t *
tello_msg__srv__DroneMode_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xcb, 0xd8, 0xc2, 0xbb, 0x55, 0x49, 0xa4, 0x56,
      0x90, 0xfb, 0x76, 0x58, 0xc4, 0x66, 0x0e, 0xc2,
      0xac, 0xbc, 0x54, 0x21, 0x7d, 0xf0, 0x9e, 0xbf,
      0x73, 0x87, 0x78, 0xdd, 0x48, 0xae, 0x72, 0xa4,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_type_hash_t *
tello_msg__srv__DroneMode_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xfd, 0x7a, 0x23, 0xe5, 0xe3, 0x74, 0xa3, 0x46,
      0xdb, 0xf8, 0x8d, 0xbc, 0xc9, 0x12, 0x66, 0x24,
      0x47, 0xbc, 0x43, 0x76, 0x69, 0xdc, 0x4a, 0xe9,
      0x1c, 0x2e, 0x9f, 0x0a, 0x1d, 0x09, 0x5d, 0xc6,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_tello_msg
const rosidl_type_hash_t *
tello_msg__srv__DroneMode_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x37, 0xdf, 0xf3, 0x3b, 0x26, 0xa1, 0x62, 0x5b,
      0xd6, 0xba, 0xb2, 0xdf, 0xd7, 0xbe, 0x82, 0x1f,
      0xf7, 0xdc, 0xdf, 0x51, 0xda, 0x0e, 0x04, 0x10,
      0x32, 0x8b, 0xf3, 0x5b, 0xa8, 0xa3, 0xcd, 0x2b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char tello_msg__srv__DroneMode__TYPE_NAME[] = "tello_msg/srv/DroneMode";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char tello_msg__srv__DroneMode_Event__TYPE_NAME[] = "tello_msg/srv/DroneMode_Event";
static char tello_msg__srv__DroneMode_Request__TYPE_NAME[] = "tello_msg/srv/DroneMode_Request";
static char tello_msg__srv__DroneMode_Response__TYPE_NAME[] = "tello_msg/srv/DroneMode_Response";

// Define type names, field names, and default values
static char tello_msg__srv__DroneMode__FIELD_NAME__request_message[] = "request_message";
static char tello_msg__srv__DroneMode__FIELD_NAME__response_message[] = "response_message";
static char tello_msg__srv__DroneMode__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field tello_msg__srv__DroneMode__FIELDS[] = {
  {
    {tello_msg__srv__DroneMode__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {tello_msg__srv__DroneMode_Request__TYPE_NAME, 31, 31},
    },
    {NULL, 0, 0},
  },
  {
    {tello_msg__srv__DroneMode__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {tello_msg__srv__DroneMode_Response__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
  {
    {tello_msg__srv__DroneMode__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {tello_msg__srv__DroneMode_Event__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription tello_msg__srv__DroneMode__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {tello_msg__srv__DroneMode_Event__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {tello_msg__srv__DroneMode_Request__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
  {
    {tello_msg__srv__DroneMode_Response__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tello_msg__srv__DroneMode__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tello_msg__srv__DroneMode__TYPE_NAME, 23, 23},
      {tello_msg__srv__DroneMode__FIELDS, 3, 3},
    },
    {tello_msg__srv__DroneMode__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = tello_msg__srv__DroneMode_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = tello_msg__srv__DroneMode_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = tello_msg__srv__DroneMode_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char tello_msg__srv__DroneMode_Request__FIELD_NAME__mode[] = "mode";

static rosidl_runtime_c__type_description__Field tello_msg__srv__DroneMode_Request__FIELDS[] = {
  {
    {tello_msg__srv__DroneMode_Request__FIELD_NAME__mode, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tello_msg__srv__DroneMode_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tello_msg__srv__DroneMode_Request__TYPE_NAME, 31, 31},
      {tello_msg__srv__DroneMode_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char tello_msg__srv__DroneMode_Response__FIELD_NAME__success[] = "success";
static char tello_msg__srv__DroneMode_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field tello_msg__srv__DroneMode_Response__FIELDS[] = {
  {
    {tello_msg__srv__DroneMode_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tello_msg__srv__DroneMode_Response__FIELD_NAME__message, 7, 7},
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
tello_msg__srv__DroneMode_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tello_msg__srv__DroneMode_Response__TYPE_NAME, 32, 32},
      {tello_msg__srv__DroneMode_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char tello_msg__srv__DroneMode_Event__FIELD_NAME__info[] = "info";
static char tello_msg__srv__DroneMode_Event__FIELD_NAME__request[] = "request";
static char tello_msg__srv__DroneMode_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field tello_msg__srv__DroneMode_Event__FIELDS[] = {
  {
    {tello_msg__srv__DroneMode_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {tello_msg__srv__DroneMode_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {tello_msg__srv__DroneMode_Request__TYPE_NAME, 31, 31},
    },
    {NULL, 0, 0},
  },
  {
    {tello_msg__srv__DroneMode_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {tello_msg__srv__DroneMode_Response__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription tello_msg__srv__DroneMode_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {tello_msg__srv__DroneMode_Request__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
  {
    {tello_msg__srv__DroneMode_Response__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tello_msg__srv__DroneMode_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tello_msg__srv__DroneMode_Event__TYPE_NAME, 29, 29},
      {tello_msg__srv__DroneMode_Event__FIELDS, 3, 3},
    },
    {tello_msg__srv__DroneMode_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = tello_msg__srv__DroneMode_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = tello_msg__srv__DroneMode_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Service pour changer le mode du drone\n"
  "# Modes:\n"
  "# 0 = Manuel\n"
  "# 1 = QR Code Follower\n"
  "# 2 = Spielberg\n"
  "# 3 = Surveillance\n"
  "\n"
  "int32 mode\n"
  "---\n"
  "bool success\n"
  "string message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
tello_msg__srv__DroneMode__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tello_msg__srv__DroneMode__TYPE_NAME, 23, 23},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 164, 164},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
tello_msg__srv__DroneMode_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tello_msg__srv__DroneMode_Request__TYPE_NAME, 31, 31},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
tello_msg__srv__DroneMode_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tello_msg__srv__DroneMode_Response__TYPE_NAME, 32, 32},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
tello_msg__srv__DroneMode_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tello_msg__srv__DroneMode_Event__TYPE_NAME, 29, 29},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tello_msg__srv__DroneMode__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tello_msg__srv__DroneMode__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *tello_msg__srv__DroneMode_Event__get_individual_type_description_source(NULL);
    sources[4] = *tello_msg__srv__DroneMode_Request__get_individual_type_description_source(NULL);
    sources[5] = *tello_msg__srv__DroneMode_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tello_msg__srv__DroneMode_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tello_msg__srv__DroneMode_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tello_msg__srv__DroneMode_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tello_msg__srv__DroneMode_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tello_msg__srv__DroneMode_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tello_msg__srv__DroneMode_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *tello_msg__srv__DroneMode_Request__get_individual_type_description_source(NULL);
    sources[4] = *tello_msg__srv__DroneMode_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
