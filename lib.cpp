#include "lib.h"

bool operator==(const version_info& lhs, const version_info& rhs) {
  if ((lhs.major == rhs.major)
    && (lhs.minor == rhs.minor)
    && (lhs.patch == rhs.patch))
    return true;
  return false;
}

bool operator!=(const version_info& lhs, const version_info& rhs) {
  return !(lhs == rhs);
}

bool operator<(const version_info& lhs, const version_info& rhs) {
  if (lhs.major < rhs.major)
    return true;
  if (lhs.minor < rhs.minor)
    return true;
  if (lhs.patch < rhs.patch)
    return true;
  return false;
}

bool operator>(const version_info& lhs, const version_info& rhs) {
  return rhs < lhs;
}

bool operator<=(const version_info& lhs, const version_info& rhs) {
  return !(lhs > rhs);
}

bool operator>=(const version_info& lhs, const version_info& rhs) {
  return !(lhs < rhs);
}

std::ostream& operator<<(std::ostream& out, const version_info& out_version) {
  return out << out_version.major << '.' << out_version.minor << '.' << out_version.patch;
}

version_info version()
{
  return version_info(PROJECT_VERSION_MAJOR,
                      PROJECT_VERSION_MINOR,
                      PROJECT_VERSION_PATCH);
}
