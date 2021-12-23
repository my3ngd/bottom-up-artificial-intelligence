MESSAGE( LIBRARIES_CMAKELISTS_START )

# Sources
set(AI_SOURCE_DIR src)
set(AI_SOURCES
  ${AI_SOURCE_DIR}/decimal.cc
  # Add your sources here
  # ${AI_SOURCE_DIR}/foo/bar/your_source.cc
)

# Headers
set(AI_HEADER_DIR include)
set(AI_HEADERS
  ${AI_HEADER_DIR}/decimal.h
  # Add your headers here
  # ${AI_HEADER_DIR}/foo/bar/your_header.h
)

# create the static library "libai.a" from {headers} and {sources}
add_library(ai STATIC ${AI_HEADERS} ${AI_SOURCES})

target_include_directories(ai
  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/${AI_HEADER_DIR}"
)

MESSAGE( LIBRARIES_CMAKELISTS_END )
