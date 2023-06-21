cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Kalkulator_dla_elektronikow_MG")

add_executable (Kalkulator_dla_elektronikow_MG "Kalkulator_dla_elektronikow_MG.cpp" "Kalkulator_dla_elektronikow_MG.h" "Number.cpp" "Number.h" "Console.cpp" "Console.h")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Kalkulator_dla_elektronikow_MG PROPERTY CXX_STANDARD 20)
endif()

