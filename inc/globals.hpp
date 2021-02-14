/* TODO
 * Put component description here
 */

#ifndef GLOBALS_HPP
#define GLOBALS_HPP

// ========================================================================== //
// dependencies

// STL
#include <string>

// LIB

// own


// ========================================================================== //
// project version

#define PROJECT_NAME "Amber Waters"
#define VERSION_MAJOR 1
#define VERSION_MINOR 1

// ========================================================================== //
// XML convenience

pugi::xml_node loadXML(const std::string & filename, const std::string & content = "");

#endif
