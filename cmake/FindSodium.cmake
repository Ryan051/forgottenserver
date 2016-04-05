# Locate Sodium library
# This module defines
#   SODIUM_FOUND
#   SODIUM_INCLUDE_DIR
#   SODIUM_LIBRARIES

find_path(SODIUM_INCLUDE_DIR NAMES sodium.h)
find_library(SODIUM_LIBRARIES NAMES sodium libsodium)

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(Sodium DEFAULT_MSG SODIUM_INCLUDE_DIR SODIUM_LIBRARIES)

mark_as_advanced(SODIUM_INCLUDE_DIR SODIUM_LIBRARIES)
