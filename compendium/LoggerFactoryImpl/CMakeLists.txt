# sources and headers
set(_srcs
	src/LoggerFactoryImpl.cpp
	src/LoggerImpl.cpp
	src/FormatterLoggerImpl.cpp
	src/LogServiceImpl.cpp
  )

set(_hdrs
  src/Activator.hpp
  src/LoggerFactoryImpl.hpp
  src/LoggerImpl.hpp
  src/FormatterLoggerImpl.hpp
  src/LogServiceImpl.hpp
  )

set(_link_libraries )
if(UNIX)
  list(APPEND _link_libraries dl)
endif()
if(WIN32)
  list(APPEND _link_libraries shlwapi.lib)
endif()

if(CMAKE_THREAD_LIBS_INIT)
  list(APPEND _link_libraries ${CMAKE_THREAD_LIBS_INIT})
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/manifest.json.in
	       ${CMAKE_CURRENT_BINARY_DIR}/resources/manifest.json)

if(MINGW)
  # silence ignored attributes warnings
  add_compile_options(-Wno-attributes)
endif()

usMacroCreateBundle(LoggerFactoryImpl
  VERSION "1.0.0"
  DEPENDS Framework
  TARGET LoggerFactory
  SYMBOLIC_NAME logger_factory
  EMBED_RESOURCE_METHOD LINK
  PRIVATE_INCLUDE_DIRS src/util src/service src/bundle ../third_party
  LINK_LIBRARIES ${_link_libraries}
  PUBLIC_HEADERS ${_public_headers}
  PRIVATE_HEADERS ${_hdrs}
  SOURCES ${_srcs} src/Activator.cpp
  BINARY_RESOURCES manifest.json
  )

target_include_directories(LoggerFactory PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CppMicroServices_BINARY_DIR}/include
  ${CppMicroServices_SOURCE_DIR}/framework/include
  ${CppMicroServices_BINARY_DIR}/framework/include
  ${CppMicroServices_SOURCE_DIR}/compendium/LoggerFactory/include
  ${CppMicroServices_BINARY_DIR}/compendium/LoggerFactory/include
  ${CppMicroServices_SOURCE_DIR}/third_party/spdlog/include
  ${CppMicroServices_SOURCE_DIR}/third_party/googletest/googletest/include
  ${CppMicroServices_SOURCE_DIR}/third_party/googletest/googlemock/include
  )

if(APPLE)
  if(CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS "8.0.0")
	  target_compile_definitions(LoggerFactory PRIVATE SPDLOG_NO_TLS)
  endif()
endif()
