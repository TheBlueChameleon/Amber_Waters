// ========================================================================== //
// dependencies

// STL
#include <iostream>
#include <string>
  using namespace std::string_literals;
#include <cstring>

// LIB
#include "pugixml.hpp"

// own
#include "globals.hpp"

// ========================================================================== //
// local macro

#define THROWTEXT(msg) ("RUNTIME EXCEPTION IN "s + (__PRETTY_FUNCTION__) + "\n"s + msg)

// ========================================================================== //
// XML convenience

pugi::xml_document loadXML(const std::string & filename, const std::string & content) {
  /* Loads the document specified by <filename>
   * Performs project and version check
   * Returns XML handle on success
   * Throws std::runtime_error otherwise
   */
  
  pugi::xml_document doc;
  
  // ........................................................................ //
  // load and check XML validity
  
  pugi::xml_parse_result result = doc.load_file(filename.data());
  
  if (not result) {
    throw std::runtime_error(THROWTEXT(
      "    Could not load '"s + filename + "'.\n"
      "    Load result : " + result.description()
    ));
  }
  
  // ........................................................................ //
  // check whether this belongs to the project
  
  /* A project file is expected to have "project" as a root node.
   * project should have the attribute "name"
   * the value has to be the same as global PROJECT_NAME, as defined in
   * globals.hpp.
   */
  
  auto nodeProject = doc.child("project");
  
  if (not nodeProject) {
    throw std::runtime_error(THROWTEXT(
      "    Invalid file '"s + filename + "'.\n"
      "    Couldn't find project tag"
    ));
  }
  
  auto attribName = nodeProject.attribute("name");
  if (not attribName) {
    throw std::runtime_error(THROWTEXT(
      "    Invalid file '"s + filename + "'.\n"
      "    Couldn't find project name"
    ));
  }
  
  if ( std::strcmp(attribName.value(), PROJECT_NAME) ) {
    throw std::runtime_error(THROWTEXT(
      "    Invalid file '"s + filename + "'.\n"
      "    Not part of project '" + PROJECT_NAME + "'"
    ));
  }
  
  // ........................................................................ //
  // check version
  
  /* Version number is stored in node version, directly under the node project
   * It has two elements, major and minor.
   * They in turn each have an attribute "value" which holds an int.
   * 
   * Negative or empty values are not valid.
   * trailing non-numeric strings will be ignored. ("1text" evaluates to 1)
   * leading non-numeric strings are evaluated to zero. ("text1" evaluates to 0)
   * version number 0.0 is invalid.
   * 
   * Supported major/minor version is defined in globals.hpp as
   * VERSION_MAJOR, VERSION_MINOR
   */
  
  auto nodeVersion = nodeProject.child("version");
  if (not nodeVersion) {
    throw std::runtime_error(THROWTEXT(
      "    Invalid file '"s + filename + "'.\n"
      "    Couldn't find version tag"
    ));
  }
  
  auto nodeMajor = nodeVersion.child("major");
  if (not nodeMajor) {
    throw std::runtime_error(THROWTEXT(
      "    Invalid file '"s + filename + "'.\n"
      "    Couldn't find version major tag"
    ));
  }
  
  auto nodeMinor = nodeVersion.child("minor");
  if (not nodeMinor) {
    throw std::runtime_error(THROWTEXT(
      "    Invalid file '"s + filename + "'.\n"
      "    Couldn't find version minor tag"
    ));
  }
  
  auto major = nodeMajor.attribute("value").as_int(-1);
  auto minor = nodeMinor.attribute("value").as_int(-1);
  
  if (
    (major  < 0 || minor  < 0) ||
    (major == 0 && minor == 0)
  ) {
    throw std::runtime_error(THROWTEXT(
      "    Invalid file '"s + filename + "'.\n"
      "    Version number " + std::to_string(major) + "." + std::to_string(minor) + " is invalid."
    ));
  }
  
  
  if (major > VERSION_MAJOR) {
    throw std::runtime_error(THROWTEXT(
      "    Invalid file '"s + filename + "'.\n"
      "    Version number " + std::to_string(major) + "." + std::to_string(minor) + " is not supported.\n"
      "    This is version " + std::to_string(VERSION_MAJOR) + "." + std::to_string(VERSION_MINOR)
    ));
  } else if (major == VERSION_MAJOR) {
    if (minor > VERSION_MINOR) {
      throw std::runtime_error(THROWTEXT(
        "    Invalid file '"s + filename + "'.\n"
        "    Version number " + std::to_string(major) + "." + std::to_string(minor) + " is not supported.\n"
        "    This is version " + std::to_string(VERSION_MAJOR) + "." + std::to_string(VERSION_MINOR)
      ));
    }
  }
  
  std::cout << "version " << major << "." << minor << std::endl;
  
  return doc;
}
