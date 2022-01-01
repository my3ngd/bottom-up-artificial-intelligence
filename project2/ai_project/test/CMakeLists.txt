MESSAGE( TEST_CMAKELISTS_START )

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/e4717df71a4f45bf9f0ac88c6cd9846a0bc248dd.zip)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(AI_TESTS
  basic_test.cc
  # Add your test files here
  # foo/bar/your_test.cc
)

# make executable file "ai_test" using {AI_TEST: basic_test.cc}
add_executable(ai_test ${AI_TESTS})

target_link_libraries(
  ai_test
  ai
  gtest_main
  gmp
  gmpxx
)

include(GoogleTest)
gtest_discover_tests(ai_test)

MESSAGE( TEST_CMAKELISTS_END )
